#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <unordered_set>
#include <algorithm>

namespace constellations
{
    enum Relation { STRONG, WEAK };

    class Star
    {
    public:
        using unique_ptr = std::unique_ptr<Star>;
        using shared_ptr = std::shared_ptr<Star>;
        using weak_ptr = std::weak_ptr<Star>;

        Star(const Star&) = delete; // No copy
        Star(Star&&) = delete; // No move

        Star(const std::string& star_name) : name(star_name)
        {
            std::cout << "Star ctor : " << name << "\n";
            starInstances.insert(this);
        }

        ~Star()
        {
            std::cout << "Star dtor : " << name << "\n";
            starInstances.erase(this);
        }

        void addRelation(shared_ptr other, Relation rel = STRONG)
        {
            (rel == STRONG)? strongRelation = other : weakRelation = other;
        }

        const std::string& getName() const
        {
            return name;
        }

        void listRelations()
        {
            std::list<Star*> visitSet;
            doVisit(visitSet);
            for (auto p : visitSet) 
            {
                std::cout << p->getName() << std::endl;
            }
        }

        static void listInstances()
        {
            for (auto ps : starInstances)
            {
                std::cout << ps->getName() << std::endl;
            }
        }

        static void clearInstancesList()
        {
            starInstances.clear();
        }

    private:
        void doVisit(std::list<Star*>& visitSet)
        {
            auto it = std::find(visitSet.begin(), visitSet.end(), this);
            if (strongRelation && it != visitSet.end())
            {
                std::cout << visitSet.back()->getName() << " closes a loop with " << name << std::endl;
                //std::cout << name << " dropping strong relation to " << strongRelation->name << "\n";
                //weakRelation = strongRelation;
                //strongRelation.reset();
            }

            if (strongRelation != nullptr && it == visitSet.end())
            {
                std::cout << name << " has a strong relation to " << strongRelation->name << "\n";
                visitSet.push_back(this);
                strongRelation->doVisit(visitSet);
            }
        }

        std::string name;
        shared_ptr strongRelation;
        weak_ptr weakRelation;
        static std::unordered_set<Star*> starInstances;
    };

    std::unordered_set<Star*> Star::starInstances;
}

namespace unique_pointer
{
    using namespace constellations;

    Star::unique_ptr doOneThing(Star::unique_ptr star)
    {
        std::cout << "- doOneThing() on " << star->getName() << "\n";
        return star; // Move on return by copy is implicit - this is the preferred option
    }

    void doSomeSideWork(const Star::unique_ptr& star)
    {
        std::cout << "- doSomeSideWork() on " << star->getName() << "\n";
    }

    Star::unique_ptr doSomethingElse(Star::unique_ptr star)
    {
        std::cout << "- doSomethingElse() on " << star->getName() << "\n";
        return std::move(star); // Explicit move on return by copy has no effect, is the same as "return star"
    }

    void doOtherThing(Star::unique_ptr star)
    {
        std::cout << "- doOtherThing() on " << star->getName() << "\n";
        doSomeSideWork(star);
        star = doSomethingElse(std::move(star));
        // ...
    }

    void runDemo()
    {
        std::cout << "\n* -------------------------------------------------------------";
        std::cout << "\n* Unique Pointer";
        std::cout << "\n* -------------------------------------------------------------\n";

        auto sirius = std::make_unique<Star>("Sirius");

        sirius = doOneThing(std::move(sirius));
        (sirius)? std::cout << "- My good star is still with me\n" : std::cout << "- My good star has done, better I go too\n";
        doOtherThing(std::move(sirius));
        (sirius)? std::cout << "- My good star is still with me\n" : std::cout << "- My good star has done, better I go too\n";

        // Unique pointers can be moved but not copied
        // Uncommenting the following line results in compilation error
        // sirius = doOneThing(sirius);
    }
}

namespace shared_pointer
{
    using namespace constellations;

    void demoSharedLoop(bool do_loop = true)
    {
        std::cout << "\n* -------------------------------------------------------------";
        (do_loop)
            ? std::cout << "\n* Shared Pointer (shared_ptr loop)"
            : std::cout << "\n* Shared Pointer (weak_ptr loop)";
        std::cout << "\n* -------------------------------------------------------------\n";

        std::cout << "\n* Create the stars\n";
        auto alkaid = std::make_shared<Star>("Alkaid");
        auto alcor = std::make_shared<Star>("Alcor");
        auto alioth = std::make_shared<Star>("Alioth");
        auto megrez = std::make_shared<Star>("Megrez");
        auto dubhe = std::make_shared<Star>("Dubhe");
        auto merak = std::make_shared<Star>("Merak");
        auto phecda = std::make_shared<Star>("Phecda");

        std::cout << "\n* Form the constellation\n";
        alkaid->addRelation(alcor);
        alcor->addRelation(alioth);
        alioth->addRelation(megrez);
        megrez->addRelation(dubhe);
        dubhe->addRelation(merak);
        merak->addRelation(phecda);
        phecda->addRelation(megrez, (do_loop)? STRONG : WEAK);

        alkaid->listRelations();
        std::cout << "\n* End demo\n";
    }

    void checkUseCountPassingByValue(Star::shared_ptr star)
    {
        std::cout << "- Use count inside pass by value " << star.use_count() << "\n";
    }

    void checkUseCountPassingByReference(const Star::shared_ptr &star)
    {
        std::cout << "- Use count inside pas by reference " << star.use_count() << "\n";
    }

    void checkUseCount()
    {
        std::cout << "\n* -------------------------------------------------------------";
        std::cout << "\n* Shared Pointer Use Count";
        std::cout << "\n* -------------------------------------------------------------\n";

        std::cout << "- Create star Antares\n";
        auto antares = std::make_shared<Star>("Antares");
        Star::shared_ptr share1;
        Star::shared_ptr share2;
        Star::shared_ptr share3;
        Star::weak_ptr weak;

        std::cout << "- Use count at the beginning " << antares.use_count() << "\n";
        share1 = antares;
        std::cout << "- Use count after new share " << antares.use_count() << "\n";
        share2 = antares;
        std::cout << "- Use count after new share " << antares.use_count() << "\n";
        weak = antares;
        std::cout << "- Use count after weak share " << antares.use_count() << "\n";

        share3 = weak.lock();
        std::cout << "- Use count after weak lock " << antares.use_count() << "\n";

        checkUseCountPassingByValue(antares);
        std::cout << "- Use count after call by value " << antares.use_count() << "\n";
        checkUseCountPassingByReference(antares);
        std::cout << "- Use count after call by reference " << antares.use_count() << "\n";

        share1 = nullptr;   // Assigning to null releases the reference to the object and decreases the reference count
        std::cout << "- Use count after shared reset " << antares.use_count() << "\n";
        share2.reset();     // Reset has the same effect as assigning to null
        std::cout << "- Use count after shared reset " << antares.use_count() << "\n";
        share3 = nullptr;
        std::cout << "- Use count after shared reset " << antares.use_count() << "\n";

        (antares)? std::cout << "antares still valid\n" : std::cout << "antares no longer valid \n";
        (share1)? std::cout << "share1 still valid\n" : std::cout << "share1 no longer valid \n";
        (share2)? std::cout << "share2 still valid\n" : std::cout << "share2 no longer valid \n";
        (share3)? std::cout << "share3 still valid\n" : std::cout << "share3 no longer valid \n";
        (weak.expired())? std::cout << "weak has expired\n" : std::cout << "weak is still valid \n";

        antares.reset();
        std::cout << "- Use count after shared reset " << antares.use_count() << "\n";

        (antares)? std::cout << "antares still valid\n" : std::cout << "antares no longer valid \n";
        (share1)? std::cout << "share1 still valid\n" : std::cout << "share1 no longer valid \n";
        (share2)? std::cout << "share2 still valid\n" : std::cout << "share2 no longer valid \n";
        (share3)? std::cout << "share3 still valid\n" : std::cout << "share3 no longer valid \n";
        (weak.expired())? std::cout << "weak has expired\n" : std::cout << "weak is still valid \n";
    }

    void runDemo()
    {
        demoSharedLoop(true);
        std::cout << "\n* List memory leaks, if any\n";
        Star::listInstances();
        Star::clearInstancesList();

        demoSharedLoop(false);
        std::cout << "\n* List memory leaks, if any\n";
        Star::listInstances();

        checkUseCount();
    }
}

int main()
{
    unique_pointer::runDemo();
    shared_pointer::runDemo();

    return 0;
}
