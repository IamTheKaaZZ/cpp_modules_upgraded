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

protected:
    uint32_t m_width, m_height;
};

struct Square : Rectangle {
    Square(uint32_t size) : Rectangle(size, size) {}
    void set_width(const uint32_t width) override { this->m_width = m_height = width; }
    void set_height(const uint32_t height) override { this->m_height = m_width = height; }
};

void process(Rectangle &r) {
    uint32_t w = r.get_width();
    r.set_height(10);

    assert((w * 10) == r.area()); // Fails for Square <--------------------
}

int main() {
    Rectangle r{5, 5};
    process(r);
    Square s{5};
    process(s);
    return EXIT_SUCCESS;
}

//--------------------------------------------------------------------------------------------------------------//

