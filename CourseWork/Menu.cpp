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
    string str; // строка для считывания введённых данных
    getline(cin, str); // считываем строку

    if (!str.empty()) {
        variant = stoi(str);
    }

    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (variant < 1 or variant > 6)
    {
        cout << "Не правильный ввод. Попробуйте снова: "; // выводим сообщение об ошибке
        getline(cin, str); // считываем строку повторно
        variant = stoi(str);
    }

    return variant;
}

void Menu::PrintMenu()
{
    system("cls"); // очищаем экран
    cout << "Что вы хотите сделать?" << endl;
    cout << "1. Зашифровать текст." << endl;
    cout << "2. Расшифровать текст." << endl;
    cout << "3. Выход из программы." << endl;
}

void Menu::PrintMenuTextToCrypt()
{
    system("cls");
    cout << "Каким способом шифровать?" << endl;
    cout << "1. Двойная перестановка." << endl;
    cout << "2. Шифр Виженера." << endl;
    cout << "3. Выход из программы." << endl;
}

string Menu::GetTextFromUser()
{
    system("cls");
    string textFromUser;
    cout << "Введите текст для шифрования: ";
    getline(cin, textFromUser);

    while (isRus(textFromUser[0]))
    {
        system("cls");
        cout << "Вводите латиницу! Введите текст для шифрования: ";
        getline(cin, textFromUser);
    }
    return textFromUser;
}

std::string Menu::GetKeyFromUser()
{
    system("cls");
    string key;
    cout << "Введите ключ для шифрования: ";
    getline(cin, key);
    while (isRus(key[0])) {
        system("cls");
        cout << "Вводите латиницу! Введите ключ для шифрования: ";
        getline(cin, key);
    }
    return key;
}

int Menu::GetVariantCrypt()
{
    int variantCrypt; // строка для считывания введённых данных
    string str;
    getline(cin, str); // считываем строку
    variantCrypt = stoi(str);

    while (variantCrypt != 1 and variantCrypt != 2 and variantCrypt != 3)
    {
        cout << "Не правильный ввод. Попробуйте снова: "; // выводим сообщение об ошибке
        getline(cin, str); // считываем строку повторно
        variantCrypt = stoi(str);
    }

    return variantCrypt;
}
