#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{

	public:

		Zombie() = delete;
		Zombie(std::string const & name);
		Zombie( Zombie const & src );
		~Zombie();

		Zombie &		operator=( Zombie const & rhs );
		std::string const &	getName() const { return this->_name; }
		void			announce() const;

	private:

		std::string	_name;

};

std::ostream &			operator<<( std::ostream & o, Zombie const & i );
Zombie*					newZombie(std::string const & name);
void					randomChump(std::string const & name);

#endif /* ********************************************************** ZOMBIE_H */