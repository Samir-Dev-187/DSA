#include<iostream>
using namespace std;

class Person
{
    public:
    string name;
    int age;

    Person(string name, int age)
    {
        cout << "Parent Constuctor...\n";
        this->name = name;
        this->age = age;
    }

    virtual void hello()
    {
        cout << "Hello World\n";
    }

    ~Person()
    {
        cout << "Hi!! I am Parent Destuctor...\n";
    }
};

class Student : public Person
{
    public:
        int rollNo;

        Student(string name, int age, int rollNo) : Person(name, age)
        {
            this->rollNo = rollNo;
            cout << "Child Constuctor...\n";
        }

        ~Student()
        {
            cout << "Hi!! I am Student Destuctor...\n";
        }
        void getInfo()
        {
            cout << name << endl;
            cout << age << endl;
            cout << rollNo << endl;
        }

        void hello()
        {
        cout << "Hello From Child\n";
        }
};

int main()
{
    Student s1("Samir Shaw", 21, 1234);
    s1.getInfo();

    s1.hello();
    return 0;
}