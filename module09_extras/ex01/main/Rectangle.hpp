#ifndef RECTANGLE_HPP
# define RECTANGLE_HPP

# include <iostream>
# include <string>

class Rectangle
{

	public:

		Rectangle();
		Rectangle( Rectangle const & src );
		~Rectangle();

		Rectangle &		operator=( Rectangle const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, Rectangle const & i );

#endif /* ******************************************************* RECTANGLE_H */