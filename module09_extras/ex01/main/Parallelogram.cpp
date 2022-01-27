#include "Parallelogram.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Parallelogram::Parallelogram()
{
}

Parallelogram::Parallelogram( const Parallelogram & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Parallelogram::~Parallelogram()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Parallelogram &				Parallelogram::operator=( Parallelogram const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Parallelogram const & i )
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