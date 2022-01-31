#include <cstdint>
#include <cassert>
#include <cstdlib>

struct Rectangle {
    Rectangle(const uint32_t width, const uint32_t height) : m_width{width}, m_height{height} {}

    uint32_t get_width() const { return m_width; }
    uint32_t get_height() const { return m_height; }

    virtual void set_width(const uint32_t width) { this->m_width = width; }
    virtual void set_height(const uint32_t height) { this->m_height = height; }

    uint32_t area() const { return m_width * m_height; }
    //
    bool        is_square() { return (m_height == m_width) ? true : false; }
    //

protected:
    uint32_t m_width, m_height;
};

struct Square : Rectangle {
    Square(uint32_t size) : Rectangle(size, size) {}
    void set_width(const uint32_t width) override { this->m_width = m_height = width; }
    void set_height(const uint32_t height) override { this->m_height = m_width = height; }
};

//-----------------------------------------------------------//
//  Not that good => Casting
//-----------------------------------------------------------//

void process_bad(Rectangle &r) {
    uint32_t w = r.get_width();
    r.set_height(10);

    if (dynamic_cast<Square *>(&r) != nullptr)
        assert((r.get_width() * r.get_width()) == r.area());
    else
        assert((w * 10) == r.area());
}

//-----------------------------------------------------------//
//  Better => using a boolean function
//-----------------------------------------------------------//

void process_better(Rectangle &r) {
    uint32_t w = r.get_width();
    r.set_height(10);

    if (r.is_square())
        assert((r.get_width() * r.get_width()) == r.area());
    else
        assert((w * 10) == r.area());
}

//-----------------------------------------------------------//
//  Best => Proper inheritance hierarchy
//-----------------------------------------------------------//

struct Shape {
    virtual uint32_t area() const = 0;
};

struct Rectangle_best : Shape {
    Rectangle_best(const uint32_t width, const uint32_t height) : m_width{width}, m_height{height} {}

    uint32_t get_width() const { return m_width; }
    uint32_t get_height() const { return m_height; }

    virtual void set_width(const uint32_t width) { this->m_width = width; }
    virtual void set_height(const uint32_t height) { this->m_height = height; }

    uint32_t area() const override { return m_width * m_height; }

private:
    uint32_t m_width, m_height;
};

struct Square_best : Shape {
    Square_best(uint32_t size) : m_size(size) {}
    void set_size(const uint32_t size) { this->m_size = size; }
    uint32_t area() const override { return m_size * m_size; }

private:
    uint32_t m_size;
};

void process(Shape &s) {
    // Use polymorphic behaviour only i.e. area()
}

// + Factory Pattern

struct ShapeFactory {
    static Shape CreateRectangle(uint32_t width, uint32_t height);
    static Shape CreateSquare(uint32_t size);
};

/*

Benefits of Liskov’s Substitution Principle
=> Compatibility

    It enables the binary compatibility between multiple releases & patches. In other words, It keeps the client code away from being impacted.

=> Type Safety

    It’s the easiest approach to handle type safety with inheritance, as types are not allowed to vary when inheriting.

=> Maintainability

    Code that adheres to LSP is loosely dependent on each other & encourages code reusability.
    Code that adheres to the LSP is code that makes the right abstractions.

Yardstick to Craft Liskov’s Substitution Principle Friendly Software in C++

    In most introductions to object-oriented programming, inheritance discussed as an “IS-A” relationship with the inherited object.
    However, this is necessary, but not sufficient.
    It is more appropriate to say that one object can be designed to inherit from another if it always has an “IS-SUBSTITUTABLE-FOR” relationship with the inherited object.
    The whole point of using an abstract base class is so that, in the future, you can write a new subclass & insert it into existing, working, tested code.
    A noble goal, but how to achieve it? First, start with decomposing your problem space — domain. Second, express your contract/interfaces/virtual-methods in plain English.
*/