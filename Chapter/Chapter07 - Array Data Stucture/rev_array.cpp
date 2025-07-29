#include<iostream>
using namespace std;

// int main()
// {
//     int size;
//     cout << "Enter Size: ";
//     cin >> size;

//     int arr[size];
//     for(int i=0; i<size; i++)
//     {cout << "Enter Number At Index " <<i<<" : "; 
//         cin >> arr[i];
//     };
    
//     for(int i=size-1; i>-1; i--)
//     {
//         cout << arr[i];
//     }
// }

// Using 2 Pointer Apporch



// Function prototype (declaration before main)
void reverArray(int arr[], int sz);

int main()
{
    int arr[] = {4, 2, 7, 8, 1, 2, 5};
    int sz = 7; // Calculate size dynamically

    reverArray(arr, sz); // Now recognized by compiler

    for (int i = 0; i < sz; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Function definition after main
void reverArray(int arr[], int sz)
{
    int start = 0, end = sz - 1;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
