#include <memory>
#include "SmartPointer.hpp"
#include "SharedPtr.hpp"
#include "WeakPtr.hpp"

void    originals() {
    std::shared_ptr<int> sp (new int);

    std::weak_ptr<int> wp1;
    std::weak_ptr<int> wp2 (wp1);
    std::weak_ptr<int> wp3 (sp);

    std::cout << "use_count:\n";
    std::cout << "wp1: " << wp1.use_count() << '\n';
    std::cout << "wp2: " << wp2.use_count() << '\n';
    std::cout << "wp3: " << wp3.use_count() << '\n';

    std::shared_ptr<int> shared (new int(10));
    std::weak_ptr<int> weak(shared);

    std::cout << "1. weak " << (weak.expired()?"is":"is not") << " expired\n";

    shared.reset();

    std::cout << "2. weak " << (weak.expired()?"is":"is not") << " expired\n";

    std::shared_ptr<int> sp1,sp2;
    std::weak_ptr<int> wp;
                                        // sharing group:
                                        // --------------
    sp1 = std::make_shared<int> (20);    // sp1
    std::cout << "use_count:\n";
    std::cout << "sp1: " << sp1.use_count() << '\n';
    wp = sp1;                            // sp1, wp
    std::cout << "use_count:\n";
    std::cout << "wp: " << wp.use_count() << '\n';

    sp2 = wp.lock();                     // sp1, wp, sp2
    std::cout << "use_count:\n";
    std::cout << "sp2: " << sp2.use_count() << '\n';
    sp1.reset();                         //      wp, sp2

    sp1 = wp.lock();                     // sp1, wp, sp2

    std::cout << "*sp1: " << *sp1 << '\n';
    std::cout << "*sp2: " << *sp2 << '\n';

}

void    mine() {

    SmartPointer::SharedPtr<int> sp (new int);

    SmartPointer::WeakPtr<int> wp1;
    SmartPointer::WeakPtr<int> wp2 (wp1);
    SmartPointer::WeakPtr<int> wp3 (sp);

    std::cout << "use_count:\n";
    std::cout << "wp1: " << wp1.use_count() << '\n';
    std::cout << "wp2: " << wp2.use_count() << '\n';
    std::cout << "wp3: " << wp3.use_count() << '\n';

    SmartPointer::SharedPtr<int> shared (new int(10));
    SmartPointer::WeakPtr<int> weak(shared);

    std::cout << "1. weak " << (weak.expired()?"is":"is not") << " expired\n";
    std::cout << "1. weak " << (*weak.get()) << std::endl;
    std::cout << "1. weak " << (weak.use_count()) << std::endl;
    std::cout << "1. shared " << (shared.use_count()) << std::endl;

    shared.reset();
    std::cout << "2. weak " << (weak.use_count()) << std::endl;
    std::cout << "2. shared " << (shared.use_count()) << std::endl;

    std::cout << "2. weak " << (weak.expired()?"is":"is not") << " expired\n";

    SmartPointer::SharedPtr<int> sp1,sp2;
    SmartPointer::WeakPtr<int> wp;
                                                // sharing group:
                                                // --------------
    sp1 = SmartPointer::make_shared<int> (20);  // sp1
    std::cout << "use_count:\n";
    std::cout << "sp1: " << sp1.use_count() << '\n';
    wp = sp1;                            // sp1, wp
    std::cout << "use_count:\n";
    std::cout << "wp: " << wp.use_count() << '\n';

    sp2 = wp.lock();                     // sp1, wp, sp2
    std::cout << "use_count:\n";
    std::cout << "sp2: " << sp2.use_count() << '\n';
    sp1.reset();                         //      wp, sp2

			std::cout << "segfault hunting\n";
    sp1 = wp.lock();                            // sp1, wp, sp2
			std::cout << "segfault hunting\n";

    std::cout << "*sp1: " << *sp1 << '\n';
    std::cout << "*sp2: " << *sp2 << '\n';


}

int main()
{
    originals();
    mine();
    return 0;
}