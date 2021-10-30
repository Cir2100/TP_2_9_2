#pragma once
#include <iostream>
#include <fstream>
#include <string>

template <typename T>
T processingInput(T minInput, T maxInput);
template <typename T>
void inputData(std::string help, T& data, T minValue, T maxValue);
bool processInputNameOfInputFile(std::string& filename);

template <typename T>
T processingInput(T minInput, T maxInput) {
	while (true)
	{
		T method;
		std::cin >> method;
		if (std::cin.fail() || method < minInput || method > maxInput)
		{
			std::cin.clear();
			std::cout << "Неверный ввод.\nВведите повторно: ";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			std::cin.clear();
			return method;
		}
		std::cin.ignore(32767, '\n');
	}
}

template <typename T>
void inputData(std::string help, T& data, T minValue, T maxValue) {
	std::cout << help;
	data = processingInput(minValue, maxValue);
}
