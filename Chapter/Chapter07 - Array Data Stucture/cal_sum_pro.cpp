#include<iostream>
using namespace std;

void calSum(int arr[], int size);
void calProduct(int arr[], int size);

int main()
{
    int size;
    cout << "Enter Size: ";
    cin >> size;
    int arr[size];
    for(int i=0; i<size; i++)
    {
        cout << "Enter Number At Position " << i << " : ";
        cin >> arr[i];
    }
    calSum(arr,size);
    calProduct(arr,size);
}

void calSum(int arr[], int size)
{
    int s=0;
    for(int i=0; i<size; i++)
    {
        s += arr[i];
    }
    cout << "Sum: " << s;
}

void calProduct(int arr[], int size)
{
    int p=1;
    for(int i=0; i<size; i++)
    {
        p *= arr[i];
    }
    cout << "\nProduct: " << p;
}