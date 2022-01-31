#include "Rectangle.hpp"
#include "Polygons.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Rectangle::Rectangle(unsigned const & height, unsigned const & width) :
	Polygons("rectangle"),
	_height(height),
	_width(width)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

float const			Rectangle::area() const {
	return _height * _width;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */