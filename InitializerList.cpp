
#include <iostream>

class Something
{
private:
    const int m_value;

public:
    Something(int x) : m_value{ x } // directly initialize our const member variable
    {
        std::cout << "Something(" << m_value << ")\n";
    }

    void print()
    {
        std::cout << "Something(" << m_value << ")\n";
    }
};

int main()
{
    std::cout << "Enter an integer: ";
    int x{4};
//    std::cin >> x;

    Something s(x);
//    s.print();

    return 0;
}
