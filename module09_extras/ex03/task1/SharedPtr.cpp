#include "SharedPtr.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

SharedPtr::SharedPtr()
{
}

SharedPtr::SharedPtr( const SharedPtr & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

SharedPtr::~SharedPtr()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

SharedPtr &				SharedPtr::operator=( SharedPtr const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, SharedPtr const & i )
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