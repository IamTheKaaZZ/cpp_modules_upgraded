#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap(), ClapTrap()
{
	this->name = "DiamondTrapper";
	ClapTrap::name = this->name + "_clap_name";
	this->hitpoints = FragTrap::hitpoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap Def. Constructor\n";
}

DiamondTrap::DiamondTrap(std::string const & name) : ScavTrap(name), FragTrap(name), ClapTrap(name)
{
	this->name = name;
	ClapTrap::name = this->name + "_clap_name";
	this->hitpoints = FragTrap::hitpoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap Param. Constructor\n";
}

DiamondTrap::DiamondTrap( const DiamondTrap & src ) : ScavTrap(src), FragTrap(src), ClapTrap(src), name(src.name)
{
	std::cout << "DiamondTrap Copy Constructor\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & rhs )
{
	if ( this != &rhs )
	{
		ScavTrap::operator=(rhs);
		this->name = rhs.name;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void					DiamondTrap::whoAmI() const {
	std::cout << "Who am I? None of your business....\nOkay my name is ";
	std::cout << this->name << " and my claptrap name is " << ClapTrap::name << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */