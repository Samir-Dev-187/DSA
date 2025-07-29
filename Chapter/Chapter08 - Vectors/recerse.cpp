#include<iostream>
#include<vector>
using namespace std;
void reverse(vector<int> vec);
int main()
{
    vector <int> vec = {1,2,3,4,5,6,7};
    
    reverse(vec);
    cout <<"\n";
}

void reverse(vector<int> vec)
{
    for(int i=vec.size()-1; i>=0; i--)
    {
        cout << vec[i] << " ";  
    }
}