#include "Polygons.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Polygons::Polygons(std::string const & name) : _nameOfPoly(name)
{
    std::cout << "Polygons Constructor\n";
}

// Polygons::Polygons( const Polygons & src )
// {
// }


// /*
// ** -------------------------------- DESTRUCTOR --------------------------------
// */

Polygons::~Polygons()
{
    std::cout << "Polygons Destructor\n";
}


// /*
// ** --------------------------------- OVERLOAD ---------------------------------
// */

// Polygons &				Polygons::operator=( Polygons const & rhs )
// {
// 	//if ( this != &rhs )
// 	//{
// 		//this->_value = rhs.getValue();
// 	//}
// 	return *this;
// }

// std::ostream &			operator<<( std::ostream & o, Polygons const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


// /*
// ** --------------------------------- METHODS ----------------------------------
// */


// /*
// ** --------------------------------- ACCESSOR ---------------------------------
// */


// /* ************************************************************************** */