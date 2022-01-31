#ifndef PARALLELOGRAM_HPP
# define PARALLELOGRAM_HPP

# include "Polygons.hpp"
# include <iostream>
# include <string>
# include <cmath>
# define _USE_MATH_DEFINES

class Parallelogram : public Polygons
{

	public:

		Parallelogram() = delete;
		Parallelogram(unsigned const & base, unsigned const & height);
		Parallelogram(unsigned const & hSide, unsigned const & vSide, int const & angle);
		Parallelogram( Parallelogram const & src ) = default;
		~Parallelogram() = default;

		Parallelogram &		operator=( Parallelogram const & rhs ) = default;
		float const		area() const;

	private:
		unsigned	base;
		unsigned	height;
		unsigned	hSide;
		unsigned	vSide;
		int			angle;

};

#endif /* *************************************************** PARALLELOGRAM_H */