#ifndef TRAPEZOID_HPP
# define TRAPEZOID_HPP

# include <iostream>
# include <string>

class Trapezoid
{

	public:

		Trapezoid();
		Trapezoid( Trapezoid const & src );
		~Trapezoid();

		Trapezoid &		operator=( Trapezoid const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, Trapezoid const & i );

#endif /* ******************************************************* TRAPEZOID_H */