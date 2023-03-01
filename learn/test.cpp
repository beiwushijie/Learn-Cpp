#include <iostream>
#include <string>
void CopyVal(struct Teacher Tarry[],int len);
void prininfo(struct Teacher Tarry[], int len);
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
    std::srand((unsigned int) time(NULL));
    struct Teacher Tarry[3];
    int len = sizeof(Tarry)/sizeof(Tarry[0]);
    CopyVal(Tarry , len);
    prininfo(Tarry, len);
}

void CopyVal(struct Teacher Tarry[],int len)
{
    std::string suffix = "ABCDE";
    for (int i = 0; i < len; i++ )
    {
        Tarry[i].name = "Teacher";
        Tarry[i].name += suffix[i];
        for (int j = 0; j < 5; j++)
        {
            Tarry[i].stu[j].name = "Student" + suffix[j];
            // Tarry[i].stu[j].name += suffix[j];
            Tarry[i].stu[j].score = std::rand() % 61 + 40;
        }
        
    }
}

void prininfo(struct Teacher Tarry[], int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << "教师的姓名： " << Tarry[i].name << std::endl;
        for (int j = 0; j < 5; j++)
        {
            std::cout << "\t学生的姓名： " << Tarry[i].stu[j].name <<std::endl;
            std::cout << "\t学生的成绩： " << Tarry[i].stu[j].score <<std::endl;
        }
        
    }
    
}