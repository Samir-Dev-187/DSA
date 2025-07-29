#include<iostream>
using namespace std;

int main()
{
    char ch;
    cout << "Enter Charecter: ";
    cin >> ch;

    if(isupper(ch)){
        cout << "Uppercase";
    }
    else if(int(ch) >= 97 && int(ch) <= 122){
        cout << "Lowercase";
    }
    else{
        cout << "Invalid Input!!";
    }

    return 0;
}