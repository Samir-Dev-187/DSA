#include<iostream>
using namespace std;

class CircularQueue
{
    int* arr;
    int curSize, cap;
    int f, r;

    public:
        CircularQueue(int size)
        {
            cap = size;
            arr = new int[cap];
            curSize = 0;
            f = 0;
            r = -1;
        }

        void push(int data) //O(1)
        {
            if(curSize == cap)
            {
                cout << "CQ is FULL \n";
                return;
            }

            r = (r+1) % cap;
            arr[r] = data;
            curSize++;
        }

        void pop() //O(1)
        {
            if(empty())
            {
                cout << "CQ is EMPTY \n";
                return;
            }

            f = (f+1) % cap;
            curSize--;
        }

        int front() //O(1)
        {
            if(empty())
            {
                cout << "CQ is EMPTY \n";
                return -1;
            }

            return arr[f];
        }

        bool empty() //O(1)
        {
            return curSize == 0;
        }

        void printCQ()
        {
            for(int i=0; i<cap; ++i)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main()
{
    CircularQueue cq(4);

    cq.push(1);
    cq.push(8);
    cq.push(3);
    cq.push(5);
    cq.pop();
    cq.push(9);

    cq.printCQ();
    
    return 0;
}