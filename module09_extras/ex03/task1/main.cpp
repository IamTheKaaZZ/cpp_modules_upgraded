#include <memory>
#include "SharedPtr.hpp"

void    originals() {
    std::shared_ptr<int> p1;
    std::shared_ptr<int> p2 (nullptr);
    std::shared_ptr<int> p3 (new int);
    std::shared_ptr<int> p6 (p3);
    std::shared_ptr<int> p7 (std::move(p6));
    std::shared_ptr<int> p8 (std::unique_ptr<int>(new int));

    std::cout << "use_count:\n";
    std::cout << "p1: " << p1.use_count() << '\n';
    std::cout << "p2: " << p2.use_count() << '\n';
    std::cout << "p3: " << p3.use_count() << '\n';
    std::cout << "p6: " << p6.use_count() << '\n';
    std::cout << "p7: " << p7.use_count() << '\n';
    std::cout << "p8: " << p8.use_count() << '\n';

    p1 = p3;
    std::cout << "use_count:\n";
    std::cout << "p3: " << p3.use_count() << '\n';
    p2 = p3;
    std::cout << "use_count:\n";
    std::cout << "p3: " << p3.use_count() << '\n';
    p6 = p3;
    std::cout << "use_count:\n";
    std::cout << "p3: " << p3.use_count() << '\n';
    p7 = nullptr;
    p8 = nullptr;

    std::cout << "use_count:\n";
    std::cout << "p1: " << p1.use_count() << '\n';
    std::cout << "p2: " << p2.use_count() << '\n';
    std::cout << "p3: " << p3.use_count() << '\n';
    std::cout << "p6: " << p6.use_count() << '\n';
    std::cout << "p7: " << p7.use_count() << '\n';
    std::cout << "p8: " << p8.use_count() << '\n';

    std::shared_ptr<int> foo;
    std::shared_ptr<int> bar (new int(10));

    foo = bar;                          // copy

    bar = std::make_shared<int> (20);   // move

    std::unique_ptr<int> unique (new int(30));
    std::cout << "*unique: " << *unique << '\n';
    foo = std::move(unique);            // move from unique_ptr

    std::cout << "*foo: " << *foo << '\n';
    std::cout << "*bar: " << *bar << '\n';

}

void    mine() {
    SmartPointer::SharedPtr<int> p1;
    SmartPointer::SharedPtr<int> p2 (nullptr);
    SmartPointer::SharedPtr<int> p3 (new int);
    SmartPointer::SharedPtr<int> p6 (p3);
    SmartPointer::SharedPtr<int> p7 (std::move(p6));
    SmartPointer::SharedPtr<int> p8 (SmartPointer::UniquePtr<int>(new int));

    std::cout << "use_count:\n";
    std::cout << "p1: " << p1.use_count() << '\n';
    std::cout << "p2: " << p2.use_count() << '\n';
    std::cout << "p3: " << p3.use_count() << '\n';
    std::cout << "p6: " << p6.use_count() << '\n';
    std::cout << "p7: " << p7.use_count() << '\n';
    std::cout << "p8: " << p8.use_count() << '\n';

    p1 = p3;
    std::cout << "use_count:\n";
    std::cout << "p3: " << p3.use_count() << '\n';
    p2 = p3;
    std::cout << "use_count:\n";
    std::cout << "p3: " << p3.use_count() << '\n';
    p6 = p3;
    std::cout << "use_count:\n";
    std::cout << "p3: " << p3.use_count() << '\n';
    p7 = nullptr;
    p8 = nullptr;

    std::cout << "use_count:\n";
    std::cout << "p1: " << p1.use_count() << '\n';
    std::cout << "p2: " << p2.use_count() << '\n';
    std::cout << "p3: " << p3.use_count() << '\n';
    std::cout << "p6: " << p6.use_count() << '\n';
    std::cout << "p7: " << p7.use_count() << '\n';
    std::cout << "p8: " << p8.use_count() << '\n';

    SmartPointer::SharedPtr<int> foo;
    SmartPointer::SharedPtr<int> bar (new int(10));

    foo = bar;                          // copy

    bar = SmartPointer::make_shared<int> (20);   // move

    SmartPointer::UniquePtr<int> unique (new int(30));
    std::cout << "*unique: " << *unique << '\n';

    foo = std::move(unique);            // move from unique_ptr

    std::cout << "*foo: " << *foo << '\n';
    std::cout << "*bar: " << *bar << '\n';

}

int main()
{
    originals();
    mine();
    return 0;
}