#ifndef SQUARE_HPP
# define SQUARE_HPP

# include <iostream>
# include <string>

class Square
{

	public:

		Square();
		Square( Square const & src );
		~Square();

		Square &		operator=( Square const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, Square const & i );

#endif /* ********************************************************** SQUARE_H */