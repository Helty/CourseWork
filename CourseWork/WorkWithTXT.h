#include <string>
#include <vector>
#include <fstream> 
#include <iostream>

using namespace std;
using DataArray = vector<string>;

#pragma once
class WorkWithTXT
{
public:

	inline static const string decryptTextFile = "D:\\Проекты Visual Studio\\CourseWork\\CourseWork\\txtFiles\\decrypt_text.txt";
	inline static const string encryptTextFile = "D:\\Проекты Visual Studio\\CourseWork\\CourseWork\\txtFiles\\encrypt_text.txt";
	inline static const string permutationKeyFile = "D:\\Проекты Visual Studio\\CourseWork\\CourseWork\\txtFiles\\permutation_keys.txt";
	inline static const string vigenereKeyFile = "D:\\Проекты Visual Studio\\CourseWork\\CourseWork\\txtFiles\\vigenere_keys.txt";

	static DataArray GetDataArrayFromTxt(std::string const& filePath);
	static void SetTextToTxt(std::string const& text, std::string filePath);
};

