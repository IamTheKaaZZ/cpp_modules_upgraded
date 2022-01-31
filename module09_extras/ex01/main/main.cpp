#include "Kite.hpp"
#include "Parallelogram.hpp"
#include "Polygons.hpp"
#include "Rectangle.hpp"
#include "Rhombus.hpp"
#include "Square.hpp"
#include "Trapezoid.hpp"
#include <iomanip>
#include <ios>

int main() {
    Square          s(4); //16
    Rectangle       r(2, 3); //6
    Parallelogram   p1(18, 8, 55); //118
    Parallelogram   p2(2, 3);
    Kite            k1(3, 5); //7.5
    Kite            k2(5, 6, 60); //26
    Rhombus         r1(15, 11, false); //165
    Rhombus         r2(10, 60);
    Rhombus         r3(10, 120); // r2 == r3 aka 86.6
    Rhombus         r4(18, 24, true); //216
    Trapezoid       t(2, 5, 4); //14

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "The name of the polygon = " << s.getName() << "\n";
    std::cout << "Expected area = 16\n";
    std::cout << "The area is = " << s.area() << "\n";
    std::cout << "The name of the polygon = " << r.getName() << "\n";
    std::cout << "Expected area = 6\n";
    std::cout << "The area is = " << r.area() << "\n";
    std::cout << "The name of the polygon = " << p1.getName() << "\n";
    std::cout << "Expected area = 118\n";
    std::cout << "The area is = " << p1.area() << "\n";
    std::cout << "The name of the polygon = " << p2.getName() << "\n";
    std::cout << "Expected area = 6\n";
    std::cout << "The area is = " << p2.area() << "\n";
    std::cout << "The name of the polygon = " << k1.getName() << "\n";
    std::cout << "Expected area = 7.5\n";
    std::cout << "The area is = " << k1.area() << "\n";
    std::cout << "The name of the polygon = " << k2.getName() << "\n";
    std::cout << "Expected area = 26\n";
    std::cout << "The area is = " << k2.area() << "\n";
    std::cout << "The name of the polygon = " << r1.getName() << "\n";
    std::cout << "Expected area = 165\n";
    std::cout << "The area is = " << r1.area() << "\n";
    std::cout << "The name of the polygon = " << r2.getName() << "\n";
    std::cout << "Expected area = 86.6\n";
    std::cout << "The area is = " << r2.area() << "\n";
    std::cout << "The name of the polygon = " << r3.getName() << "\n";
    std::cout << "Expected area = 86.6\n";
    std::cout << "The area is = " << r3.area() << "\n";
    std::cout << "The name of the polygon = " << r4.getName() << "\n";
    std::cout << "Expected area = 216\n";
    std::cout << "The area is = " << r4.area() << "\n";
    std::cout << "The name of the polygon = " << t.getName() << "\n";
    std::cout << "Expected area = 14\n";
    std::cout << "The area is = " << t.area() << "\n";
}