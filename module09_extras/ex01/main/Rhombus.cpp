#include "Rhombus.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Rhombus::Rhombus()
{
}

Rhombus::Rhombus( const Rhombus & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Rhombus::~Rhombus()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Rhombus &				Rhombus::operator=( Rhombus const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Rhombus const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */