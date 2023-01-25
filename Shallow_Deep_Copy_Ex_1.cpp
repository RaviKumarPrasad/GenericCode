

#include <iostream>

class Test
{
    private:    
            int *a;
    public:
            Test()  {}
            Test(int val)
            {
                *a = val;
            }         
            Test(const Test & obj)      //check with and without reference(*)
            {
                a = new int;
                *a = *(obj.a);
            } 
            void show() { std::cout<<"\n a "<<*a; }
            void changeA(int val) { *a = val; }
};

int main()
{
    Test t1(22);
    t1.show();
    Test t2(t1);
    t2.show();

    t1.changeA(33);
    t1.show();
    t2.show();

    Test t3;
    t3 = t1;
    t1.changeA(44);
    t1.show();
    t2.show();
    t3.show();
    
    Test &t4 = t2;
    t2.changeA(66);
    t2.show();
    t4.show();
    t1.show();
    t3.show();
}
