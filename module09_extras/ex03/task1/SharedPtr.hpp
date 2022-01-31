#ifndef SHAREDPTR_HPP
# define SHAREDPTR_HPP

# include <iostream>
# include <string>

class SharedPtr
{

	public:

		SharedPtr();
		SharedPtr( SharedPtr const & src );
		~SharedPtr();

		SharedPtr &		operator=( SharedPtr const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, SharedPtr const & i );

#endif /* ******************************************************* SHAREDPTR_H */