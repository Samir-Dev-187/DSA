#include<iostream>
#include<string>
using namespace std;

class Teacher
{
    private:
        double salary;

    public:
        // Teacher() //constructure (non-parameterize)
        // {
        //     dept = "Cybersecurity";
        //     cout << "Hi!! I am Constucture.. \n";
        // }

        Teacher(string n, string d, string s, double sal) //parameterize
        {
            name = n;
            dept = d;
            subject = s;
            salary = sal;
        }

        // properties/attributes
        string name;
        string dept;
        string subject;

        // methods/member function
        void changeDept(string newDept)
        {
            dept = newDept;
        }

        // //setter
        // void setSalary(double s)
        // {
        //     salary = s;
        // }
        // //getter
        // double getSalary()
        // {
        //     return salary;
        // }

        void getInfo()
        {
            cout << name << endl;
            cout << dept << endl;
            cout << subject << endl;
            cout << salary << endl;
        }
};

int main()
{
    Teacher t1("Samir", "Cybersecurity", "C++", 250000);
    t1.getInfo();
    
    // t1.name = "Samir";
    // t1.subject = "C++";

    // cout << t1.name << endl;
    // cout << t1.dept << endl;
    // t1.setSalary(25000);
    // cout << t1.getSalary() << endl;
    return 0;
}