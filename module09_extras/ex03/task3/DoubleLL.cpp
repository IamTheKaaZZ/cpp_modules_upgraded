#include "DoubleLL.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DoubleLL::DoubleLL()
{
}

DoubleLL::DoubleLL( const DoubleLL & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DoubleLL::~DoubleLL()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DoubleLL &				DoubleLL::operator=( DoubleLL const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, DoubleLL const & i )
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