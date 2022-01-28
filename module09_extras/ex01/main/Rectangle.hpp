#ifndef RECTANGLE_HPP
# define RECTANGLE_HPP

# include "Polygons.hpp"
# include <iostream>
# include <string>

class Rectangle : public Polygons
{

	public:

		Rectangle() = delete;
		Rectangle(unsigned height, unsigned width);
		Rectangle( Rectangle const & src );
		~Rectangle();

		Rectangle &		operator=( Rectangle const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, Rectangle const & i );

#endif /* ******************************************************* RECTANGLE_H */