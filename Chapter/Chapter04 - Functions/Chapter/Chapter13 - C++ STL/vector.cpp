#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec5;
    
    vector<int> vec(3,10);

    vector<int> vec1(vec);

    cout << vec.size();

    vec.push_back(3);
    vec.pop_back();
    vec.push_back(8);
    vec.push_back(7);
    vec.push_back(6);
    vec.emplace_back();

    vec.at(3);
    cout << vec.front();
    cout << vec.back();
}   