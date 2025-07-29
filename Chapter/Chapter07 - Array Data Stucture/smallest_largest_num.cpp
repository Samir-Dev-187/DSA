#include<iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter Size: ";
    cin >> size;
    int arry[size];
    int p;
    for(int i=0; i<size; i++)
    {
        cout << "Enter Number at position " << i << ": ";
        cin >> arry[i];
    }

    int sml = INT8_MAX;
    for(int i=0; i<size; i++)
    {
        if(arry[i] < sml){
            sml = arry[i];
            p=i;
        }
    }
    cout << "Smallest: " << sml << "    Position: " << p;

    int lar = INT8_MIN;
    for(int i=0; i<size; i++)
    {
        if(arry[i]>lar){
            lar = arry[i];
            p=i;
        }
    }
    cout << "\nLargest: " << lar << "   Position: " << p; 
}