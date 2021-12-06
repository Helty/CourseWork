#include "Menu.h"

namespace
{
    bool isRus(unsigned char letter){
        return ((letter >= 192 && letter <= 255) || letter == 168 || letter == 184) ? true : false;
    }
}

void Menu::GetChoice(MainMenuItem& choice)
{
    string userChoice;
    getline(cin, userChoice);
    if (!userChoice.empty()) choice = (MainMenuItem)(stoi(userChoice));

    while (choice != MainMenuItem::ENCRYPT_TEXT and choice != MainMenuItem::DECRYPT_TEXT and choice != MainMenuItem::EXIT) {
        cout << "�� ���������� ����. ���������� �����: ";
        getline(cin, userChoice);
        choice = (MainMenuItem)(stoi(userChoice));
    }
}
void Menu::PrintMainMenu()
{
    system("cls"); // ������� �����
    cout << "��� �� ������ �������?" << endl;
    cout << "1. ����������� �����." << endl;
    cout << "2. ������������ �����." << endl;
    cout << "3. ����� �� ���������." << endl;
}
void Menu::PrintMenuCryptChoise()
{
    system("cls");
    cout << "����� �������� ���������?" << endl;
    cout << "1. ������� ������������." << endl;
    cout << "2. ���� ��������." << endl;
    cout << "3. ����� � ������� ����." << endl;
}
string Menu::GetTextFromUser(){
    system("cls");
    string textFromUser;
    cout << "������� ����� ��� ����������: ";
    getline(cin, textFromUser);
    while (isRus(textFromUser[0]))    {
        system("cls");
        cout << "������� ��������! ������� ����� ��� ����������: ";
        getline(cin, textFromUser);
    }
    return textFromUser;
}
std::string Menu::GetKeyFromUser(){
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
void Menu::GetChoiceCrypt(MenuCryptChoise& choiceCrypt)
{
    string userChoiceCrypt;
    getline(cin, userChoiceCrypt);
    choiceCrypt = (MenuCryptChoise)(stoi(userChoiceCrypt));
    while (choiceCrypt != MenuCryptChoise::PERMUTATION and choiceCrypt != MenuCryptChoise::VIGENERE and choiceCrypt != MenuCryptChoise::EXIT)
    {
        cout << "�� ���������� ����. ���������� �����: ";
        getline(cin, userChoiceCrypt);
        choiceCrypt = (MenuCryptChoise)(stoi(userChoiceCrypt));
    }
}
