#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);

    cout << "lower bound = " << *(s.lower_bound(4)) << endl;
    cout << "lower bound = " << *(s.upper_bound(4)) << endl;

    for(auto val : s)
    {
        cout << val << endl;
    }
}