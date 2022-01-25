#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include <string>
# include <map>

class Karen
{

	public:

		Karen();
		Karen( Karen const & src );
		~Karen();

		Karen &		operator=( Karen const & rhs );
		void		complain(std::string level);

	private:

		std::map<std::string, void(Karen::*)(void)>	kMap;
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);

};


#endif /* *********************************************************** KAREN_H */