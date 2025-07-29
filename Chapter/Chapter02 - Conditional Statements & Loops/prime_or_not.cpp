#include<iostream>
using namespace std;

int main()
{
    int n;
    int found;
    cout << "Enter Number: ";
    cin >> n;

    for(int i=2; i<=(n-1);i++){
        if(n%i != 0){
            found = 1;
        }
        else if(n%i == 0){
            found = 0;
            break;
        }
    }

    if(found == 1){
        cout << "Prime Number";
    }
    else{
        cout << "Non Prime Number";
    }
}