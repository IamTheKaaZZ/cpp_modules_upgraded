#include "Square.hpp"
#include "Polygons.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Square::Square(unsigned side) : Polygons("square"), sideLen(side) {
	std::cout << "Square Constructor\n";
}

Square::Square( const Square & src ) : Polygons(src)
{
	std::cout << "Square Copy Constructor\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Square::~Square()
{
	std::cout << "Square Destructor\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Square &				Square::operator=( Square const & rhs )
{
	if ( this != &rhs )
	{
		Polygons::operator=(rhs);
		this->sideLen = rhs.sideLen;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

unsigned				Square::area() const {
	unsigned	result = sideLen * sideLen;
	return result;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */