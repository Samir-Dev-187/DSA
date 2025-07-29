#include<iostream>
using namespace std;

int main()
{
    pair <string, int> p = {"Samir", 18};
    cout << p.first << endl;
    cout << p.second << endl;

    pair <int, pair<char, int>> s = {1,{'d',7}};
    cout << s.first << endl;
    cout << s.second.first << endl;
    cout << s.second.second << endl;
}