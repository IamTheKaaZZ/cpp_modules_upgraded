#ifndef DOUBLELL_HPP
# define DOUBLELL_HPP

# include <iostream>
# include <string>

class DoubleLL
{

	public:

		DoubleLL();
		DoubleLL( DoubleLL const & src );
		~DoubleLL();

		DoubleLL &		operator=( DoubleLL const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, DoubleLL const & i );

#endif /* ******************************************************** DOUBLELL_H */