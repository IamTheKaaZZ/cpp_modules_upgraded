#include "Trapezoid.hpp"
#include "Polygons.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Trapezoid::Trapezoid(unsigned const & base1, unsigned const & base2, unsigned const & height) :
	Polygons("trapezoid"),
	b1(base1),
	b2(base2),
	h(height)
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

float const		Trapezoid::area() const {
	return (b1 + b2) * h / 2.0;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */