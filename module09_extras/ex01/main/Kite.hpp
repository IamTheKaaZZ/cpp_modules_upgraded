#ifndef KITE_HPP
# define KITE_HPP

# include <iostream>
# include <string>
# include <cmath>
# include "Polygons.hpp"
# define _USE_MATH_DEFINES

class Kite : public Polygons
{

	public:

		Kite() = delete;
		Kite(unsigned const & hDiag, unsigned const & vDiag);
		Kite(unsigned const & sideA, unsigned const & sideB, int const & sharedAngle);
		Kite( Kite const & src ) = default;
		~Kite() = default;

		Kite &		operator=( Kite const & rhs ) = default;
		float const		area() const;

	private:

		unsigned	hDiag;
		unsigned	vDiag;
		unsigned	sideA;
		unsigned	sideB;
		int			angle;

};

#endif /* ************************************************************ KITE_H */