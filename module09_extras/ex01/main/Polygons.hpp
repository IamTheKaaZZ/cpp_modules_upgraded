#ifndef POLYGONS_HPP
# define POLYGONS_HPP

# include <iostream>
# include <string>

class Polygons
{

	public:

		Polygons() = delete;
		Polygons(std::string const & name);
		Polygons( Polygons const & src ) = default;
		virtual ~Polygons();

		Polygons &		operator=( Polygons const & rhs ) = default;
		virtual float const 	area() const = 0;
		std::string const &	getName() const { return _nameOfPoly; }

	protected:

		std::string	_nameOfPoly;

};

#endif /* ******************************************************** POLYGONS_H */