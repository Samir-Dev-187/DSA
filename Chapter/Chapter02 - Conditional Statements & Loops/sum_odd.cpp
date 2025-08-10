#include <iostream>
using namespace std;

int main()
{
    int n,sum = 0,i;
    cout << "Enter Number: ";
    cin >> n;
    
    for(i=1; i<=n; i++){
        if(i % 2 != 0){
            sum += i;
        }
    }

    cout << sum << endl;

    return 0;
}