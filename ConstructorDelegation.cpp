

#include <iostream>

class Test
{
    private:    
        int a,b;
    public:
        Test()
        {
            a = 10;   
        }
        Test(int b) : Test()    //Constructor delegation
        {
            this->b = b;
        }
        void show() { std::cout<<"\na "<<a<<" b "<<b;}
};

int main()
{
    Test t(21);
    t.show();
}
