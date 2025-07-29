#include<iostream>
#include<string>
using namespace std;

class ABC
{
    public:
        ABC()
        {
            cout << "Constuctor" << endl;
        }

        ~ABC()
        {
            cout << "Destuctor" << endl;
        }
};

int main()
{
    if(true)
    {
        static ABC obj;
    }
    cout << "End Of Main Function" << endl;

    return 0;
}