#include "Zombie.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Zombie::Zombie(std::string const & name) : _name(name)
{
}

Zombie::Zombie( const Zombie & src ) : _name(src._name)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Zombie::~Zombie()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Zombie &				Zombie::operator=( Zombie const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs._name;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Zombie const & i )
{
	o << "Name = " << i.getName();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		Zombie::announce() const {
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie*		newZombie(std::string const & name) {
	return new Zombie(name);
}

void		randomChump(const std::string &name) {
	Zombie rando(name);
	rando.announce();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */