#include <iostream>
#include <string>
#include <utility> // for std::move
#include <vector>
#include "copy_swap.hpp"
#include "move_swap.hpp"

int main () {
    int a = 21;
    int b = 42;
    std::string c = "LOL";
    std::string d = "LMAO";

    std::cout << a << '\n';
    std::cout << b << '\n';
    std::cout << c << '\n';
    std::cout << d << '\n';
    copySwap(a, b);
    copySwap(c, d);
    std::cout << a << '\n';
    std::cout << b << '\n';
    std::cout << c << '\n';
    std::cout << d << '\n';
    int e = std::move(a) + std::move(b);
    std::string f = std::move(c) + std::move(d);
    std::cout << a << '\n';
    std::cout << b << '\n';
    std::cout << c << '\n';
    std::cout << d << '\n';
    std::cout << e << '\n';
    std::cout << f << '\n';
}