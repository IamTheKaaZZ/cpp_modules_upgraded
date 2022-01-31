#ifndef UNIQUEPTR_HPP
# define UNIQUEPTR_HPP

# include <cstddef>
# include <iostream>
# include <string>
# include "moveSwap.hpp"
# include "BasePtr.hpp"

template<class T>
class UniquePtr : public BasePtr<T>
{

		using type = std::remove_extent<T>;

	public:

		//NULL
		constexpr UniquePtr() noexcept : data(nullptr) {
			std::cout << "UniquePtr ctor.\n";
		}
		constexpr UniquePtr(std::nullptr_t) noexcept : UniquePtr() {}

		//POINTER
		explicit UniquePtr(T* data) noexcept : data(data) {
			std::cout << "UniquePtr ctor.\n";
		};

		//MOVE
		UniquePtr(UniquePtr<T> && u) noexcept : data(nullptr) {
			std::cout << "UniquePtr move ctor.\n";
			this->swap(u);
		}

		//DESTRUCT
		~UniquePtr() {
			std::cout << "UniquePtr dtor.\n";
			if (data != nullptr)
				delete data;
		};

		//Assignment
		UniquePtr<T> &	operator=(UniquePtr<T> && rhs) noexcept {
			if (this != rhs) {
				this->swap(rhs);
			}
			return *this;
		}
		UniquePtr<T> &	operator=(std::nullptr_t) noexcept {
			this->reset();
			return *this;
		}

		//Access operators
		T*			operator->() const { return data; }
		T			operator*() const { return *data; }

		//Access smart pointer state
		T*			get() const { return data; }
		explicit	operator bool() const { return data; }

		//Modify object state
		T*			release() noexcept {
			T*	result = nullptr;
			moveSwap(result, this->data);
			return result;
		}
		void		swap(UniquePtr<T> & other) noexcept {
			moveSwap(this->data, other.data);
		}
		void		reset() {
			T*	tmp = release();
			delete tmp;
		}
		void		reset(type* newData) {
			this->reset();
			data = newData;
		}

		//No Copying allowed
		UniquePtr(UniquePtr const & src ) = delete;
		UniquePtr &		operator=( UniquePtr<T> const & rhs ) = delete;

	protected:

		T*	data;
};

#endif /* ******************************************************* UNIQUEPTR_H */