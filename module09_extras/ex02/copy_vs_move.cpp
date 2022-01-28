#include <iostream>
#include <string>
#include <utility> // for std::move
#include <vector>
#include "copy_swap.hpp"
#include "move_swap.hpp"

//https://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html

//Rvalues and lvalues - bitter rivals, or best of friends?

/*
In C++, there are rvalues and lvalues.
An lvalue is an expression whose address can be taken, a locator value--essentially,
an lvalue provides a (semi)permanent piece of memory. You can make assignments to lvalues.
For example:

int a;
a = 1; // here, a is an lvalue

You can also have lvalues that aren't variables:
int x;
int& getRef () 
{
        return x;
}
 
=> int& refToX = x;

getRef() = 4;
refToX = 4;
int* ptrX = &getRef();

Here, getRef returns a reference to a global variable, so it's returning a value that is stored in a permanent location.
(You could literally write & getRef() if you wanted to, and it would give you the address of x.)

Rvalues are--well, rvalues are not lvalues. An expression is an rvalue if it results in a temporary object. For example:
int x;
int getVal ()
{
    return x;
}
getVal();

Here, getVal() is an rvalue--the value being returned is not a reference to x, it's just a temporary value.
This gets a little bit more interesting if we use real objects instead of numbers:
string getName ()
{
    return "Alex";
}
getName();

Here, getName returns a string that is constructed inside the function.
You can assign the result of getName to a variable:
string name = getName();

But you're assigning from a temporary object, not from some value that has a fixed location. getName() is an rvalue.

*/

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
}