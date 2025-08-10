#include<iostream>
#include<queue>
using namespace std;

class MyStack
{
    public:
        queue<int> q1;
        queue<int> q2;

        MyStack()
        {

        }

        void push(int x) //O(n)
        {
            while (!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }

            q1.push(x);

            while (!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
            
            
        }

        int pop() //O(1)
        {
            int ans = q1.front();
            q1.pop();
            return ans;
        }

        int top() //O(1)
        {
            return q1.front();
        }

        bool empty() //O(1)
        {
            return q1.empty();
        }
};

int main()
{
    MyStack m1;
    m1.push(1);
    m1.push(2);
    m1.push(3);
    m1.push(4);
    m1.push(5);

    cout << m1.top() << endl;
    cout << m1.empty() << endl;

    while (!m1.empty())
    {
        cout << m1.top() << " ";
        m1.pop();
    }
    cout << endl;
    
    return 0;
}