/*Linear Search*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector <int> vec = {1,2,9,7,5,8,10,6};
    int find=8;
    
    for(int i=0; i<vec.size(); i++)
    {
        if (vec[i]==find)
        {
            cout << "Item Found At Index: " << i;
            break;
        }
        
    }
}