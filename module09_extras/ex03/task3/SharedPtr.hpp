#ifndef SHAREDPTR_HPP
# define SHAREDPTR_HPP

# include <cstddef>
# include <iostream>
# include <string>
# include "UniquePtr.hpp"
# include "ShareCount.hpp"

namespace SmartPointer {

using std::bad_weak_ptr;
using SmartPointer::WeakPtr;

template<class T>
class SharedPtr
{
	public:

      	using element_type = typename std::remove_extent<T>::type;

		//-------------CONSTRUCTORS
		//NULL/DEFAULT
		constexpr SharedPtr() noexcept : data(nullptr),
			refs(new ShareCount())
		{
			// std::cout << "SharedPtr def ctor.\n";
		};
		constexpr SharedPtr(std::nullptr_t) noexcept : SharedPtr() {}

		//POINTER
		explicit SharedPtr(T* data) : data(data),
			refs(new ShareCount(1))
		{
			// std::cout << "SharedPtr ptr ctor.\n";
		}

		//COPY
		SharedPtr(SharedPtr<T> const & src) noexcept : SharedPtr<T>(src.get())
		{
			// std::cout << "SharedPtr copy ctor.\n";
			if (!src.is_empty()) {
				refs = src.refs;
				(*refs)++;
			}
		}
		SharedPtr(WeakPtr<T> const & src) : SharedPtr<T>(src.get())
		{
			// std::cout << "SharedPtr copy ctor.\n";
			if (src.expired())
				throw std::bad_weak_ptr();
			refs = src.getUsePtr();
			(*refs)++;
		}
		//MOVE
		SharedPtr(SharedPtr<T> && src) noexcept : SharedPtr<T>()
		{
			// std::cout << "SharedPtr move ctor.\n";
			this->swap(src);
		}
		SharedPtr(UniquePtr<T> && src) noexcept : data(nullptr),
			refs(new ShareCount(1))
		{
			// std::cout << "SharedPtr UniquePtr move ctor.\n";
			this->data = src.release();
		}
		SharedPtr(BasePtr<T> && src) noexcept : data(nullptr),
			refs(new ShareCount(1))
		{
			// std::cout << "SharedPtr UniquePtr move ctor.\n";
			this->data = src.release();
		}

		//DESTRUCTOR
		~SharedPtr() {
			// std::cout << "SharedPtr dtor.\n";
			destructSideEffects(true);
		}

		//-------------OPERATOR=
		SharedPtr<T> &	operator=(SharedPtr<T> const & rhs) noexcept {
			// std::cout << "Copy op shared\n";
			destructSideEffects(false);
			this->data = rhs.get();
			this->refs = rhs.refs;
			(*rhs.refs)++;
			return *this;
		};
		//Assignment - nullptr
		SharedPtr<T> &	operator=(std::nullptr_t) noexcept {
			// std::cout << "null assign op shared\n";
			destructSideEffects(false);
			this->release();
			refs = new ShareCount();
			return *this;
		}
		//Move assignment
		SharedPtr<T> &		operator=(SharedPtr<T> && rhs) noexcept { //Move from other SharedPtr
			// std::cout << "Move op shared\n";
			destructSideEffects(false);
			this->swap(rhs);
			return *this;
		}
		SharedPtr<T> &		operator=(UniquePtr<T> && rhs) noexcept { //Move from UniquePtr
			// std::cout << "Move op unique\n";
			// std::cout << "Swapping " << *data << " and " << *rhs << '\n';
			moveSwap(*data, *rhs);
			// std::cout << "Swapping " << *data << " and " << *rhs << '\n';
			destructSideEffects(false); //Bruh this decreases the value of rhs by 1 wut
			// std::cout << "Swapping " << *data << " and " << *rhs << '\n';
			(*refs) = 1;
			return *this;
		}

		//-------------MEMBER FUNCTIONS
		//Access operators
		T*			operator->() const { return data; }
		T&			operator*() const { return *data; }

		//Access smart pointer state
		T* const &	get() const { return data; }	//Get the stored pointer
		explicit	operator bool() const { return (data != nullptr); }
		long int	use_count() const noexcept { return refs->getCount(); }
		ShareCount*	getUsePtr() const noexcept { return refs; }
		bool		unique() const noexcept { return ((*this) && refs->getCount() == 1); }
		bool		is_empty() const noexcept { return (!(*this)); }

		//Modify object state
		T*			release() noexcept {
			T*	result = nullptr;
			SmartPointer::moveSwap(result, this->data); //release the pointer and set it to nullptr in the object
			// std::cout << "result = " << result << ", data = " << this->data << std::endl;
			return result;
		}
		void					swap(SharedPtr<T> & other) noexcept {
			SmartPointer::moveSwap(this->data, other.data);
			SmartPointer::moveSwap(this->refs, other.refs);
		}
		void					reset() {
			if (refs->getCount() > 0)
				refs->getCount() = 0;
			T*	tmp = release(); 	//release and set to nullptr
			if (tmp != nullptr) {	//delete depending if it's an array or not
				// std::cout << "Deleting stored object\n";
				if (std::is_array<T>::value)
					delete 	[] tmp;
				else
					delete tmp;
				tmp = nullptr;
			}
		}
		void					reset(T* newData) noexcept {
			this->reset();
			data = newData;
			refs++;
		}

	protected:

		T*				data;
		ShareCount*		refs;
		void			destructSideEffects(bool const & dtorCalled) {
			if (refs->getCount() > 1)
				(*refs)--;
			else if (refs->getCount() == 1) {
				reset();
				if (dtorCalled)
					delete refs;
			}
			else if (refs->getCount() == 0) {
				if (dtorCalled)
					delete refs;
			}
		}
};

//-------------<< overload

template<class T>
std::ostream &		operator<<(std::ostream & o, SharedPtr<T> const & s) {
	o << s.get();
	return o;
}

//-------------Non-member swap

template<class T>
inline void	swap(SharedPtr<T> & a, SharedPtr<T> & b) noexcept {
	a.swap(b);
}

//-------------make_shared

//Typedef for conditional return type
template <bool B, class T = void>
using enable_if_t = typename std::enable_if<B,T>::type;

//Typedef for the boolean that checks if T is an array
template< class T >
inline constexpr bool is_array_v = std::is_array<T>::value;

//It's not an array
template <class T, class ...Args>
enable_if_t<!is_array_v<T>, SharedPtr<T>>
		make_shared(Args&& ...args) {
   return SharedPtr<T>(new T(std::forward<Args>(args)...));
};

//It's an array
template <class T>
enable_if_t<is_array_v<T>, SharedPtr<T>>
		make_shared(int size) {
   using type = std::remove_extent<T>;
   return SharedPtr<T>(new type[size]);
};

//-------------Relational operators

template<class T, class U>
inline bool	operator==(SharedPtr<T> const & lhs, SharedPtr<U> const & rhs) noexcept {
	return (lhs.get() == rhs.get());
}
template<class T>
inline bool	operator==(SharedPtr<T> const & lhs, std::nullptr_t) noexcept {
	return (!lhs);
}
template<class T>
inline bool	operator==(std::nullptr_t, SharedPtr<T> const & rhs) noexcept {
	return (!rhs);
}

template<class T, class U>
inline bool	operator!=(SharedPtr<T> const & lhs, SharedPtr<U> const & rhs) noexcept {
	return (lhs.get() != rhs.get());
}
template<class T>
inline bool	operator!=(SharedPtr<T> const & lhs, std::nullptr_t) noexcept {
	return ((bool)lhs);
}
template<class T>
inline bool	operator!=(std::nullptr_t, SharedPtr<T> const & rhs) noexcept {
	return ((bool)rhs);
}

//We implement operator< once fully and then use the implementation for the rest

template<class T, class U>
inline bool	operator<(SharedPtr<T> const & lhs, SharedPtr<U> const & rhs) noexcept {
    using T_elt = typename SharedPtr<T>::element_type;
    using U_elt = typename SharedPtr<U>::element_type;
    using V = typename std::common_type<T_elt*, U_elt*>::type;
    return std::less<V>()(rhs.get(), lhs.get());
}
template<class T>
inline bool	operator<(SharedPtr<T> const & lhs, std::nullptr_t) noexcept {
    using lhs_elt = typename SharedPtr<T>::T;
    return std::less<lhs_elt*>()(lhs.get(), nullptr);
}
template<class T>
inline bool	operator<(std::nullptr_t, SharedPtr<T> const & rhs) noexcept {
    using rhs_elt = typename SharedPtr<T>::T;
    return std::less<rhs_elt*>()(nullptr, rhs.get());
}

template<class T, class U>
bool	operator<=(SharedPtr<T> const & lhs, SharedPtr<U> const & rhs) noexcept {
	return !(rhs < lhs);
}
template<class T, class U>
bool	operator<=(SharedPtr<T> const & lhs, std::nullptr_t) noexcept {
	return !(nullptr < lhs);
}
template<class T, class U>
bool	operator<=(std::nullptr_t, SharedPtr<U> const & rhs) noexcept {
	return !(rhs < nullptr);
}

template<class T, class U>
bool	operator>(SharedPtr<T> const & lhs, SharedPtr<U> const & rhs) noexcept {
	return (rhs < lhs);
}
template<class T, class U>
bool	operator>(SharedPtr<T> const & lhs, std::nullptr_t) noexcept {
	return (nullptr < lhs);
}
template<class T, class U>
bool	operator>(std::nullptr_t, SharedPtr<U> const & rhs) noexcept {
	return (rhs < nullptr);
}

template<class T, class U>
bool	operator>=(SharedPtr<T> const & lhs, SharedPtr<U> const & rhs) noexcept {
	return !(lhs < rhs);
}
template<class T, class U>
bool	operator>=(SharedPtr<T> const & lhs, std::nullptr_t) noexcept {
	return !(lhs < nullptr);
}
template<class T, class U>
bool	operator>=(std::nullptr_t, SharedPtr<U> const & rhs) noexcept {
	return !(nullptr < rhs);
}

}
#endif /* ******************************************************* SHAREDPTR_H */