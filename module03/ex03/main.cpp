#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"

int main() {
    DiamondTrap basic;
    basic.attack("this subject lol");
    basic.takeDamage(42);
    basic.beRepaired(69);
    basic.guardGate();
    basic.highFiveGuys();
    basic.whoAmI();
    DiamondTrap upgrade("DIAMOND DUST");
    upgrade.attack("this subject lol");
    upgrade.takeDamage(42);
    upgrade.beRepaired(69);
    upgrade.guardGate();
    upgrade.highFiveGuys();
    upgrade.whoAmI();
    DiamondTrap copy = basic;
    copy.guardGate();
    copy.whoAmI();
    copy.highFiveGuys();
}