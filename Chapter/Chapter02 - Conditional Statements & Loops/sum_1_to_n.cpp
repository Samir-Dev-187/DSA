#include<iostream>
using namespace std;

int main()
{
    int n,i=1,s = 0;
    cout << "Enter Number: ";
    cin >> n;

    // for(i=1; i<=n; i++){
    //     s += i;
    // }

    while (i<=n)
    {
        s += i;
        i++;
    }
    

    cout << s << endl;

    return 0;
}