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

		//NULL/DEFAULT
		constexpr SharedPtr() noexcept : BasePtr<T>(), useCount(new long int(0)) {
			std::cout << "SharedPtr ctor.\n";
		};
		constexpr SharedPtr(std::nullptr_t) noexcept : SharedPtr() {}

		//POINTER
		explicit SharedPtr(T* data) : BasePtr<T>(data), useCount(new long int(1)) {
			std::cout << "SharedPtr ctor.\n";
		}

		//COPY (CTOR + ASSIGN)
		SharedPtr(SharedPtr<T> const & src) noexcept : BasePtr<T>(src) {
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
			this->data = rhs.get();
			if (rhs.useCount) (*rhs.useCount)++;
			return *this;
		}

		//MOVE (CTOR + ASSIGN)
		SharedPtr(SharedPtr<T> && src) noexcept : BasePtr<T>(std::move(src)), useCount(src.useCount) {
			src.reset();
		}
		SharedPtr<T> &		operator=(SharedPtr<T> && rhs) noexcept { //Move from other SharedPtr
			BasePtr<T>::operator=(std::move(rhs));
			rhs.reset();
			if (useCount != nullptr) {
				delete useCount;
			}
			useCount = new long int(rhs.use_count());
			return *this;
		}
		SharedPtr<T> &		operator=(UniquePtr<T> && rhs) noexcept { //Move from UniquePtr
			BasePtr<T>::operator=(std::move(rhs));
			rhs.reset();
			if (useCount != nullptr) {
				delete useCount;
			}
			useCount = new long int(1);
			return *this;
		}


		//DESTRUCTOR
		~SharedPtr() {
			BasePtr<T>::reset();
			delete useCount;
		}

		//Access operators
		T*			operator->() const { using BasePtr<T>::operator->(); }
		T&			operator*() const { using BasePtr<T>::operator*(); }

		//Access smart pointer state
		T*			get() const { using BasePtr<T>::get(); }
		explicit	operator bool() const { return this->data; }
		long int	use_count() const noexcept { return *useCount; }
		bool		unique() const noexcept { return ((*this) && *useCount == 1); }

		//Modify object state
		T*			release() noexcept = delete;
		void		swap(SharedPtr<T> & other) noexcept {
			BasePtr<T>::swap(other);
		}
		void		reset() {
			BasePtr<T>::reset();
			if (useCount != nullptr) {
				delete useCount;
			}
			useCount = new long int(0);
		}
		void		reset(T* newData) noexcept {
			BasePtr<T>::reset(newData);
			if (useCount != nullptr) {
				delete useCount;
			}
			useCount = new long int(1);
		}

	private:

		long int*	useCount;
};

}
#endif /* ******************************************************* SHAREDPTR_H */