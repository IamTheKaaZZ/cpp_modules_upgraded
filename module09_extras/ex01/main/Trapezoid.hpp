#ifndef TRAPEZOID_HPP
# define TRAPEZOID_HPP

# include "Polygons.hpp"
#include <cmath>
# include <iostream>
# include <string>

class Trapezoid : public Polygons
{

	public:

		Trapezoid() = delete;
		Trapezoid(unsigned const & base1, unsigned const & base2, unsigned const & height);
		Trapezoid( Trapezoid const & src ) = default;
		~Trapezoid() = default;

		Trapezoid &		operator=( Trapezoid const & rhs ) = default;
		float const 	area() const;

	private:

		unsigned	b1;
		unsigned	b2;
		unsigned	h;

};

std::ostream &			operator<<( std::ostream & o, Trapezoid const & i );

#endif /* ******************************************************* TRAPEZOID_H */