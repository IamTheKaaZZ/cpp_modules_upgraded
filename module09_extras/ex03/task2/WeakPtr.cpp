#include "WeakPtr.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WeakPtr::WeakPtr()
{
}

WeakPtr::WeakPtr( const WeakPtr & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WeakPtr::~WeakPtr()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WeakPtr &				WeakPtr::operator=( WeakPtr const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WeakPtr const & i )
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