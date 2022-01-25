#include "Zombie.hpp"
#include <cstdlib>

int main() {
    Zombie  john("John");
    Zombie  joao(john);
    Zombie  juan = john;
    john.announce();
    joao.announce();
    juan.announce();
    Zombie* zptr = newZombie("Joao Maria");
    zptr->announce();
    randomChump("Maria Joao");
    delete zptr;
    Zombie* horde = zombieHorde(50, "Cookies");
    for (int i = 0; i < 50; i++) {
        horde[i].announce();
    }
    delete [] horde;
    return EXIT_SUCCESS;
}