#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    stack<int> s2;

    // cout << "top = " << s.top();

    // while (!s.empty())
    // {
    //     cout << s.top() << endl;
    //     s.pop();
    // }
    // cout << endl;
    
    s2.swap(s);
    return 0;
}