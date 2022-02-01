#include "BasePtr.hpp"
#include "UniquePtr.hpp"
#include "moveSwap.hpp"

template<class T>
void    printVal(SmartPointer::UniquePtr<T> & up) {
    std::cout << "Value pointed to of up = ";
    if (up.get() == nullptr) std::cout << "NULL\n";
    else std::cout << *up << '\n';
}

int main () {
    SmartPointer::UniquePtr<int>    upa(new int(42));
    SmartPointer::UniquePtr<int>    upb;

    printVal<int>(upa);
    printVal<int>(upb);

    upb.swap(upa);

    printVal<int>(upa);
    printVal<int>(upb);

    upb = SmartPointer::make_unique<int>(69);

    printVal<int>(upb);

    int*    intPtr = upb.release();
    printVal<int>(upb);
    std::cout << "the released pointer contains = " << *intPtr << '\n';
}