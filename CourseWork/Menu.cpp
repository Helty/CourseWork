#include "Menu.h"

namespace
{
    bool isRus(unsigned char letter)
    {
        return ((letter >= 192 && letter <= 255) || letter == 168 || letter == 184) ? true : false;
    }
}

int Menu::GetVariant()
{
    int variant = 1;
    string str; // ������ ��� ���������� �������� ������
    getline(cin, str); // ��������� ������

    if (!str.empty()) {
        variant = stoi(str);
    }

    // ���� ���� �����������, �������� �� ���� � ������ ��������� ���
    while (variant < 1 or variant > 6)
    {
        cout << "�� ���������� ����. ���������� �����: "; // ������� ��������� �� ������
        getline(cin, str); // ��������� ������ ��������
        variant = stoi(str);
    }

    return variant;
}

void Menu::PrintMenu()
{
    system("cls"); // ������� �����
    cout << "��� �� ������ �������?" << endl;
    cout << "1. ����������� �����." << endl;
    cout << "2. ������������ �����." << endl;
    cout << "3. ����� �� ���������." << endl;
}

void Menu::PrintMenuTextToCrypt()
{
    system("cls");
    cout << "����� �������� ���������?" << endl;
    cout << "1. ������� ������������." << endl;
    cout << "2. ���� ��������." << endl;
    cout << "3. ����� �� ���������." << endl;
}

string Menu::GetTextFromUser()
{
    system("cls");
    string textFromUser;
    cout << "������� ����� ��� ����������: ";
    getline(cin, textFromUser);

    while (isRus(textFromUser[0]))
    {
        system("cls");
        cout << "������� ��������! ������� ����� ��� ����������: ";
        getline(cin, textFromUser);
    }
    return textFromUser;
}

std::string Menu::GetKeyFromUser()
{
    system("cls");
    string key;
    cout << "������� ���� ��� ����������: ";
    getline(cin, key);
    while (isRus(key[0])) {
        system("cls");
        cout << "������� ��������! ������� ���� ��� ����������: ";
        getline(cin, key);
    }
    return key;
}

int Menu::GetVariantCrypt()
{
    int variantCrypt; // ������ ��� ���������� �������� ������
    string str;
    getline(cin, str); // ��������� ������
    variantCrypt = stoi(str);

    while (variantCrypt != 1 and variantCrypt != 2 and variantCrypt != 3)
    {
        cout << "�� ���������� ����. ���������� �����: "; // ������� ��������� �� ������
        getline(cin, str); // ��������� ������ ��������
        variantCrypt = stoi(str);
    }

    return variantCrypt;
}
