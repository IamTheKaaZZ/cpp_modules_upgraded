#include "Rhombus.hpp"
#include "Polygons.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Rhombus::Rhombus(unsigned const & a, unsigned const & b, bool const & diag) :
	Polygons("rhombus"),
	side(0),
	height(0),
	hDiag(0),
	vDiag(0),
	angle(0)
{
	if (diag) {
		hDiag = a;
		vDiag = b;
	}
	else {
		side = a;
		height = b;
	}
}

Rhombus::Rhombus(unsigned const & side, int const & angle) :
	Polygons("rhombus"),
	side(side),
	height(0),
	hDiag(0),
	vDiag(0),
	angle(angle)
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

float const		Rhombus::area() const {
	if (angle) {
		return side * side * std::sin(angle * M_PI / 180);
	}
	else if (height) {
		return side * height;
	}
	else {
		return (hDiag * vDiag) / 2.0;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */