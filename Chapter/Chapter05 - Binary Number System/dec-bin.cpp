#include<iostream>
using namespace std;

int decToBin(int decNum);

int main()
{
    int n;
    cout << "Enter Number To Convert Into Binary: ";
    cin >> n;
    cout << decToBin(n);
}

int decToBin(int decNum)
{
    int ans = 0, pow = 1;

    while (decNum>0)
    {
        int rem = decNum % 2;
        decNum /= 2;

        ans += (rem*pow);
        pow *= 10;
    }
    return ans;
}