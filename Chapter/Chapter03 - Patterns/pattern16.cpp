/*


*      *
**    ** 
***  *** 
******** 
******** 
***  *** 
**    ** 
*      *


*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter Number: ";
    cin >> n;

    // Upper half
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++) cout << "*";
        for(int sp=0; sp<2*(n-i); sp++) cout << " ";
        for(int k=0; k<=i; k++) cout << "*";
        cout << "\n";
    }

    // Lower half
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<=i; j++) cout << "*";
        for(int sp=0; sp<2*(n-i); sp++) cout << " ";
        for(int k=0; k<=i; k++) cout << "*";
        cout << "\n";
    }

    return 0;
}
