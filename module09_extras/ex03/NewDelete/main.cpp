#include <iostream>
#include <vector>
#include <list>

class TestDummy final {
public:
    TestDummy() { std::cout << this << ": TestDummy ctor\n"; }
    TestDummy(const TestDummy& other) { std::cout << this << ": TestDummy copy ctor from : " << &other << "\n"; }
    TestDummy(TestDummy&& other) { std::cout << this << ": TestDummy move ctor from : " << &other << "\n"; }
    TestDummy& operator=(const TestDummy& other) { std::cout << this << ": TestDummy copy assignment from : " << &other << "\n"; return *this; }
    TestDummy& operator=(TestDummy&& other) { std::cout << this << ": TestDummy move assignment from : " << &other << "\n"; return *this; }
    ~TestDummy() { std::cout << this << ": TestDummy dtor\n"; }
};

namespace simple_allocation
{
    void createByValue()
    {
        std::vector<TestDummy> vecDummyPtr;
        // vecDummyPtr.reserve(3);  // With sufficient space reserved upfront

        for (int i = 0; i < 3; i++)
        {
            std::cout << "createByValue() i = " << i << "\n";
            TestDummy dummy;
            std::cout << "createByValue() push_back " << i << "\n";
            // Use std::move to distinguish from copies done by vector growth
            vecDummyPtr.push_back(std::move(dummy));
        }

        std::cout << "createByValue() end\n";
    }

    void createMemoryLeaks()
    {
        std::vector<TestDummy*> vecDummyPtr;

        for (int i = 0; i < 3; i++)
        {
            TestDummy* pDummy = new TestDummy();
            vecDummyPtr.push_back(pDummy);
        }

        vecDummyPtr.clear();
    }

    void cleanProperly()
    {
        std::vector<TestDummy*> vecDummyPtr;

        for (int i = 0; i < 3; i++)
        {
            TestDummy* pDummy = new TestDummy();
            vecDummyPtr.push_back(pDummy);
        }

        for (auto p : vecDummyPtr)
        {
            delete p;
        }

        vecDummyPtr.clear();
    }

    void runDemo()
    {
        std::cout << "\n* -------------------------------------------------------------";
        std::cout << "\n* Simple Allocation";
        std::cout << "\n* -------------------------------------------------------------\n";

        std::cout << "\n* Create memory leaks (objects inserted in the vector are not deleted\n";
        createMemoryLeaks();

        std::cout << "\n* Do proper cleanup (objects inserted in the vector are deleted\n";
        cleanProperly();

        std::cout << "\n* Do the same with value types instead of pointers just to compare\n";
        createByValue();
    }
}

namespace array_allocation
{
    void badDeallocation()
    {
        const std::size_t N_OBJS = 3;
        std::cout << "\n* Allocating an array of " << N_OBJS << " objects\n";
        TestDummy* pDummies = new TestDummy[N_OBJS];
        std::cout << "\n* Attempting to cleanup with regular (non-array) delete\n";
        delete pDummies;
    }

    void gooddDeallocation()
    {
        const std::size_t N_OBJS = 3;
        std::cout << "\n* Allocating an array of " << N_OBJS << " objects\n";
        TestDummy* pDummies = new TestDummy[N_OBJS];
        std::cout << "\n* Cleanup with array delete[]\n";
        delete[] pDummies;
    }

    void runDemo()
    {
        std::cout << "\n* -------------------------------------------------------------";
        std::cout << "\n* Array Allocation";
        std::cout << "\n* -------------------------------------------------------------\n";

        //array_allocation::badDeallocation();
        array_allocation::gooddDeallocation();
    }
}

namespace placement_new
{
    constexpr std::size_t N_OBJS = 3;
    constexpr std::size_t STORAGE_SIZE = N_OBJS * sizeof(TestDummy);

    char dummyStorage[STORAGE_SIZE];

    void runDemo()
    {
        std::cout << "\n* -------------------------------------------------------------";
        std::cout << "\n* Placement New";
        std::cout << "\n* -------------------------------------------------------------\n";

        std::cout << "\n* Placing three dummies in the Dummy Storage\n";
        TestDummy* pD1 = new (&dummyStorage[0 * sizeof(TestDummy)]) TestDummy;
        TestDummy* pD2 = new (&dummyStorage[1 * sizeof(TestDummy)]) TestDummy;
        TestDummy* pD3 = new (&dummyStorage[2 * sizeof(TestDummy)]) TestDummy;

        std::cout << "\n* Expolicitly invoking the destructors of the three dummies\n";
        pD1->~TestDummy();
        pD2->~TestDummy();
        pD3->~TestDummy();

        std::cout << "\n* Creating another dummy in the local scope\n";
        TestDummy localDummy;
        std::cout << "\n* Using placement new to re-invoke the constructor of the dummy\n";
        TestDummy* pR = new (&localDummy) TestDummy;

        std::cout << "\n* runDemo() end\n";
    }
}

int main()
{
    simple_allocation::runDemo();
    array_allocation::runDemo();
    placement_new::runDemo();

    return 0;
}
