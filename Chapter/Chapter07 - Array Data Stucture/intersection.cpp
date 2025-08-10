#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
    int arr1[] = {4, 2, 1, 7};
    int arr2[] = {2, 3, 4, 1};

    unordered_set<int> s(arr2, arr2 + 4); // arr2 ko set me store kar rahe hain quick lookup ke liye

    cout << "Intersection: ";
    for(int i = 0; i < 4; i++)
    {
        if(s.find(arr1[i]) != s.end()) // agar element arr2 me hai
            cout << arr1[i] << " ";
    }
}
