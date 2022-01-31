#ifndef UNIQUEPTR_HPP
# define UNIQUEPTR_HPP

# include <iostream>
# include <string>

template<class T>
class UniquePtr
{

	public:

		explicit UniquePtr(T* data) : data(data) {
			std::cout << "UniquePtr ctor.\n";
		};
		UniquePtr(UniquePtr<T> && u) {
			std::cout << "UniquePtr move ctor.\n";

		}
		~UniquePtr() {
			std::cout << "UniquePtr dtor.\n";
			delete data;
		};
		void	swap() {

		}
		//No Copying allowed
		UniquePtr(UniquePtr const & src ) = delete;
		UniquePtr &		operator=( UniquePtr<T> const & rhs ) = delete;

	private:

		T*	data;
};

#endif /* ******************************************************* UNIQUEPTR_H */