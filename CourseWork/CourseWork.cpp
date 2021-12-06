#include <iostream>
#include "Windows.h"
#include "WorkWithTXT.h"
#include "Vigenere.h"
#include "Permutation.h"
#include "Menu.h"
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Menu::MainMenuItem choice;
    Menu::MenuCryptChoise choiceCrypt;
    do
    {
        Menu::PrintMainMenu();
        Menu::GetChoice(choice);

        if (choice == Menu::MainMenuItem::ENCRYPT_TEXT){
            Menu::PrintMenuCryptChoise();
            Menu::GetChoiceCrypt(choiceCrypt);
            if (choiceCrypt == Menu::MenuCryptChoise::PERMUTATION) {
                Permutation permutation;
                string textDecrypt = Menu::GetTextFromUser();
                string key = Menu::GetKeyFromUser();
                permutation.SetKey(key);
                string textEncrypt = permutation.Encrypt(textDecrypt);
                try {
                    WorkWithTXT::SetTextToTxt(key, WorkWithTXT::permutationKeyFile);
                    WorkWithTXT::SetTextToTxt(textEncrypt, WorkWithTXT::encryptTextFile);
                    WorkWithTXT::SetTextToTxt(textDecrypt, WorkWithTXT::decryptTextFile);
                }
                catch (const std::exception& error)
                {
                    cerr << error.what() << endl;
                }
            }
            else if (choiceCrypt == Menu::MenuCryptChoise::VIGENERE) {
                Vigenere vigenere;
                string textDecrypt = Menu::GetTextFromUser();
                string key = Menu::GetKeyFromUser();
                vigenere.SetKey(key);
                string textEncrypt = vigenere.Encrypt(textDecrypt);

                try {
                    WorkWithTXT::SetTextToTxt(key, WorkWithTXT::vigenereKeyFile);
                    WorkWithTXT::SetTextToTxt(textEncrypt, WorkWithTXT::encryptTextFile);
                    WorkWithTXT::SetTextToTxt(textDecrypt, WorkWithTXT::decryptTextFile);
                }
                catch (const std::exception& error)
                {
                    cerr << error.what() << endl;
                }
            }
            else if (choiceCrypt == Menu::MenuCryptChoise::EXIT) {
                continue;
            }
        }
        else if (choice == Menu::MainMenuItem::DECRYPT_TEXT) {
            system("cls");
            Vigenere vigenere;
            Permutation permutation;            
            for (auto encryptText : WorkWithTXT::GetDataArrayFromTxt(WorkWithTXT::encryptTextFile)) {
                for (auto permutationKey : WorkWithTXT::GetDataArrayFromTxt(WorkWithTXT::permutationKeyFile)) {
                    permutation.SetKey(permutationKey);
                    string decryptText = permutation.Decrypt(encryptText);
                    for (auto decryptTextTXT : WorkWithTXT::GetDataArrayFromTxt(WorkWithTXT::decryptTextFile)) {
                        if (decryptText == decryptTextTXT) {
                            cout << "Есть совпадение: " << endl;
                            cout << "Зашифрованный текст: " << encryptText << endl;
                            cout << "Расшифрованный текст: " << decryptText << endl;
                            cout << "Ключ: " << permutationKey << endl;
                            cout << "Тип шифрования: перестановка." << endl << endl;
                            break;
                        }
                        else {
                            continue;
                        }
                    }
                }
                for (auto vigenereKey : WorkWithTXT::GetDataArrayFromTxt(WorkWithTXT::vigenereKeyFile)) {
                    vigenere.SetKey(vigenereKey);
                    string decryptText = vigenere.Decrypt(encryptText);
                    for (auto decryptTextTXT : WorkWithTXT::GetDataArrayFromTxt(WorkWithTXT::decryptTextFile)) {
                        if (decryptText == decryptTextTXT) {
                            cout << "Есть совпадение: " << endl;
                            cout << "Зашифрованный текст: " << encryptText << endl;
                            cout << "Расшифрованный текст: " << decryptText << endl;
                            cout << "Ключ: " << vigenereKey << endl;
                            cout << "Тип шифрования: Виженер." << endl << endl;
                            break;
                        }
                        else 
                        {
                            continue;
                        }
                    }
                }
            }
            system("PAUSE");
        }
        else if (choice == Menu::MainMenuItem::EXIT) {
            break;
        }
    } while (TRUE);
}
