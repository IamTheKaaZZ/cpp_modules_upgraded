#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap    joao;
    joao.attack("your mom");
    joao.takeDamage(42);
    joao.beRepaired(21);
    ScavTrap    Joana;
    Joana.guardGate();
    Joana.attack("a big rock");
    Joana.takeDamage(3);
    Joana.beRepaired(69);
}