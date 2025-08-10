#include<iostream>
#include<string>
using namespace std;

class Student
{
    public:
    string name;
    double *cgpaPtr;

    Student(string name, double cgpa)
    {
        this-> name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    Student(Student &obj)
    {
        this->name = obj.name;
        cgpaPtr = new double;
        *cgpaPtr = *obj.cgpaPtr;
    }

    //destucture
    ~Student()
    {
        cout << "Hi!! I delete Everything..";
        delete cgpaPtr;
    }
    void getInfo()
    {
        cout << name << endl;
        cout << *cgpaPtr << endl;
    }
};

int main()
{   
    Student s1("Samir Shaw", 8.9);
    s1.getInfo();
    return 0;
}