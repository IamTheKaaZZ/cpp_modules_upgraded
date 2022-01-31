#include "Parallelogram.hpp"
#include "Polygons.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Parallelogram::Parallelogram(unsigned const & base, unsigned const & height) :
	Polygons("parallelogram"),
	base(base),
	height(height),
	hSide(0),
	vSide(0),
	angle(0)
{
}

Parallelogram::Parallelogram(unsigned const & hSide, unsigned const & vSide, int const & angle) :
	Polygons("parallelogram"),
	base(0),
	height(0),
	hSide(hSide),
	vSide(vSide),
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

float const			Parallelogram::area() const {
	if (angle) {
		return hSide * vSide * std::sin(angle * M_PI / 180);
	}
	else return base * height;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */