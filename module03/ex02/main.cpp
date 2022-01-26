#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap    joao;
    joao.attack("your mom");
    joao.takeDamage(42);
    joao.beRepaired(21);
    ClapTrap    johnny("Johnny");
    johnny.attack("your mom");
    johnny.takeDamage(42);
    johnny.beRepaired(21);
    FragTrap    Joana;
    Joana.attack("a big rock");
    Joana.takeDamage(3);
    Joana.beRepaired(69);
    FragTrap    Joana_plus("Better Joana");
    Joana_plus.attack("a big rock");
    Joana_plus.takeDamage(3);
    Joana_plus.beRepaired(69);
    Joana_plus.highFiveGuys();
    Joana = Joana_plus;
    Joana.attack("Joana Plus");
    Joana.highFiveGuys();
}