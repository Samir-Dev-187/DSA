#include<iostream>
#include<vector>

using namespace std;

int main()
{
    // vector <int> vec = {1,2,3};
    // cout << vec[0] << endl;


    // vector <int> vec(5,0);
    // cout << vec[0] <<endl;
    // cout << vec[1] <<endl;
    // cout << vec[2] <<endl;
    // cout << vec[3] <<endl;
    // cout << vec[4] <<endl;
    // return 0;

    vector <char> vec = {'a','b','c','d','e'};
    for(char i: vec)
    {
        cout << i << endl;
    }
    return 0;

    //vector functions

    cout << vec.size();
    vec.push_back(25);
    vec.pop_back();
    vec.front();
    vec.back();
    vec.at(0);
}