#include "Kite.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Kite::Kite()
{
}

Kite::Kite( const Kite & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Kite::~Kite()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Kite &				Kite::operator=( Kite const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Kite const & i )
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