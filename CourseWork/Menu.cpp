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
        cout << "Не правильный ввод. Попробуйте снова: ";
        getline(cin, userChoice);
        choice = (MainMenuItem)(stoi(userChoice));
    }
}
void Menu::PrintMainMenu()
{
    system("cls"); // очищаем экран
    cout << "Что вы хотите сделать?" << endl;
    cout << "1. Зашифровать текст." << endl;
    cout << "2. Расшифровать текст." << endl;
    cout << "3. Выход из программы." << endl;
}
void Menu::PrintMenuCryptChoise()
{
    system("cls");
    cout << "Каким способом шифровать?" << endl;
    cout << "1. Двойная перестановка." << endl;
    cout << "2. Шифр Виженера." << endl;
    cout << "3. Выйти в главное меню." << endl;
}
string Menu::GetTextFromUser(){
    system("cls");
    string textFromUser;
    cout << "Введите текст для шифрования: ";
    getline(cin, textFromUser);
    while (isRus(textFromUser[0]))    {
        system("cls");
        cout << "Вводите латиницу! Введите текст для шифрования: ";
        getline(cin, textFromUser);
    }
    return textFromUser;
}
std::string Menu::GetKeyFromUser(){
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
void Menu::GetChoiceCrypt(MenuCryptChoise& choiceCrypt)
{
    string userChoiceCrypt;
    getline(cin, userChoiceCrypt);
    choiceCrypt = (MenuCryptChoise)(stoi(userChoiceCrypt));
    while (choiceCrypt != MenuCryptChoise::PERMUTATION and choiceCrypt != MenuCryptChoise::VIGENERE and choiceCrypt != MenuCryptChoise::EXIT)
    {
        cout << "Не правильный ввод. Попробуйте снова: ";
        getline(cin, userChoiceCrypt);
        choiceCrypt = (MenuCryptChoise)(stoi(userChoiceCrypt));
    }
}
