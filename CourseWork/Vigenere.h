#include <string>
#include <algorithm>
#include <vector>
#include <map>


#pragma once
class Vigenere
{
private:
	std::string m_key;

public:
	void SetKey(std::string);

	std::string Encrypt(std::string);
	std::string Decrypt(std::string);
};

