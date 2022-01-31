#ifndef WEAKPTR_HPP
# define WEAKPTR_HPP

# include <iostream>
# include <string>

class WeakPtr
{

	public:

		WeakPtr();
		WeakPtr( WeakPtr const & src );
		~WeakPtr();

		WeakPtr &		operator=( WeakPtr const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, WeakPtr const & i );

#endif /* ********************************************************* WEAKPTR_H */