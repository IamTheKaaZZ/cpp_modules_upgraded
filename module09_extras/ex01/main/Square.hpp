#ifndef SQUARE_HPP
# define SQUARE_HPP

# include "Polygons.hpp"
# include <iostream>
# include <string>

class Square : public Polygons
{

	public:

		Square() = delete;
		Square(unsigned side);
		Square( Square const & src );
		~Square();

		Square &		operator=( Square const & rhs );
		unsigned		area() const;

	private:

		unsigned sideLen;

};

#endif /* ********************************************************** SQUARE_H */