#include <memory>
#include "SharedPtr.hpp"

struct Foo {
    int n1;
    int n2; 
    Foo(int a, int b) : n1(a), n2(b) {}
};

int main()
{
    SmartPointer::SharedPtr<int> p1;
    SmartPointer::SharedPtr<int> p2 (nullptr);
    SmartPointer::SharedPtr<int> p3 (new int);
    SmartPointer::SharedPtr<int> p6 (p3);
    SmartPointer::SharedPtr<int> p7 (std::move(p6));
    SmartPointer::SharedPtr<Foo> obj (new Foo(2, 4));
    SmartPointer::SharedPtr<int> p9 (obj, &obj->n1);

    std::cout << "use_count:\n";
    std::cout << "p1: " << p1.use_count() << '\n';
    std::cout << "p2: " << p2.use_count() << '\n';
    std::cout << "p3: " << p3.use_count() << '\n';
    std::cout << "p6: " << p6.use_count() << '\n';
    std::cout << "p7: " << p7.use_count() << '\n';
    std::cout << "p9: " << p9.use_count() << '\n';
    
    auto p1 = SmartPointer::make_shared<Foo>(1, 2);
    SmartPointer::SharedPtr<int> p2(p1, &p1->n1);
    SmartPointer::SharedPtr<int> p3(p1, &p1->n2);
 
    std::cout << std::boolalpha
              << "p2 < p3 " << (p2 < p3) << '\n'
              << "p3 < p2 " << (p3 < p2) << '\n';
}