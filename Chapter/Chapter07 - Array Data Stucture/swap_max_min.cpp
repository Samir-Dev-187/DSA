#include<iostream>
#include<climits> // INT_MAX aur INT_MIN ke liye
using namespace std;

void swapMaxMin(int arr[], int size) {
    int minIndex = 0, maxIndex = 0;
    int min = INT_MAX, max = INT_MIN; // Sahi initialization

    // Min & Max index find karna ek hi loop me
    for(int i = 0; i < size; i++) {
        if(arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
        if(arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }

    // Swap min & max
    swap(arr[minIndex], arr[maxIndex]);

    // Print updated array
    cout << "Updated array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {4, 2, 9, 6, 1, 5, 8, 16, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    swapMaxMin(arr, size);
    return 0;
}
