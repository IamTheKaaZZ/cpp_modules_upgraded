#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class FragTrap : virtual public ClapTrap
{

	public:

		FragTrap();
		FragTrap(std::string const & name);
		FragTrap( FragTrap const & src );
		virtual ~FragTrap();

		FragTrap &		operator=( FragTrap const & rhs );
		void			highFiveGuys() const;

	private:

};

#endif /* ******************************************************** FRAGTRAP_H */