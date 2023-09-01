#include <iostream>

int * global;

void test(int * a)
{
    global = new int();
    global = a;
    std::cout << *global;
}

int main()
{
    int * a = new int();
    *a = 10;
    test(a);
    delete a;
    return 0;
}