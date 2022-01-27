#ifndef RHOMBUS_HPP
# define RHOMBUS_HPP

# include <iostream>
# include <string>

class Rhombus
{

	public:

		Rhombus();
		Rhombus( Rhombus const & src );
		~Rhombus();

		Rhombus &		operator=( Rhombus const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, Rhombus const & i );

#endif /* ********************************************************* RHOMBUS_H */