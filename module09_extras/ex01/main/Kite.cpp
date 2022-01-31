#include "Kite.hpp"
#include <cmath>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Kite::Kite(unsigned const & hDiag, unsigned const & vDiag) :
	Polygons("kite"),
	hDiag(hDiag),
	vDiag(vDiag),
	sideA(0),
	sideB(0),
	angle(0)
{
}

Kite::Kite(unsigned const & sideA, unsigned const & sideB, int const & sharedAgnle) :
	Polygons("kite"),
	hDiag(0),
	vDiag(0),
	sideA(sideA),
	sideB(sideB),
	angle(sharedAgnle)
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

float const			Kite::area() const {
	if (angle) {
		return sideA * sideB * std::sin(angle * M_PI / 180);
	}
	else return (hDiag * vDiag) / 2.0;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */