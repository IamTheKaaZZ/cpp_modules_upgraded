#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{

	public:

		ClapTrap();
		ClapTrap(std::string const & name);
		ClapTrap( ClapTrap const & src ) = default;
		~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs ) = default;
		void			attack(std::string const & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

	private:

		std::string		name;
		unsigned int	hitpoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;

};

// std::ostream &			operator<<( std::ostream & o, ClapTrap const & i );

#endif /* ******************************************************** CLAPTRAP_H */