#ifndef RHOMBUS_HPP
# define RHOMBUS_HPP

# include "Polygons.hpp"
# include <iostream>
# include <string>
# include <cmath>
# define _USE_MATH_DEFINES

class Rhombus : public Polygons
{

	public:

		Rhombus() = delete;
		Rhombus(unsigned const & a, unsigned const & b, bool const & diag);
		Rhombus(unsigned const & side, int const & angle);
		Rhombus( Rhombus const & src ) = default;
		~Rhombus() = default;

		Rhombus &		operator=( Rhombus const & rhs ) = default;
		float const	area() const;

	private:

		unsigned	side;
		unsigned	height;
		unsigned	hDiag;
		unsigned	vDiag;
		int	angle;

};

#endif /* ********************************************************* RHOMBUS_H */