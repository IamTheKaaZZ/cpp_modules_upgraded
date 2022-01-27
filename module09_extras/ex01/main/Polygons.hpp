#ifndef POLYGONS_HPP
# define POLYGONS_HPP

# include <iostream>
# include <string>

class Polygons
{

	public:

		Polygons() = delete;
		Polygons( Polygons const & src ) = default;
		virtual ~Polygons() = default;

		Polygons &		operator=( Polygons const & rhs ) = default;
		virtual unsigned &	area() const = 0;

	private:

};

#endif /* ******************************************************** POLYGONS_H */