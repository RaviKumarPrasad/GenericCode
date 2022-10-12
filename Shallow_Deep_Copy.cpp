

#include <iostream>

class T
{
    private :
        int * a;
    public :
        T()  { a = new int; }
        T(T &obj)   //copy cons
        {
            a = new int;    //deep copy
            *a = *(obj.a);
        }
        inline void show() { std::cout<<*a<<std::endl; }
        inline void setA(int val) { *a = val; }
};

int main()
{
    T t;
    t.setA(7);
    t.show();
    
    //T t1=t;   //call copy cons
    T t1;       //assign t to t1 and do shallow copy
    t1 = t;
    //T t1(t);  //call copy cons
    t1.show();

    t.setA(9);
    t.show();
    t1.show();
}
