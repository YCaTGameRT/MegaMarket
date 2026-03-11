#include "Sys.h"

//из программа
bool IsNumber(const std::string& str) {
	if (str.size() <= 0 || str.size() >= 10) {
		std::cout << "Некорректный ввод!\n";
		std::cout << "Ошибка длины числа От 1 до 9 цифр включительно!\n\n";
		Sleep(1500);
		return false;
	}
	for (size_t i = 0; i < str.size(); i++) {
		if (!std::isdigit(str[i])) {
			std::cout << "Некорректный ввод!\n";
			std::cout << "Введённые данные не являются число\n\n";
			Sleep(1500);
			return false;
		}
	}
	return true;
}
bool CheckLogin(const std::string& str) {
	for (size_t i = 0; i < userSize; i++) {
		if (str == loginArr[i]) {
			std::cout << "Такой пользователь существует!\n";
			Sleep(1500);
			return false;
		}
	}
	if (str.empty() || str.size() > 15) {
		std::cout << "Недопустимая длина логина. От 1 до 15\n";
		Sleep(1500);
		return false;
	}
	std::unordered_set<char> specialSymbols;
	for (char i = 'A'; i <= 'Z'; i++) {
		specialSymbols.insert(i);
	}
	for (char i = 'a'; i <= 'z'; i++) {
		specialSymbols.insert(i);
	}
	for (char symb : str) {
		if (!specialSymbols.count(symb)) {
			std::cout << "Некорректные символы в логине\n";
			Sleep(1500);
			return false;
		}
	}
	return true;
}
bool CheckPass(const std::string& str) {
	if (str.size() < 5 || str.size() > 40) {
		std::cout << "Недопустимая длина пароля. От 5 до 40\n";
		Sleep(1500);
		return false;
	}
	std::unordered_set<char> specialSymbols;
	std::unordered_set<char> passSymbols{ '!', '@', '#', '$', '%', '*', '&', '(', ')', '-', '_', '=', '+', '/', '?', '|', '\\', '\"', '\'', '.', ',', '<', '>', '~', '`', ':', ';', '{', '}', '[', ']' };
	int symbolCount = 0, maxSymbolCount = 3;
	for (char i = 'A'; i <= 'Z'; i++) {
		specialSymbols.insert(i);
	}
	for (char i = 'a'; i <= 'z'; i++) {
		specialSymbols.insert(i);
	}
	for (char symb : str) {
		if (passSymbols.count(symb)) {
			symbolCount++;
			if (symbolCount == maxSymbolCount) {
				return true;
			}
		}
	}
	std::cout << "Требуется минимум 3 спец. символа\n";
	Sleep(1500);
	return false;
}