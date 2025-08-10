#include<iostream>
using namespace std;

void fibonacci(int n)  
{
    int a = 0, b = 1, next;
    
    for(int i = 2; i < n; i++)  // 0 aur 1 toh pehle se print ho chuka hai
    {
        next = a + b;
        cout << next << " ";
        a = b;   // Previous value update kar raha hai
        b = next;
    }
}

int main()
{
    int n;
    cout << "Enter Number: ";
    cin >> n;
    cout << "0 1 ";  
    fibonacci(n);  // Correct function call
}
