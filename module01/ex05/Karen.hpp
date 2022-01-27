#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include <string>
# include <map>
# include <functional>

class Karen
{

	public:

		typedef std::function<void(Karen*)> KarenFunction;

		Karen();
		Karen( Karen const & src );
		~Karen();

		Karen &		operator=( Karen const & rhs );
		void		complain(std::string level);

	private:

		std::map<std::string, KarenFunction>	kMap;
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);

};


#endif /* *********************************************************** KAREN_H */