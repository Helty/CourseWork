#include "Permutation.h"

void Permutation::SetKey(vector<int> key){
    this->m_key.resize(key.size());
    for (int i = 0; i < key.size(); i++)    {
        this->m_key[i] = key[i];
    }
}
void Permutation::SetKey(string key){
    Permutation::SetKey(StringToVectorIntTranslation(key));
}
vector<int> Permutation::StringToVectorIntTranslation(string key){
    std::vector<int> result;
    for (int i = 0; i < key.size(); i++)    {
        result.push_back(((int)key[i]) - 48);
    }
    return result;
}
string Permutation::Encrypt(string textEncrypt){
    if (textEncrypt == "" or (textEncrypt.length() % m_key.size() != 0)) return "";
    std::string result = "";
    for (int i = 0; i < textEncrypt.length(); i += (int)m_key.size()) {
        std::vector<char> transposition;
        transposition.resize(m_key.size());
        for (int j = 0; j < m_key.size(); j++) {
            transposition[m_key[j] - 1] = textEncrypt[i + j];
        }
        for (int j = 0; j < m_key.size(); j++) {
            result += transposition[j];
        }
    }
    return result;
}
string Permutation::Decrypt(string textDecrypt){
    if (textDecrypt == "" or (textDecrypt.length() % m_key.size() != 0)) return "";
    string result = "";
    for (int i = 0; i < textDecrypt.length(); i += (int)m_key.size()) {
        std::vector<char> transposition;
        transposition.resize(m_key.size());
        for (int j = 0; j < m_key.size(); j++) {
            transposition[j] = textDecrypt[i + m_key[j] - 1];
        }
        for (int j = 0; j < m_key.size(); j++) {
            result += transposition[j];
        }
    }
    return result;
}