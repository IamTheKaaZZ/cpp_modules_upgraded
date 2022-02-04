#ifndef WEAKPTR_HPP
# define WEAKPTR_HPP

# include <iostream>
# include <string>
# include "SharedPtr.hpp"
# include "UniquePtr.hpp"
# include "BasePtr.hpp"

namespace SmartPointer {

using SmartPointer::SharedPtr;
using SmartPointer::RefCounter;

template<class T>
class WeakPtr
{
	public:

      	using element_type = typename std::remove_extent<T>::type;

		//-------------CONSTRUCTORS
		//NULL/DEFAULT
		constexpr WeakPtr() noexcept : data(nullptr),
			useCount(new RefCounter())
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
				useCount = src.useCount;
			}
		}
		WeakPtr(SharedPtr<T> const & src) noexcept : WeakPtr<T>()
		{
			// std::cout << "WeakPtr copy ctor.\n";
			if (!src.is_empty()) {
				data = src.get();
				useCount = src.getUsePtr();
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
			if (useCount->get() == 0) {
				delete useCount;
			}
		}

		//-------------OPERATOR=
		WeakPtr<T> &	operator=(WeakPtr<T> const & rhs) noexcept {
			std::cout << "Copy op weak\n";
			if (rhs.expired()) {
				this->reset();
				*this->useCount = 0;
			}
			else {
				this->data = rhs.get();
				this->useCount = rhs.useCount;
			}
			return *this;
		};
		WeakPtr<T> &	operator=(SharedPtr<T> const & rhs) noexcept {
			std::cout << "Copy op shared\n";
			if (rhs.is_empty()) {
				this->reset();
				*this->useCount = 0;
			}
			else {
				this->data = rhs.get();
				this->useCount = rhs.getUsePtr();
			}
			return *this;
		};
		WeakPtr<T> &		operator=(WeakPtr<T> && rhs) noexcept { //Move from other WeakPtr
			std::cout << "Move op shared\n";
			this->swap(rhs);
			return *this;
		}

		//Access smart pointer state
		T*						get() const { return data; }	//Get the stored pointer
		explicit				operator bool() const { return (data != nullptr); }
		long int				use_count() const noexcept { return useCount->get(); }
		RefCounter*				getUsePtr() const noexcept { return useCount; }
		bool					expired() const noexcept {
			std::cout << std::boolalpha << "is NULL?" << ((*this)? " NOT NULL\n" : " NULL\n");
			std::cout << std::boolalpha << "has 0 count?" << ((useCount->get() == 0)? " 0\n" : " NO\n");
			return (data == nullptr || useCount->get() == 0); 
		}
		SharedPtr<T>			lock() const noexcept {
			if (this->expired()) return SharedPtr<T>();
			return SharedPtr<T>(data);
		}

		//Modify object state
		void					reset() {
			T*	tmp = release(); 	//release and set to nullptr
			if (tmp != nullptr) {	//delete depending if it's an array or not
				// std::cout << "Deleting stored object\n";
				if (std::is_array<T>::value)
					delete 	[] tmp;
				else
					delete tmp;
			}
		}
		void					reset(T* newData) noexcept {
			this->reset();
			data = newData;
		}

	private:

		T*				data;
		RefCounter*		useCount;
		T*			release() noexcept {
			T*	result = nullptr;
			SmartPointer::moveSwap(result, this->data); //release the pointer and set it to nullptr in the object
			return result;
		}
};

//-------------Non-member swap

template<class T>
inline void	swap(WeakPtr<T> & a, WeakPtr<T> & b) noexcept {
	a.swap(b);
}

}
#endif /* ********************************************************* WEAKPTR_H */