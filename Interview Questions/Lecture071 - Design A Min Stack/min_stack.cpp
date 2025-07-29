#include<iostream>
#include<stack>
using namespace std;

class MinStack
{
    public:
        stack<pair<int, int>> s;

        void push(int val)
        {
            if(s.empty())
            {
                s.push({val, val});
            }
            else
            {
                int minVal = min(val, s.top().second);
                s.push({val, minVal});
            }
        }

        void pop()
        {
            s.pop();
        }

        int top()
        {
            return s.top().first;
        }

        int getMin()
        {
            return s.top().second;
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

    // time: O(1);
    //space: O(2*n);
    
    return 0;
}