#include <iostream>

class Person
{
public:
    Person(int age, int height)
    {
        mage = age;
        mheight = new int(height);
    }

    // Person(const Person &p)
    // {
    //     mage = p.mage;
    //     mheight = new int (*p.mheight);
    // }

    ~Person()
    {
        if (mheight != NULL)
        {
            delete mheight;
            mheight = NULL;
        }
        std::cout << "析构函数";
        
    }
    int mage;
    int *mheight;
};


int main()
{
    Person p1(19, 160);
    Person p2(p1);
    std::cout << p1.mheight;
    
    system("pause");
}