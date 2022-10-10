//We use mutable variable in this pattern of classes, where we add some perticular data to be changed in const object.

#include <iostream>


class Test
{
//    private:
    public:
        int a;
        mutable int b;
        Test() : a(4), b(6) {}
        void show() const;
};
void Test::show() const
{
    std::cout<<a<<" "<<b<<std::endl;    
}

int main()
{
    const Test t;
    t.show();
    t.b = 9;
    t.show();
}
