#ifndef BASEPTR_HPP
# define BASEPTR_HPP

# include "moveSwap.hpp"
# include <iostream>
# include <string>
# include <type_traits>

namespace SmartPointer {

template<class T>
class BasePtr 
{

	public:

		//NULL
		constexpr BasePtr() noexcept : data(nullptr) {
			// std::cout << "BasePtr def ctor.\n";
		}
		constexpr BasePtr(std::nullptr_t) noexcept : BasePtr<T>() {
		}

		//POINTER
		explicit BasePtr(T* data) noexcept : data(data) {
			// std::cout << "BasePtr ptr ctor.\n";
		};

		//COPY
		BasePtr(BasePtr<T> const & src) noexcept : data(src.data) {
			// std::cout << "BasePtr copy ctor.\n";
		};

		//MOVE
		BasePtr(BasePtr<T> && u) noexcept : data(nullptr) {
			// std::cout << "BasePtr move ctor.\n";
			this->swap(u); //Swap the data of u with nullptr
		}

		//DESTRUCT
		~BasePtr() {
			// std::cout << "BasePtr dtor.\n";
			this->reset();
		};

		//Assignment
		BasePtr<T> &	operator=(BasePtr<T> const & rhs) = default;
		BasePtr<T> &	operator=(BasePtr<T> && rhs) noexcept { //move
			this->swap(rhs);
			return *this;
		}
		BasePtr<T> &	operator=(std::nullptr_t) noexcept {
			this->reset();
			return *this;
		}

		//Access operators
		T*			operator->() const { return data; }
		T&			operator*() const { return *data; }

		//Access smart pointer state
		T*			get() const { return data; }	//Get the stored pointer
		explicit	operator bool() const { return (data != nullptr); }

		//Modify object state
		T*			release() noexcept {
			T*	result = nullptr;
			SmartPointer::moveSwap(result, this->data); //release the pointer and set it to nullptr in the object
			return result;
		}
		void		swap(BasePtr<T> & other) noexcept {
			SmartPointer::moveSwap(this->data, other.data);
		}
		void		reset() {
			T*	tmp = release(); 	//release and set to nullptr
			if (tmp != nullptr) {	//delete depending if it's an array or not
				// std::cout << "Deleting stored object\n";
				if (std::is_array<T>::value)
					delete 	[] tmp;
				else
					delete tmp;
			}
		}
		void		reset(T* newData) noexcept {
			this->reset();
			data = newData;
		}

	protected:

		T*	data;
};

}
#endif /* ********************************************************* BASEPTR_H */