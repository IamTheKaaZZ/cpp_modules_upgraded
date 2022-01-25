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
    return EXIT_SUCCESS;
}