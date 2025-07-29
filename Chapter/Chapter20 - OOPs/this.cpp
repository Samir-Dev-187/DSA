#include<iostream>
#include<string>
using namespace std;

class Teacher
{
    private:
        double salary;

    public:
        string name;
        string dept;
        string subject;

        Teacher(string name, string dept, string subject, double salary) //parameterize
        {
            this->name = name;
            this->dept = dept;
            this->subject = subject;
            this->salary = salary;
        }

        Teacher(Teacher &orgObj) //custom copy constucture
        {
            cout << "I am custom copy constucture... \n";

            this->name = orgObj.name;
            this->dept = orgObj.dept;
            this->subject = orgObj.subject;
            this->salary = orgObj.salary;
        }
        // methods/member function

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
    
    Teacher t2(t1); //defalult copy constucture
    t2.getInfo();

    Teacher t2(t1); //custom copy constucture
    t2.getInfo();

    return 0;
}