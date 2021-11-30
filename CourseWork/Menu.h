#include <iostream>
#include <string>

using namespace std;
#pragma once
class Menu
{

public:
	int GetVariant();
	int GetVariantCrypt();
	void PrintMenu();
	void PrintMenuTextToCrypt();
	std::string GetTextFromUser();
	std::string GetKeyFromUser();
};

