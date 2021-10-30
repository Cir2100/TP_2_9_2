#include "UsersInput.h"
#include "task.h"
#include <iostream>
#include <Windows.h>

using namespace std;

string readFile(ifstream& input) {
	string s = "";
	string tmpS;
	while (getline(input, tmpS))
		s.append(tmpS).append("\n");
	return s;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int countFindSuggestion;
	inputData("������� ���������� ���� � �����������: ", countFindSuggestion, 0, INT32_MAX);

	string filename;
	processInputNameOfInputFile(filename);
	ifstream input(filename);
	cout << "��������� �����������:\n" << findSuggestoins(readFile(input), countFindSuggestion);
	input.close();
}