#include "Trapezoid.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Trapezoid::Trapezoid()
{
}

Trapezoid::Trapezoid( const Trapezoid & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Trapezoid::~Trapezoid()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Trapezoid &				Trapezoid::operator=( Trapezoid const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Trapezoid const & i )
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