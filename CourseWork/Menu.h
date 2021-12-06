#include <iostream>
#include <string>

using namespace std;
#pragma once
class Menu
{

public:
	enum class MainMenuItem : int
	{
		ENCRYPT_TEXT = 1,
		DECRYPT_TEXT,
		EXIT,
	};
	enum class MenuCryptChoise : int
	{
		PERMUTATION = 1,
		VIGENERE,
		EXIT,
	};

	static void GetChoice(MainMenuItem& menuItem);
	static void GetChoiceCrypt(MenuCryptChoise& choiceCrypt);

	static void PrintMainMenu();
	static void PrintMenuCryptChoise();

	static std::string GetTextFromUser();
	static std::string GetKeyFromUser();
};

