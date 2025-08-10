#include<iostream>
#include<stack>
using namespace std;

class Solution
{
    public:
        bool isValid(string s)
        {
            stack<int> st;

            for(int i=0; i<s.size(); i++) //O(n)
            {
                if(s[i] == '(' || s[i] == '{' || s[i] == '[') //opening
                {
                    st.push(s[i]);
                }
                else //closing
                {
                    if(st.size() == 0)
                    {
                        return false;
                    }

                    if((st.top() == '(' && s[i] == ')') ||
                        (st.top() == '{' && s[i] == '}') ||
                        (st.top() == '[' && s[i] == ']'))
                        {
                            st.pop();
                        }
                    
                    else //no match
                    {
                        return false;
                    }
                }
            }

            return st.size() == 0;
        }
};

int main()
{
    Solution s1;
    string str = "[{()}]()";

    cout << s1.isValid(str) << endl;

    return 0;
}