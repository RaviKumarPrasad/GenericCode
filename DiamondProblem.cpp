//Diamond problem in C++, 

#include <iostream>
using namespace std;

class A
{
public:
    void display()
        {
            cout<<"Display Method in A ";
        }
};
class B: virtual public A       //virtual -> To tell the compiler to create a single referene to avoid ambiguity
{
    public:
    void show()
        {
            cout<<"Show Method in B ";
        }
};
class C: virtual public A       //virtual -> To tell the compiler to create a single referene to avoid ambiguity
{
    void show()
        {
            cout<<"Show Method in B ";
        }
 
};
class D:public B,public C
{
 
};
int main()
{
    D o;
    o.display();
    return 0;
}
