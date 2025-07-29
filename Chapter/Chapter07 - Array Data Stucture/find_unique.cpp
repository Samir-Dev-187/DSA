#include<iostream>
using namespace std;

void findUnique(int arr[], int size);

int main() 
{
    int size;
    cout << "Enter Size: ";
    cin >> size;
    int arr[size];

    for(int i = 0; i < size; i++) 
    {
        cout << "Enter Number At Position " << i << " : ";
        cin >> arr[i];
    }

    findUnique(arr, size);
}

void findUnique(int arr[], int size) 
{
    for(int i = 0; i < size; i++) 
    {
        bool isUnique = true;
        for(int j = 0; j < size; j++) {
            if(i != j && arr[i] == arr[j]) 
            {
                isUnique = false;
                break;
            }
        }
        if(isUnique) 
        {
            cout << arr[i] << " ";
        }
    }
}
