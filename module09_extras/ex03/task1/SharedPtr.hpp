#ifndef SHAREDPTR_HPP
# define SHAREDPTR_HPP

# include <cstddef>
# include <iostream>
# include <string>
# include "../task0/UniquePtr.hpp"

namespace SmartPointer {

template<class T>
class SharedPtr : public BasePtr<T>
{

	public:

      	using element_type = typename SharedPtr<T>::type;

		//NULL/DEFAULT
		constexpr SharedPtr() noexcept : BasePtr<T>(),
			useCount(new long int(0)),
			unmanagedPtr(nullptr)
		{
			std::cout << "SharedPtr ctor.\n";
		};
		constexpr SharedPtr(std::nullptr_t) noexcept : SharedPtr() {}

		//POINTER
		explicit SharedPtr(T* data) : BasePtr<T>(data),
			useCount(new long int(1)),
			unmanagedPtr(nullptr)
		{
			std::cout << "SharedPtr ctor.\n";
		}

		//COPY (CTOR + ASSIGN)
		SharedPtr(SharedPtr<T> const & src) noexcept : BasePtr<T>(src),
			unmanagedPtr(src.unmanagedPtr)
		{
			std::cout << "SharedPtr copy ctor.\n";
			if (this->data != nullptr) {
				if (src.useCount)
					(*src.useCount)++;
				useCount = new long int(1);
			}
			else useCount = new long int(0);
		}
		//Copy from WEAK => see after WeakPtr is implemented
		/*
		explicit SharedPtr(WeakPtr<T> const & src) {
			== copy ctor but throw bad_weak_ptr exception when WeakPtr has expired.
		}
		*/
		SharedPtr<T> &		operator=(SharedPtr<T> const & rhs ) noexcept {
			this->data = rhs.data;
			this->unmanagedPtr = rhs.unmanagedPtr;
			if (rhs.useCount) (*rhs.useCount)++;
			return *this;
		}

		//MOVE (CTOR + ASSIGN)
		SharedPtr(SharedPtr<T> && src) noexcept : BasePtr<T>(std::move(src)),
			useCount(1),
			unmanagedPtr(std::move(src.unmanagedPtr))
		{
			std::cout << "SharedPtr move ctor.\n";
			src.reset();
		}
		SharedPtr<T> &		operator=(SharedPtr<T> && rhs) noexcept { //Move from other SharedPtr
			BasePtr<T>::operator=(std::move(rhs));
			this->unmanagedPtr = std::move(rhs.unmanagedPtr);
			rhs.reset();
			if (useCount != nullptr) {
				delete useCount;
			}
			useCount = new long int(rhs.use_count());
			return *this;
		}
		SharedPtr<T> &		operator=(UniquePtr<T> && rhs) noexcept { //Move from UniquePtr
			BasePtr<T>::operator=(std::move(rhs));
			this->unmanagedPtr = std::move(rhs.unmanagedPtr);
			rhs.reset();
			if (useCount != nullptr) {
				delete useCount;
			}
			useCount = new long int(1);
			return *this;
		}

		//ALIASING CONSTRUCTOR (Move + extra unmanaged ptr)
		SharedPtr(SharedPtr && src, element_type* ptr) : SharedPtr<T>(std::move(src)),
			useCount(2),
			unmanagedPtr(ptr)
		{
			std::cout << "SharedPtr Alias ctor.\n"; //Only has an extra effect on get() AND use_count
			//The object shares OWNERSHIP with src BUT points to ptr
		}

		//DESTRUCTOR
		~SharedPtr() {
			std::cout << "SharedPtr dtor.\n";
			switch (useCount) {
				case 0:
					delete useCount;
					break;
				case 1:
					BasePtr<T>::reset();
					delete useCount;
					break;
				default:
					(*useCount)--;
					break;
			}
		}

		//Access operators
		T*			get() const override { //Overload of the base class because of alias ctor
			return (unmanagedPtr)? unmanagedPtr : this->data; 
		}

		//Access smart pointer state
		long int	use_count() const noexcept { return *useCount; }
		bool		unique() const noexcept { return ((*this) && *useCount == 1); }

		//Modify object state
		T*			release() noexcept = delete;
		void		swap(SharedPtr<T> & other) noexcept {
			BasePtr<T>::swap(other);
		}
		void		reset() {
			BasePtr<T>::reset();
			*useCount = 0;
		}
		void		reset(T* newData) noexcept {
			BasePtr<T>::reset(newData);
			*useCount = 1;
		}

	private:

		long int*		useCount;
		element_type*	unmanagedPtr;
};

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
    using lhs_elt = typename SharedPtr<T>::element_type;
    using rhs_elt = typename SharedPtr<U>::element_type;
    using V = typename std::common_type<lhs_elt*, rhs_elt*>::type;
    return std::less<V>()(lhs.get(), rhs.get());
}
template<class T>
inline bool	operator<(SharedPtr<T> const & lhs, std::nullptr_t) noexcept {
    using lhs_elt = typename SharedPtr<T>::element_type;
    return std::less<lhs_elt*>()(lhs.get(), nullptr);
}
template<class T>
inline bool	operator<(std::nullptr_t, SharedPtr<T> const & rhs) noexcept {
    using rhs_elt = typename SharedPtr<T>::element_type;
    return std::less<rhs_elt*>()(nullptr, rhs.get());
}

template<class T, class U>
bool	operator<=(SharedPtr<T> const & lhs, SharedPtr<U> const & rhs) noexcept {
	return !(rhs.get() < lhs.get());
}
template<class T, class U>
bool	operator<=(SharedPtr<T> const & lhs, std::nullptr_t) noexcept {
	return !(nullptr < lhs.get());
}
template<class T, class U>
bool	operator<=(std::nullptr_t, SharedPtr<U> const & rhs) noexcept {
	return !(rhs.get() < nullptr);
}

template<class T, class U>
bool	operator>(SharedPtr<T> const & lhs, SharedPtr<U> const & rhs) noexcept {
	return (rhs.get() < lhs.get());
}
template<class T, class U>
bool	operator>(SharedPtr<T> const & lhs, std::nullptr_t) noexcept {
	return (nullptr < lhs.get());
}
template<class T, class U>
bool	operator>(std::nullptr_t, SharedPtr<U> const & rhs) noexcept {
	return (rhs.get() < nullptr);
}

template<class T, class U>
bool	operator>=(SharedPtr<T> const & lhs, SharedPtr<U> const & rhs) noexcept {
	return !(lhs.get() < rhs.get());
}
template<class T, class U>
bool	operator>=(SharedPtr<T> const & lhs, std::nullptr_t) noexcept {
	return !(lhs.get() < nullptr);
}
template<class T, class U>
bool	operator>=(std::nullptr_t, SharedPtr<U> const & rhs) noexcept {
	return !(nullptr < rhs.get());
}

}
#endif /* ******************************************************* SHAREDPTR_H */