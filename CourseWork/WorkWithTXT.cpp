#include "WorkWithTXT.h"

DataArray WorkWithTXT::GetDataArrayFromTxt(string const& filePath)
{
	DataArray dataArrayTextFromTxt;

	ifstream file(filePath);
	string lineText;

	while (getline(file, lineText))
	{
		if (lineText == "") continue;
		dataArrayTextFromTxt.push_back(lineText);
	}
	file.close();
	return dataArrayTextFromTxt;
}

void WorkWithTXT::SetTextToTxt(string const& text, string filePath)
{
	ofstream file(filePath, ios::app);
	file.is_open() ? (file << text << endl) : throw logic_error("Ошибка записи данных");
}