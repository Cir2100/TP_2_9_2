#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream input("text.txt");

	string s;
	getline(input, s);

	input.close();
}