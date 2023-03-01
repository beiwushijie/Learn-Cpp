#include <iostream>
#define MAX 1000
void ShowMenu();

struct Person
{
    std::string m_Name;
    int m_Sex;
    int m_Age;
    std::string m_Phone;
    std::string m_Addr;
};

struct Addressbooks
{
    struct Person personArry[MAX];
    int m_Size;
};

void addPerson(Addressbooks *abs);
void display(Addressbooks *abs);
int isExist(Addressbooks *abs, std::string name);
void deletPerson(Addressbooks *abs);
void findPerson(Addressbooks *abs);
void modifyPerson(Addressbooks *abs);
void cleanPerson(Addressbooks *abs);
int main()
{
    // 创建通讯录结构体变量
    Addressbooks abs;
    // 将通讯录中个数初始化为零
    abs.m_Size = 0;

    int select;
    while (true)
    {

        ShowMenu();
        std::cin >> select;

        switch (select)
        {
        case 1: /* 添加联系人 */
            addPerson(&abs);
            break;
        case 2: /* 显示联系人 */
            display(&abs);
            break;
        case 3: /* 删除联系人 */
            deletPerson(&abs);
            break;
        case 4: /* 查找联系人 */
            findPerson(&abs);
            break;
        case 5: /* 修改联系人 */
            modifyPerson(&abs);
            break;
        case 6: /* 清空联系人 */
            cleanPerson(&abs);
            break;
        case 0:
            std::cout << "欢迎下次使用" << std::endl;
            return 0;
        }
    }
}

// 菜单
void ShowMenu()
{
    std::cout << "***** 1. 添加联系人 *****" << std::endl;
    std::cout << "***** 2. 显示联系人 *****" << std::endl;
    std::cout << "***** 3. 删除联系人 *****" << std::endl;
    std::cout << "***** 4. 查找联系人 *****" << std::endl;
    std::cout << "***** 5. 修改联系人 *****" << std::endl;
    std::cout << "***** 6. 清空联系人 *****" << std::endl;
    std::cout << "***** 0. 退出通讯录 *****" << std::endl;
}

// 添加联系人
void addPerson(Addressbooks *abs)
{
    // 判断当前通讯录是否已满
    if (abs->m_Size == MAX)
    {
        std::cout << "当前通讯录已满，无法继续输入" << std::endl;
    }
    else
    {
        // 姓名
        std::string name;
        std::cout << "请输入姓名" << std::endl;
        std::cin >> name;
        abs->personArry[abs->m_Size].m_Name = name;

        // 性别
        int sex;
        while (true)
        {
            std::cout << "请输入性别，1为男性，2为女性" << std::endl;
            std::cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArry[abs->m_Size].m_Sex = sex;
                break;
            }
        }

        // 年龄
        int age;
        std::cout << "请输入年龄" << std::endl;
        std::cin >> age;
        abs->personArry[abs->m_Size].m_Age = age;

        // 电话
        std::string phone;
        std::cout << "请输入电话号码" << std::endl;
        std::cin >> phone;
        abs->personArry[abs->m_Size].m_Phone = phone;

        // 地址
        std::string addr;
        std::cout << "请输入地址" << std::endl;
        std::cin >> addr;
        abs->personArry[abs->m_Size].m_Addr = addr;

        // 计数器自增
        abs->m_Size++;

        // 添加成功
        std::cout << "添加成功" << std::endl;
        system("pause");
        system("cls");
    }
}

// 显示联系人
void display(Addressbooks *abs)
{
    if (abs->m_Size == 0)
    {
        std::cout << "当前联系人目录为空" << std::endl;
    }
    else
    {
        for (int i = 0; i != abs->m_Size; i++)
        {
            std::cout << "姓名: " << abs->personArry[i].m_Name << "\t";
            std::cout << "性别: " << (abs->personArry[i].m_Sex == 1 ? "男" : "女") << "\t";
            std::cout << "年龄: " << abs->personArry[i].m_Age << "\t";
            std::cout << "电话: " << abs->personArry[i].m_Phone << "\t\t";
            std::cout << "地址: " << abs->personArry[i].m_Addr << "\t" << std::endl;
        }
    }
    system("pause");
    system("cls");
}

// 检测联系人是否存在
int isExist(Addressbooks *abs, std::string name)
{
    for (int i = 0; i != abs->m_Size; i++)
    {
        if (name == abs->personArry[i].m_Name)
        {
            return i;
        }
    }
    return -1;
}

void deletPerson(Addressbooks *abs)
{
    std::string name;
    std::cout << "请输联系人的名称" << std::endl;
    std::cin >> name;
    int ret = isExist(abs, name);
    if (ret == -1)
    {
        std::cout << "查无此人" << std::endl;
    }
    else
    {
        if (ret == abs->m_Size)
        {
            abs->m_Size--;
            std::cout << "删除成功" << std::endl;
        }
        else
        {
            for (int i = ret; i < abs->m_Size - 1; i++)
            {
                abs->personArry[i] = abs->personArry[i + 1];
            }
            abs->m_Size--;
            std::cout << "删除成功" << std::endl;
        }
    }
    system("pause");
    system("cls");
}

void findPerson(Addressbooks *abs)
{
    std::string name;
    std::cout << "请输入要查找的联系人姓名" << std::endl;
    std::cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        std::cout << "姓名: " << abs->personArry[ret].m_Name << "\t";
        std::cout << "性别: " << (abs->personArry[ret].m_Sex == 1 ? "男" : "女") << "\t";
        std::cout << "年龄: " << abs->personArry[ret].m_Age << "\t";
        std::cout << "电话: " << abs->personArry[ret].m_Phone << "\t\t";
        std::cout << "地址: " << abs->personArry[ret].m_Addr << "\t" << std::endl;
    }
    else
    {
        std::cout << "查无此人" << std::endl;
    }
    system("pause");
    system("cls");
}

void modifyPerson(Addressbooks *abs)
{
    std::string name;
    std::cout << "请输入要查找的联系人姓名" << std::endl;
    std::cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        // 姓名
        std::string name;
        std::cout << "请输入姓名" << std::endl;
        std::cin >> name;
        abs->personArry[ret].m_Name = name;

        // 性别
        int sex;
        while (true)
        {
            std::cout << "请输入性别，1为男性，2为女性" << std::endl;
            std::cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArry[ret].m_Sex = sex;
                break;
            }
        }

        // 年龄
        int age;
        std::cout << "请输入年龄" << std::endl;
        std::cin >> age;
        abs->personArry[ret].m_Age = age;

        // 电话
        std::string phone;
        std::cout << "请输入电话号码" << std::endl;
        std::cin >> phone;
        abs->personArry[ret].m_Phone = phone;

        // 地址
        std::string addr;
        std::cout << "请输入地址" << std::endl;
        std::cin >> addr;
        abs->personArry[ret].m_Addr = addr;
    }
    else
    {
        std::cout << "查无此人" << std::endl;
    }
    system("pause");
    system("cls");
}

void cleanPerson(Addressbooks *abs)
{
    abs->m_Size = 0;
    std::cout << "联系人已清空" << std::endl;
    system("pause");
    system("cls");
}