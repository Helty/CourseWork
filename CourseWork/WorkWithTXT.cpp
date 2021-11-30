#include "WorkWithTXT.h"


std::vector<std::string> WorkWithTXT::GetVectorKeyPermutationFromTXT()
{
	std::vector<std::string> vectorKeyPermutationTXT;
	std::ifstream file("D:\\Проекты Visual Studio\\CourseWork\\CourseWork\\txtFiles\\permutation_keys.txt");
	std::string line;

	while (getline(file, line))
	{
		if (line == "")
		{
			continue;
		}
		vectorKeyPermutationTXT.push_back(line);
	}
	file.close();
	return vectorKeyPermutationTXT;
}

std::vector<std::string> WorkWithTXT::GetVectorKeyVigenereFromTXT()
{
	std::vector<std::string> vectorKeyFromTXT;
	std::ifstream file("D:\\Проекты Visual Studio\\CourseWork\\CourseWork\\txtFiles\\vigenere_keys.txt");
	std::string line;

	while (getline(file, line))
	{
		if (line == "")
		{
			continue;
		}
		vectorKeyFromTXT.push_back(line);
	}
	file.close();

	return vectorKeyFromTXT;
}

std::vector<std::string> WorkWithTXT::GetVectorEncryptTextFromTXT()
{
	std::vector<std::string> vectorEncryptTextFromTXT;
	std::ifstream file("D:\\Проекты Visual Studio\\CourseWork\\CourseWork\\txtFiles\\encrypt_text.txt");
	std::string line;

	while (getline(file, line))
	{
		if (line == "")
		{
			continue;
		}
		vectorEncryptTextFromTXT.push_back(line);
	}
	file.close();

	return vectorEncryptTextFromTXT;
}

std::vector<std::string> WorkWithTXT::GetVectorDecryptTextFromTXT()
{
	std::vector<std::string> vectorEncryptTextFromTXT;
	std::ifstream file("D:\\Проекты Visual Studio\\CourseWork\\CourseWork\\txtFiles\\decrypt_text.txt");
	std::string line;

	while (getline(file, line))
	{
		if (line == "")
		{
			continue;
		}
		vectorEncryptTextFromTXT.push_back(line);
	}
	file.close();
	return vectorEncryptTextFromTXT;
}


bool WorkWithTXT::setDecryptTextToTXT(std::string decryptText)
{
	std::ofstream decryptTextTXT("D:\\Проекты Visual Studio\\CourseWork\\CourseWork\\txtFiles\\decrypt_text.txt", std::ios::app);
	if (decryptTextTXT.is_open())
	{
		decryptTextTXT << decryptText << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool WorkWithTXT::setPermutationKeyToTXT(std::string permutationKey)
{
	std::ofstream decryptTextTXT("D:\\Проекты Visual Studio\\CourseWork\\CourseWork\\txtFiles\\permutation_keys.txt", std::ios::app);
	if (decryptTextTXT.is_open())
	{
		decryptTextTXT << permutationKey << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool WorkWithTXT::setVigenereKeyToTXT(std::string vigenereKey)
{
	std::ofstream decryptTextTXT("D:\\Проекты Visual Studio\\CourseWork\\CourseWork\\txtFiles\\vigenere_keys.txt", std::ios::app);

	if (decryptTextTXT.is_open())
	{
		decryptTextTXT << vigenereKey << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool WorkWithTXT::setEncryptTextToTXT(std::string encryptText)
{
	std::ofstream decryptTextTXT("D:\\Проекты Visual Studio\\CourseWork\\CourseWork\\txtFiles\\encrypt_text.txt", std::ios::app);
	if (decryptTextTXT.is_open())
	{
		decryptTextTXT << encryptText << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}