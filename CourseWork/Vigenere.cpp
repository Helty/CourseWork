#include "Vigenere.h"
using namespace std;
namespace{
    map<char, int> m_characters = {        
        {'A', 1},{'B', 2},{'C', 3},{'D', 4},{'E', 5},{'F', 6},{'G', 7},{'H', 8},{'I', 9},{'J', 10},{'K', 11},{'L', 12},{'M', 13},{'N', 14},{'O', 15},
        {'P', 16},{'Q', 17},{'R', 18},{'S', 19},{'T', 20},{'U', 21},{'V', 22},{'W', 23},{'X', 24},{'Y', 25},{'Z', 26},{' ', 27},{'1', 28},{'2', 29},{'3', 30},
        {'4', 31},{'5', 32},{'6', 33},{'7', 34},{'8', 35},{'9', 36},{'0', 37},{'a', 38},{'b', 39},{'c', 40},{'d', 41},{'e', 42},{'f', 43},{'g', 44},{'h', 45},
        {'i', 46},{'j', 47},{'k', 48},{'l', 49},{'m', 50},{'n', 51},{'o', 52},{'p', 53},{'q', 54},{'r', 55},{'s', 56},{'t', 57},{'u', 58},{'v', 59},{'w', 60},
        {'x', 61},{'y', 62},{'z', 63}};
    map<int, char> m_charactersInv = {
        {1,'A'},{2,'B'},{3,'C'},{4,'D'},{5,'E'},{6,'F'},{7,'G'},{8,'H'},{9,'I'},{10,'J'},{11,'K'},{12,'L'},{13,'M'},{14,'N'},{15,'O'},
        {16,'P'},{17,'Q'},{18,'R'},{19,'S'},{20,'T'},{21,'U'},{22,'V'},{23,'W'},{24,'X'},{25,'Y'},{26,'Z'},{27,' '},{28,'1'},{29,'2'},{30,'3'},
        {31,'4'},{32,'5'},{33,'6'},{34,'7'},{35,'8'},{36,'9'},{37,'0'},{38,'a'},{39,'b'},{40,'c'},{41,'d'},{42,'e'},{43,'f'},{44,'g'},{45,'h'},
        {46,'i'},{47,'j'},{48,'k'},{49,'l'},{50,'m'},{51,'n'},{52,'o'},{53,'p'},{54,'q'},{55,'r'},{56,'s'},{57,'t'},{58,'u'},{59,'v'},{60,'w'},
        {61,'x'},{62,'y'},{63,'z'}};
    int m_N = (int)m_characters.size();
}
void Vigenere::SetKey(string key){
    m_key = key;
}

string Vigenere::Encrypt(string text){
    if (text == "") return "";
    string result = "";
    int keywordIndex = 0;
    for (const auto& symbol : text){
        auto first = m_characters[symbol];
        auto secont = m_characters[m_key[keywordIndex]];
        auto trid = first + secont;
        int c = trid % m_N;
        result += m_charactersInv[c];
        keywordIndex++;
        if ((keywordIndex + 1) == m_key.size()) keywordIndex = 0;
    }
    return result;
}

string Vigenere::Decrypt(string encryptText){
    if (encryptText == "") return "";
    string result = "";
    int keywordIndex = 0;
    for (const auto& symbol : encryptText)    {
        auto first = m_characters[symbol];
        auto secont = m_characters[m_key[keywordIndex]];
        int p = (first + m_N - secont) % m_N;
        result += m_charactersInv[p];
        keywordIndex++;
        if ((keywordIndex + 1) == m_key.size()) keywordIndex = 0;
    }
    return result;
}
