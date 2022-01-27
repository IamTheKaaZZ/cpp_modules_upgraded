#include "Karen.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Karen::Karen()
{
	kMap["DEBUG"] = std::mem_fn(&Karen::debug);
	kMap["INFO"] = std::mem_fn(&Karen::info);
	kMap["WARNING"] = std::mem_fn(&Karen::warning);
	kMap["ERROR"] = std::mem_fn(&Karen::error);
}

Karen::Karen( const Karen & src ) : kMap(src.kMap)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Karen::~Karen()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Karen &				Karen::operator=( Karen const & rhs )
{
	if ( this != &rhs )
	{
		this->kMap = rhs.kMap;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				Karen::complain(std::string level) {
	if (kMap.find(level) != kMap.end())
		kMap[level](nullptr);
	else
		std::cout << "Instructions unclear, called the manager." << std::endl;
}

void				Karen::debug() {
	std::cout << "Karen debug ooga booga" << std::endl;
}

void				Karen::info() {
	std::cout << "Karen no understand info ooga booga" << std::endl;
}

void				Karen::warning() {
	std::cout << "Karen 'ooga boogas' as a warning" << std::endl;
}

void				Karen::error() {
	std::cout << "ERROR OOGA BOOGA" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */