#include<iostream>
using namespace std;

int binToDec(int binNum);

int main()
{
    int n;
    cout << "Enter Number to contert into Binary: ";
    cin >> n;
    cout << binToDec(n);
}

int binToDec(int binNum)
{
    int ans = 0, pow = 1;

    while(binNum>0)
    {
        int rem = binNum %10;
        ans += rem*pow;

        binNum /= 10;
        pow *=2;
    }

    return ans;
}