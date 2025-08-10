#include<iostream>
using namespace std;

int main()
{
    // int a=10;
    // cout << int(&a) << endl;

    int a=25;
    int* ptr = &a;

    cout << ptr << endl;
    cout << &a << endl;
    cout << &ptr << endl;

    int* ptr1=NULL;
    cout << *ptr1 << endl;
    return 0;
}