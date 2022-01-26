#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class ScavTrap : public ClapTrap
{

	public:

		ScavTrap();
		ScavTrap( ScavTrap const & src );
		~ScavTrap();

		ScavTrap &		operator=( ScavTrap const & rhs );
		void			guardGate();

	private:

		bool	gateKeeper;

};

#endif /* ******************************************************** SCAVTRAP_H */