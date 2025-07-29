#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> list = {1,2,3,4};

    // list.push_back(7);
    // list.push_front(0);
    // for(int l : list)
    // {
    //     cout << l << " ";
    // }
    
    list.pop_back();
    list.pop_front();
    for(int l : list)
    {
        cout << l << " ";
    }
}