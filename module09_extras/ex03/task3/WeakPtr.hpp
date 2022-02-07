#ifndef WEAKPTR_HPP
# define WEAKPTR_HPP

# include <iostream>
# include <string>
# include "SharedPtr.hpp"
# include "UniquePtr.hpp"
# include "BasePtr.hpp"
# include "ShareCount.hpp"

namespace SmartPointer {

using SmartPointer::SharedPtr;

template<class T>
class WeakPtr
{
	public:

      	using element_type = typename std::remove_extent<T>::type;

		//-------------CONSTRUCTORS
		//NULL/DEFAULT
		constexpr WeakPtr() noexcept : data(nullptr),
			refs(new ShareCount())
		{
			// std::cout << "WeakPtr def ctor.\n";
		};
		constexpr WeakPtr(std::nullptr_t) noexcept : WeakPtr() {}

		//COPY
		WeakPtr(WeakPtr<T> const & src) noexcept : WeakPtr<T>()
		{
			// std::cout << "WeakPtr copy ctor.\n";
			if (!src.expired()) {
				data = src.data;
				refs = src.refs;
			}
		}
		WeakPtr(SharedPtr<T> const & src) noexcept : WeakPtr<T>()
		{
			// std::cout << "WeakPtr copy ctor.\n";
			if (!src.is_empty()) {
				data = &src.get();
				refs = src.getUsePtr();
				safetyCopy = new T(*src);
				refs->getWeak()++;
				std::cout << *refs;
			}
		}
		//MOVE
		WeakPtr(WeakPtr<T> && src) noexcept : WeakPtr<T>()
		{
			// std::cout << "WeakPtr move ctor.\n";
			this->swap(src);
		}

		//DESTRUCTOR
		~WeakPtr() {
			// std::cout << "WeakPtr dtor.\n";
			if (refs->getWeak() > 0)
				refs->getWeak()--;
			if (refs->getCount() == 0) {
				delete refs;
			}
		}

		//-------------OPERATOR=
		WeakPtr<T> &	operator=(WeakPtr<T> const & rhs) noexcept {
			// std::cout << "Copy op weak\n";
			WeakPtr<T> tmp(rhs);
			tmp.swap(*this);
			return *this;
		};
		WeakPtr<T> &	operator=(SharedPtr<T> const & rhs) noexcept {
			// std::cout << "Copy op shared\n";
			WeakPtr<T> tmp(rhs);
			tmp.swap(*this);
			return *this;
		};
		WeakPtr<T> &		operator=(WeakPtr<T> && rhs) noexcept { //Move from other WeakPtr
			// std::cout << "Move op shared\n";
			WeakPtr<T> tmp(std::move(rhs));
			tmp.swap(*this);
			return *this;
		}

		//Access smart pointer state
		T*						get() { return *data; }	//Get the stored pointer
		explicit				operator bool() const { return (data != nullptr && *data != nullptr); }
		long int				use_count() const noexcept { return refs->getCount(); }
		ShareCount*				getUsePtr() const noexcept { return refs; }
		bool					expired() const noexcept {
			return (refs->noRefs() && data != nullptr && *data == nullptr); 
		}
		SharedPtr<T>			lock() const noexcept {
			if (this->expired()) return SharedPtr<T>();
			// std::cout << "Not expired, creating a new shared ptr\n";
			SharedPtr<T>	result(safetyCopy);
			this->refs->getCount()++;
			this->refs->getWeak()++;
			result.getUsePtr()->getCount() = refs->getCount();
			result.getUsePtr()->getWeak() = refs->getWeak();
			return result;
		}
		void					swap(WeakPtr<T> & other) noexcept {
			SmartPointer::moveSwap(this->data, other.data);
			SmartPointer::moveSwap(this->refs, other.refs);
			SmartPointer::moveSwap(this->safetyCopy, other.safetyCopy);
		}
		void					swap(SharedPtr<T> & other) noexcept {
			SmartPointer::moveSwap(this->data, other.data);
			SmartPointer::moveSwap(this->refs, other.refs);
		}

		//Modify object state
		void					reset() {
			T*	tmp = release(); 	//release and set to nullptr
			deleteThis(tmp);
		}
		void					reset(T* newData) noexcept {
			this->reset();
			data = newData;
		}

	private:

		T* const *		data;
		T*				safetyCopy = nullptr;
		ShareCount*		refs;
		T*				release() noexcept {
			T*	result = nullptr;
			SmartPointer::moveSwap(result, this->data); //release the pointer and set it to nullptr in the object
			return result;
		}
		void			deleteThis(T* tmp) {
			if (tmp != nullptr) {	//delete depending if it's an array or not
				// std::cout << "Deleting stored object\n";
				if (std::is_array<T>::value)
					delete 	[] tmp;
				else
					delete tmp;
			}
		}
};

//-------------Non-member swap

template<class T>
inline void	swap(WeakPtr<T> & a, WeakPtr<T> & b) noexcept {
	a.swap(b);
}

}
#endif /* ********************************************************* WEAKPTR_H */