#include<iostream>
#include<stack>
using namespace std;

class MyQueue
{
    public:
        stack<int> s1;
        stack<int> s2;
        MyQueue()
        {

        }

        void push(int x)
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);

            while (!s2.empty()) 
            {
                s1.push(s2.top());
                s2.pop();
            }
            
        }

        int pop()
        {
            int ans = s1.top();
            s1.pop();
            return ans;
        }

        int peek()
        {
            return s1.top();
        }

        bool empty()
        {
            return s1.empty();
        }
};

int main()
{
    MyQueue m1;
    m1.push(1);
    m1.push(2);
    m1.push(3);
    m1.push(4);
    m1.push(5);

    cout << m1.peek() << endl;
    cout << m1.empty() << endl;

    while (!m1.empty())
    {
        cout << m1.peek() << " ";
        m1.pop();
    }
    cout << endl;

    return 0;
}