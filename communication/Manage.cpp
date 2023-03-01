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
    // ����ͨѶ¼�ṹ�����
    Addressbooks abs;
    // ��ͨѶ¼�и�����ʼ��Ϊ��
    abs.m_Size = 0;

    int select;
    while (true)
    {

        ShowMenu();
        std::cin >> select;

        switch (select)
        {
        case 1: /* �����ϵ�� */
            addPerson(&abs);
            break;
        case 2: /* ��ʾ��ϵ�� */
            display(&abs);
            break;
        case 3: /* ɾ����ϵ�� */
            deletPerson(&abs);
            break;
        case 4: /* ������ϵ�� */
            findPerson(&abs);
            break;
        case 5: /* �޸���ϵ�� */
            modifyPerson(&abs);
            break;
        case 6: /* �����ϵ�� */
            cleanPerson(&abs);
            break;
        case 0:
            std::cout << "��ӭ�´�ʹ��" << std::endl;
            return 0;
        }
    }
}

// �˵�
void ShowMenu()
{
    std::cout << "***** 1. �����ϵ�� *****" << std::endl;
    std::cout << "***** 2. ��ʾ��ϵ�� *****" << std::endl;
    std::cout << "***** 3. ɾ����ϵ�� *****" << std::endl;
    std::cout << "***** 4. ������ϵ�� *****" << std::endl;
    std::cout << "***** 5. �޸���ϵ�� *****" << std::endl;
    std::cout << "***** 6. �����ϵ�� *****" << std::endl;
    std::cout << "***** 0. �˳�ͨѶ¼ *****" << std::endl;
}

// �����ϵ��
void addPerson(Addressbooks *abs)
{
    // �жϵ�ǰͨѶ¼�Ƿ�����
    if (abs->m_Size == MAX)
    {
        std::cout << "��ǰͨѶ¼�������޷���������" << std::endl;
    }
    else
    {
        // ����
        std::string name;
        std::cout << "����������" << std::endl;
        std::cin >> name;
        abs->personArry[abs->m_Size].m_Name = name;

        // �Ա�
        int sex;
        while (true)
        {
            std::cout << "�������Ա�1Ϊ���ԣ�2ΪŮ��" << std::endl;
            std::cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArry[abs->m_Size].m_Sex = sex;
                break;
            }
        }

        // ����
        int age;
        std::cout << "����������" << std::endl;
        std::cin >> age;
        abs->personArry[abs->m_Size].m_Age = age;

        // �绰
        std::string phone;
        std::cout << "������绰����" << std::endl;
        std::cin >> phone;
        abs->personArry[abs->m_Size].m_Phone = phone;

        // ��ַ
        std::string addr;
        std::cout << "�������ַ" << std::endl;
        std::cin >> addr;
        abs->personArry[abs->m_Size].m_Addr = addr;

        // ����������
        abs->m_Size++;

        // ��ӳɹ�
        std::cout << "��ӳɹ�" << std::endl;
        system("pause");
        system("cls");
    }
}

// ��ʾ��ϵ��
void display(Addressbooks *abs)
{
    if (abs->m_Size == 0)
    {
        std::cout << "��ǰ��ϵ��Ŀ¼Ϊ��" << std::endl;
    }
    else
    {
        for (int i = 0; i != abs->m_Size; i++)
        {
            std::cout << "����: " << abs->personArry[i].m_Name << "\t";
            std::cout << "�Ա�: " << (abs->personArry[i].m_Sex == 1 ? "��" : "Ů") << "\t";
            std::cout << "����: " << abs->personArry[i].m_Age << "\t";
            std::cout << "�绰: " << abs->personArry[i].m_Phone << "\t\t";
            std::cout << "��ַ: " << abs->personArry[i].m_Addr << "\t" << std::endl;
        }
    }
    system("pause");
    system("cls");
}

// �����ϵ���Ƿ����
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
    std::cout << "������ϵ�˵�����" << std::endl;
    std::cin >> name;
    int ret = isExist(abs, name);
    if (ret == -1)
    {
        std::cout << "���޴���" << std::endl;
    }
    else
    {
        if (ret == abs->m_Size)
        {
            abs->m_Size--;
            std::cout << "ɾ���ɹ�" << std::endl;
        }
        else
        {
            for (int i = ret; i < abs->m_Size - 1; i++)
            {
                abs->personArry[i] = abs->personArry[i + 1];
            }
            abs->m_Size--;
            std::cout << "ɾ���ɹ�" << std::endl;
        }
    }
    system("pause");
    system("cls");
}

void findPerson(Addressbooks *abs)
{
    std::string name;
    std::cout << "������Ҫ���ҵ���ϵ������" << std::endl;
    std::cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        std::cout << "����: " << abs->personArry[ret].m_Name << "\t";
        std::cout << "�Ա�: " << (abs->personArry[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
        std::cout << "����: " << abs->personArry[ret].m_Age << "\t";
        std::cout << "�绰: " << abs->personArry[ret].m_Phone << "\t\t";
        std::cout << "��ַ: " << abs->personArry[ret].m_Addr << "\t" << std::endl;
    }
    else
    {
        std::cout << "���޴���" << std::endl;
    }
    system("pause");
    system("cls");
}

void modifyPerson(Addressbooks *abs)
{
    std::string name;
    std::cout << "������Ҫ���ҵ���ϵ������" << std::endl;
    std::cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        // ����
        std::string name;
        std::cout << "����������" << std::endl;
        std::cin >> name;
        abs->personArry[ret].m_Name = name;

        // �Ա�
        int sex;
        while (true)
        {
            std::cout << "�������Ա�1Ϊ���ԣ�2ΪŮ��" << std::endl;
            std::cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArry[ret].m_Sex = sex;
                break;
            }
        }

        // ����
        int age;
        std::cout << "����������" << std::endl;
        std::cin >> age;
        abs->personArry[ret].m_Age = age;

        // �绰
        std::string phone;
        std::cout << "������绰����" << std::endl;
        std::cin >> phone;
        abs->personArry[ret].m_Phone = phone;

        // ��ַ
        std::string addr;
        std::cout << "�������ַ" << std::endl;
        std::cin >> addr;
        abs->personArry[ret].m_Addr = addr;
    }
    else
    {
        std::cout << "���޴���" << std::endl;
    }
    system("pause");
    system("cls");
}

void cleanPerson(Addressbooks *abs)
{
    abs->m_Size = 0;
    std::cout << "��ϵ�������" << std::endl;
    system("pause");
    system("cls");
}