#include <iostream>

int *foo()
{
    int *data = new int[3];
    int a = 3, b=2, c=1;
    data[0] = a;
    data[1] = b;
    data[2] = c;

    return data;
}

int main()
{
    int *a;

    a = foo();

    std::cout << a[0] << a[1] << a[2];

    delete[] a;
    return 0;
}