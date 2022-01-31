#include <iostream>
#include <string>
#include <utility> // for std::move
#include <vector>
#include "copy_swap.hpp"
#include "move_swap.hpp"

struct Num {
    int n;
    Num(int const & n) : n(n) {}
    Num(Num const & N) : n(N.n) {
        std::cout << "Copy ctor.\n";
    }
    Num(Num && N) : n(std::move(N.n)) {
        std::cout << "Move ctor.\n";
    }
    Num &   operator=(Num const & rhs) = default;
    int const & getNum() const { return n; }
};

struct Str {
    std::string str;
    Str(std::string const & s) : str(s) {}
    Str(Str const & S) : str(S.str) {
        std::cout << "Copy ctor.\n";
    }
    Str(Str && S) : str(std::move(S.str)) {
        std::cout << "Move ctor.\n";
    }
    Str &   operator=(Str const & rhs) = default;
    std::string const & getStr() const { return str; }
};

int main () {
    Num a = 21;
    Num b = 42;
    Str c("LOL");
    Str d("LMAO");

    std::cout << "Before copy swap\n";
    std::cout << a.getNum() << '\n';
    std::cout << b.getNum() << '\n';
    std::cout << c.getStr() << '\n';
    std::cout << d.getStr() << '\n';
    copySwap(a, b);
    copySwap(c, d);
    std::cout << "After copy swap\n";
    std::cout << a.getNum() << '\n';
    std::cout << b.getNum() << '\n';
    std::cout << c.getStr() << '\n';
    std::cout << d.getStr() << '\n';
    std::cout << "Before move swap\n";
    moveSwap(a, b);
    moveSwap(c, d);
    std::cout << "After move swap\n";
    std::cout << a.getNum() << '\n';
    std::cout << b.getNum() << '\n';
    std::cout << c.getStr() << '\n';
    std::cout << d.getStr() << '\n';
    std::cout << "After move swap\n";
    Num e(std::move(a));
    Str f(std::move(c));
    std::cout << a.getNum() << '\n';
    std::cout << b.getNum() << '\n';
    std::cout << c.getStr() << '\n';
    std::cout << d.getStr() << '\n';
    std::cout << e.getNum() << '\n';
    std::cout << f.getStr() << '\n';
}