#include<iostream>
#include<stack>
using namespace std;

class MinStack
{
    public:
        stack<long long int> s;
        long long int minVal;

        void push(int val)
        {
           if(s.empty())
           {
                s.push(val);
                minVal = val;
           }
           else
           {
                if(val < minVal)
                {
                    s.push((long long)2*val - minVal);
                    minVal = val;
                }
                else
                {
                    s.push(val);
                }
           }
        }

        void pop()
        {
            if(s.top()<minVal)
            {
                minVal = 2*minVal - s.top();
            }
        }

        int top()
        {
            if(s.top() < minVal)
            {
                return minVal;
            }
            return s.top();
        }

        int getMin()
        {
            return minVal;
        }
};

int main()
{
    MinStack m1;
    m1.push(2);
    m1.push(-1);
    m1.push(0);
    m1.push(-5);
    m1.push(5);
    
    cout << m1.getMin() << endl;
    cout << m1.top() << endl;

    m1.pop();
    m1.pop();
    cout << m1.getMin() << endl;
    return 0;
}