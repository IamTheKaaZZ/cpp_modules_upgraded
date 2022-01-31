#ifndef BASEPTR_HPP
# define BASEPTR_HPP

# include <iostream>
# include <string>
# include <type_traits>

template<class T>
class BasePtr 
{

		using type = std::remove_extent<T>;

	public:

		//NULL
		constexpr BasePtr() noexcept : data(nullptr) {
			std::cout << "BasePtr ctor.\n";
		}
		constexpr BasePtr(std::nullptr_t) noexcept : BasePtr() {
		}

		//POINTER
		explicit BasePtr(T* data) noexcept : data(data) {
			std::cout << "BasePtr ctor.\n";
		};

		//MOVE
		BasePtr(BasePtr<T> && u) noexcept : data(nullptr) {
			std::cout << "BasePtr move ctor.\n";
			this->swap(u); //Swap the data of u with nullptr
		}

		//DESTRUCT
		~BasePtr() {
			std::cout << "BasePtr dtor.\n";
			if (data != nullptr)
				delete data;
		};

		//Assignment
		BasePtr<T> &	operator=(BasePtr<T> && rhs) noexcept {
			if (this != rhs) {
				this->swap(rhs);
			}
			return *this;
		}
		BasePtr<T> &	operator=(std::nullptr_t) noexcept {
			this->reset();
			return *this;
		}

		//Access operators
		type*			operator->() const { return data; }
		type			operator*() const { return *data; }

		//Access smart pointer state
		type*			get() const { return data; }
		explicit	operator bool() const { return data; }

		//Modify object state
		type*			release() noexcept {
			type*	result = nullptr;
			moveSwap(result, this->data); //release the pointer and set it to nullptr in the object
			return result;
		}
		void		swap(BasePtr<T> & other) noexcept {
			moveSwap(this->data, other.data);
		}
		void		reset() {
			type*	tmp = release(); //release and set to nullptr
			if (tmp != nullptr) {	//delete depending if it's an array or not
				if (std::is_array<type>::value)
					delete 	[] tmp;
				else
					delete tmp;
			}
		}
		void		reset(type* newData) noexcept {
			this->reset();
			data = newData;
		}

	protected:

		T*	data;
};
#endif /* ********************************************************* BASEPTR_H */