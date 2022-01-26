#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap() :
	name("ClapTrapper"),
	hitpoints(10),
	energyPoints(10),
	attackDamage(0)
{
	std::cout << "ClapTrap Def. Constructor\n";
}

ClapTrap::ClapTrap(std::string const & name) :
	name(name),
	hitpoints(10),
	energyPoints(10),
	attackDamage(0)
{
	std::cout << "ClapTrap Param. Constructor\n";
}

//is default therefore no implementation
// ClapTrap::ClapTrap( const ClapTrap & src )
// {
// }


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

//is default therefore no implementation
// ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
// {
// 	//if ( this != &rhs )
// 	//{
// 		//this->_value = rhs.getValue();
// 	//}
// 	return *this;
// }

// std::ostream &			operator<<( std::ostream & o, ClapTrap const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

void			ClapTrap::attack(const std::string &target) {
	if (this->energyPoints >= 10) {
		std::cout << "ClapTrap <" << this->name << "> attacks " << target << " dealing " << this->attackDamage << " points of damage!\n";
		if (this->energyPoints < 10) this->energyPoints = 0;
		else this->energyPoints -= 10;
		std::cout << "It has " << this->energyPoints << " energy points remaining!\n";
	}
	else {
		std::cout << "ClapTrap <" << this->name << "> cannot attack " << target << " because it ran out of energy!\n";
	}
}

void			ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap <" << this->name << "> took " << amount << " points of damage!\n";
	if (amount > this->hitpoints)
		amount = this->hitpoints;
	this->hitpoints -= amount;
	if (!this->hitpoints)
		std::cout << "It was destroyed!\n";
	else
		std::cout << "It has " << this->hitpoints << " remaining!\n";
}

void			ClapTrap::beRepaired(unsigned int amount) {
	if (!this->hitpoints)
		std::cout << "ClapTrap <" << this->name << "> got brought back to life through the ways of science!\n";
	else
		std::cout << "ClapTrap <" << this->name << "> got it hitpoints restored!\n";
	this->hitpoints += amount;
	std::cout << "It now has " << this->hitpoints << " hitpoints!\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */