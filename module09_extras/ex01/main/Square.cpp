#include "Square.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Square::Square()
{
}

Square::Square( const Square & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Square::~Square()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Square &				Square::operator=( Square const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Square const & i )
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