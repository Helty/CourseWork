#include <iostream>
#include <cassert>
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

    Menu menu;
    int variant;

    do
    {
        WorkWithTXT workWithTXT;
        menu.PrintMenu();
        variant = menu.GetVariant();

        if (variant == 1)
        {
            menu.PrintMenuTextToCrypt();
            int variantCrypt = menu.GetVariantCrypt();

            if (variantCrypt == 1)
            {
                //Объявить экземпляр класса.
                Permutation permutation;

                //попросите пользователя ввести текст для шифрования.

                string textDecrypt = menu.GetTextFromUser();

                //попросите ввести ключ для шифрования или взять из уже существующих из файла key.txt

                string key = menu.GetKeyFromUser();

                permutation.SetKey(key);

                //зашифровать методом text_encrypt = doublePermutation.encrypt(text,key)

                string textEncrypt = permutation.Encrypt(textDecrypt);

                //всю информацию записать в txt файлы.
                assert(workWithTXT.setPermutationKeyToTXT(key) == true);
                assert(workWithTXT.setEncryptTextToTXT(textEncrypt) == true);
                assert(workWithTXT.setDecryptTextToTXT(textDecrypt) == true);
            }
            else if (variantCrypt == 2)
            {
                //создать экземпляр класса шифра виженера.
                Vigenere vigenere;

                //попросите пользователя ввести текст для шифрования.

                string textDecrypt = menu.GetTextFromUser();

                //попросите ввести ключ для шифрования

                string key = menu.GetKeyFromUser();

                vigenere.SetKey(key);

                //зашифровать методом text_encrypt = vigenere.encrypt(text) и результат сохранить в text_encrypt.txt

                string textEncrypt = vigenere.Encrypt(textDecrypt);

                //всю информацию записать в txt файлы.
                assert(workWithTXT.setVigenereKeyToTXT(key) == true);
                assert(workWithTXT.setDecryptTextToTXT(textDecrypt) == true);
                assert(workWithTXT.setEncryptTextToTXT(textEncrypt) == true);
            }
            else if (variantCrypt == 3)
            {
                continue;
            }
        }
        else if (variant == 2) {

            //здесь должна быть логика расшифровки

            //создаём два экземпляра классов (permutation и vigenere)
            system("cls");
            Vigenere vigenere;
            Permutation permutation;

            //Пройтись по всем зашифрованным текстам в encrypt_text.txt
            
            for (auto encryptText : workWithTXT.GetVectorEncryptTextFromTXT())
            {
                for (auto permutationKey : workWithTXT.GetVectorKeyPermutationFromTXT())
                {
                    permutation.SetKey(permutationKey);

                    string decryptText = permutation.Decrypt(encryptText);

                    for (auto decryptTextTXT : workWithTXT.GetVectorDecryptTextFromTXT())
                    {
                        if (decryptText == decryptTextTXT)
                        {
                            cout << "Есть совпадение: " << endl;
                            cout << "Зашифрованный текст: " << encryptText << endl;
                            cout << "Расшифрованный текст: " << decryptText << endl;
                            cout << "Ключ: " << permutationKey << endl;
                            cout << "Тип шифрования: перестановка." << endl << endl;
                            goto nextEncryptText;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }

                for (auto vigenereKey : workWithTXT.GetVectorKeyVigenereFromTXT())
                {
                    vigenere.SetKey(vigenereKey);

                    string decryptText = vigenere.Decrypt(encryptText);

                    for (auto decryptTextTXT : workWithTXT.GetVectorDecryptTextFromTXT())
                    {
                        if (decryptText == decryptTextTXT)
                        {
                            cout << "Есть совпадение: " << endl;
                            cout << "Зашифрованный текст: " << encryptText << endl;
                            cout << "Расшифрованный текст: " << decryptText << endl;
                            cout << "Ключ: " << vigenereKey << endl;
                            cout << "Тип шифрования: Виженер." << endl << endl;
                            goto nextEncryptText;


                        }
                        else
                        {
                            continue;
                        }
                    }
                }

            nextEncryptText:
                continue;
            }
            system("PAUSE");
        }
        else if (variant == 3)
        {
            continue;
        }

    } while (variant != 3);

}
