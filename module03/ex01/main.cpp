#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap    joao;
    joao.attack("your mom");
    joao.takeDamage(42);
    joao.beRepaired(21);
    ClapTrap    johnny("Johnny");
    johnny.attack("your mom");
    johnny.takeDamage(42);
    johnny.beRepaired(21);
    ScavTrap    Joana;
    Joana.guardGate();
    Joana.attack("a big rock");
    Joana.takeDamage(3);
    Joana.beRepaired(69);
    ScavTrap    Joana_plus("Better Joana");
    Joana_plus.guardGate();
    Joana_plus.attack("a big rock");
    Joana_plus.takeDamage(3);
    Joana_plus.beRepaired(69);
    Joana = Joana_plus;
    Joana.guardGate();
}