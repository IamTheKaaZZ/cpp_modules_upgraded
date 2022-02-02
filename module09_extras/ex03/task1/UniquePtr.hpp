#ifndef UNIQUEPTR_HPP
# define UNIQUEPTR_HPP

# include <cstddef>
# include <iostream>
# include <string>
# include "moveSwap.hpp"
# include "BasePtr.hpp"

namespace SmartPointer {


template<class T>
class UniquePtr : public BasePtr<T>
{

	public:

		//NULL
		constexpr UniquePtr() noexcept : BasePtr<T>() {
			std::cout << "UniquePtr ctor.\n";
		}
		constexpr UniquePtr(std::nullptr_t) noexcept : UniquePtr() {}

		//POINTER
		explicit UniquePtr(T* data) noexcept : BasePtr<T>(data) {
			std::cout << "UniquePtr ctor.\n";
		};

		//MOVE
		UniquePtr(UniquePtr<T> && u) noexcept : BasePtr<T>(std::move(u)) {
			std::cout << "UniquePtr move ctor.\n";
		}

		//DESTRUCT
		~UniquePtr() {
			std::cout << "UniquePtr dtor.\n";
			BasePtr<T>::reset();
		};

		//ASSIGNMENT
		UniquePtr<T> &	operator=(UniquePtr<T> && rhs) noexcept {
			BasePtr<T>::operator=(std::move(rhs));
			return *this;
		}
		UniquePtr<T> &	operator=(std::nullptr_t) noexcept {
			this->reset();
			return *this;
		}

		//No Copying allowed for unique_ptrs
		UniquePtr(UniquePtr<T> const & src ) = delete;
		UniquePtr &		operator=( UniquePtr<T> const & rhs ) = delete;

		//--------From BasePtr---------//
		//Access operators
		// T*			operator->() const { return data; }
		// T			operator*() const { return *data; }

		//Access smart pointer state
		// T*			get() const { return data; }
		// explicit	operator bool() const { return data; }

		//Modify object state
		// T*			release() noexcept {
		// 	T*	result = nullptr;
		// 	moveSwap(result, this->data);
		// 	return result;
		// }
		// void		swap(UniquePtr<T> & other) noexcept {
		// 	moveSwap(this->data, other.data);
		// }
		// void		reset() {
		// 	T*	tmp = release();
		// 	delete tmp;
		// }
		// void		reset(type* newData) {
		// 	this->reset();
		// 	data = newData;
		// }

};

//Unigque_ptr for array elements
template<typename T>
class UniquePtr<T[]> : public BasePtr<T[]>
{

	public:

		//NULL
		constexpr UniquePtr() noexcept : BasePtr<T[]>() {
			std::cout << "UniquePtr ctor.\n";
		}
		constexpr UniquePtr(std::nullptr_t) noexcept : BasePtr<T[]>(nullptr) {}

		//POINTER
		explicit UniquePtr(T* data) noexcept : BasePtr<T[]>(data) {
			std::cout << "UniquePtr ctor.\n";
		};

		//MOVE
		UniquePtr(UniquePtr<T[]> && u) noexcept : BasePtr<T[]>(std::move(u)) {
			std::cout << "UniquePtr move ctor.\n";
		}

		//DESTRUCT
		~UniquePtr() {
			std::cout << "UniquePtr dtor.\n";
			BasePtr<T[]>::reset();
		};

		//ASSIGNMENT
		UniquePtr<T[]> &	operator=(UniquePtr<T[]> && rhs) noexcept {
			BasePtr<T>::operator=(std::move(rhs));
			return *this;
		}
		UniquePtr<T[]> &	operator=(std::nullptr_t) noexcept {
			this->reset();
			return *this;
		}

		//No Copying allowed for unique_ptrs
		UniquePtr(UniquePtr<T[]> const & src ) = delete;
		UniquePtr &		operator=( UniquePtr<T[]> const & rhs ) = delete;

		//Access operators => Array access
		T&			operator[](int pos) const { return BasePtr<T[]>::data[pos]; }

};

//Typedef for conditional return type
template <bool B, class T = void>
using enable_if_t = typename std::enable_if<B,T>::type;

//Typedef for the boolean that checks if T is an array
template< class T >
inline constexpr bool is_array_v = std::is_array<T>::value;

//It's not an array
template <class T, class ...Args>
enable_if_t<!is_array_v<T>, UniquePtr<T>>
		make_unique(Args&& ...args) {
   return UniquePtr<T>(new T(std::forward<Args>(args)...));
};

//It's an array
template <class T>
enable_if_t<is_array_v<T>, UniquePtr<T>>
		make_unique(int size) {
   using type = std::remove_extent<T>;
   return UniquePtr<T>(new type[size]);
};

}
#endif /* ******************************************************* UNIQUEPTR_H */