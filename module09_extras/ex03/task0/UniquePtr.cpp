#include "UniquePtr.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

UniquePtr::UniquePtr()
{
}

UniquePtr::UniquePtr( const UniquePtr & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

UniquePtr::~UniquePtr()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

UniquePtr &				UniquePtr::operator=( UniquePtr const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, UniquePtr const & i )
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