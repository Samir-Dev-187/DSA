#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string str = "ABCDEFGH";
    
    // for(int i=str.length()-1; i>=0; i--)
    // {
    //     cout << str[i] << " ";
    // }

    // int st=0, end=str.length()-1;
    // while (st<end)
    // {
    //     swap(str[st++],str[end--]);
    // }
    // cout << str << endl;    

    reverse(str.begin(), str.end()); //iterators
    cout << str << endl;

    return 0;
}