#include<iostream>
#include<vector>
#include<string>
#include<algorithm> 
using namespace std;

int compress(vector<char> &chars)
{
    int n=chars.size();
    int idx=0;

    for(int i=0; i<n; i++)
    {
        char ch=chars[i];
        int count=0;

        while (i<n && chars[i]==ch)
        {
            count++; 
            i++;
        }

        if(count == 1)
        {
            chars[idx++] = ch;
        }
        else
        {
            chars[idx++]=ch;
            string str=to_string(count);
            for(char dig : str)
            {
                chars[idx++] = dig;
            }
        }
        i--;
    }
    chars.resize(idx);
    return idx;
}

int main()
{
    char c_chars[] = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    vector<char> chars(c_chars, c_chars + sizeof(c_chars) / sizeof(c_chars[0]));

    int newLength = compress(chars);
    cout << newLength << endl;

    for(char ch : chars)
    {
        cout << ch;
    }

    return 0;
}