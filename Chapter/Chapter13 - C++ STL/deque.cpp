#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> deq = {1,2,3,4};
    
    deq.pop_back();
    deq.pop_front();
    for(int d : deq)
    {
        cout << d << " ";
    }
}