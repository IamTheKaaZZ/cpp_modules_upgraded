#ifndef RECTANGLE_HPP
# define RECTANGLE_HPP

# include "Polygons.hpp"
# include <iostream>
# include <string>

class Rectangle : public Polygons
{

	public:

		Rectangle() = delete;
		Rectangle(unsigned const & height, unsigned const & width);
		Rectangle( Rectangle const & src ) = default;
		~Rectangle() = default;

		Rectangle &		operator=( Rectangle const & rhs ) = default;
		float const		area() const;

	private:
		unsigned	_height;
		unsigned	_width;

};

#endif /* ******************************************************* RECTANGLE_H */