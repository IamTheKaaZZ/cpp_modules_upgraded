#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap() : ClapTrap(), gateKeeper(false)
{
	this->name = "ScavTrapper";
	this->hitpoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap Def. Constructor\n";
}

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap(src)
{
	this->gateKeeper = src.gateKeeper;
	std::cout << "ScavTrap Copy Constructor\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
{
	if ( this != &rhs )
	{
		ClapTrap::operator=(rhs);
		this->gateKeeper = rhs.gateKeeper;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void				ScavTrap::guardGate() {
	if (!this->gateKeeper) {
		this->gateKeeper = true;
		std::cout << "ScavTrap <" << this->name << " started guarding the gate.\n";
	}
	else {
		this->gateKeeper = false;
		std::cout << "ScavTrap <" << this->name << " stopped guarding the gate.\n";
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */