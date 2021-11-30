#include <string>
#include <vector>
#include <fstream> 
#include <iostream>

#pragma once
class WorkWithTXT
{
public:
	static std::vector<std::string> GetVectorKeyPermutationFromTXT();
	static std::vector<std::string> GetVectorKeyVigenereFromTXT();
	static std::vector<std::string> GetVectorEncryptTextFromTXT();
	static std::vector<std::string> GetVectorDecryptTextFromTXT();

	static bool setPermutationKeyToTXT(std::string);
	static bool setEncryptTextToTXT(std::string);
	static bool setDecryptTextToTXT(std::string);
	static bool setVigenereKeyToTXT(std::string);
};

