#include <iostream>
#include <string>

struct Student
{
    std::string name;
    int score;
};

struct Teacher
{
    std::string name;
    Student stu[5];
};

int main()
{

    std::string q = "qwer";
    std::string a;
    a = "sdfs" + q[1];
    std::cout << typeid("sdfs").name();
    // Teacher ta;
    // ta.stu[1].name = "qwer" + q[1];
    // std::cout << ta.stu[1].name;
}