
/*
const_cast<> ()

Basically this cast will help to remove the constantness of a variable.
Here in below example, we're doing const_cast of var x and then we're trying to change the value of var a. 
Output of this porgram will give you wrong value since var *x and a is pointing to same memory location due to compile time const evaluation 
but checking the value using gdb will give you correct output. Since its a wrong way to do this kind of type casting. So solution is remove 
the const from var a and use.

Good way to use this const_cast is in bottom of the code, 
suppose we made a variable const for any other function to use this varible, not to change the const variable (ex: 3rd party lib/fun)
*/

#include <iostream>

#if 0
int main()
{
    const int a = 29;
    //int a = 29;
    const int * x = &a;
    int * z = const_cast<int *> (x);
    *z = 23;
    std::cout<<*x;
    std::cout<<*z;
    std::cout<<a;
}
#endif 

int lib3rdParty(int * val)
{
    return (5*(*val));
}

int main()
{
    const int a = 29;
    const int * x = &a;
    std::cout<<lib3rdParty(const_cast<int *> (x));
}
