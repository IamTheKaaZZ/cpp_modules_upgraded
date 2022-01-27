#ifndef PARALLELOGRAM_HPP
# define PARALLELOGRAM_HPP

# include <iostream>
# include <string>

class Parallelogram
{

	public:

		Parallelogram();
		Parallelogram( Parallelogram const & src );
		~Parallelogram();

		Parallelogram &		operator=( Parallelogram const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, Parallelogram const & i );

#endif /* *************************************************** PARALLELOGRAM_H */