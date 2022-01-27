#include "Rectangle.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Rectangle::Rectangle()
{
}

Rectangle::Rectangle( const Rectangle & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Rectangle::~Rectangle()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Rectangle &				Rectangle::operator=( Rectangle const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Rectangle const & i )
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