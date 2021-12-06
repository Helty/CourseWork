#include <string>
#include <vector>

using namespace std;
#pragma once
class Permutation
{
private:
	vector<int> m_key;
	vector<int> StringToVectorIntTranslation(string);

public:
	void SetKey(vector<int> key);
	void SetKey(string key);

	string Encrypt(string);
	string Decrypt(string textDecrypt);
};

