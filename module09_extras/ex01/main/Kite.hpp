#ifndef KITE_HPP
# define KITE_HPP

# include <iostream>
# include <string>

class Kite
{

	public:

		Kite();
		Kite( Kite const & src );
		~Kite();

		Kite &		operator=( Kite const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, Kite const & i );

#endif /* ************************************************************ KITE_H */