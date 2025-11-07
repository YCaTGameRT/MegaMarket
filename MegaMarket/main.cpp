#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>

//Учётки
size_t userSize = 2;
std::string* loginArr = new std::string[userSize]{ "admin", "user" };
std::string* passArr = new std::string[userSize]{ "admin", "user" };
std::string userStatus[3]{ "Супер Администратор", "Администратор", "Сотрудник" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2] };

//Функции
void Start();
bool Login();
inline void Getline(std::string& str);
inline void Err(int time = 1500);

//Danger Zone!!!
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Start();

	delete[]loginArr, passArr, statusArr;

	return 0;
}

//Функции2
void Start() {
	std::cout << "Привет! Ты попал в MegaMarket!\n";
}
bool Login() {
	std::string login, pass;
	while (true) {
		std::cout << "Введите логин\n";
		Getline(login);
		std::cout << "Введите пароль\n";
		Getline(pass);
		if (login == "exit" && pass = "exit") {
			return false;
		}
		if (login == loginArr[0] && pass == passArr[0]) {
			std::cout << "Добро пожаловать, " << loginArr[0] << "\nВаш статус: " << statusArr[0] << "\n\n";
			return true;
		}
		for (size_t i = 1; i < userSize; i++) {
			if (login == loginArr[i] && pass == passArr[i]) {
				std::cout << "Добро пожаловать, " << loginArr[i] << "\nВаш статус: " << statusArr[i] << "\n\n";
				return true;
			}
		}
		Err();
	}
}
inline void Getline(std::string& str) {
	std::getline(std::cin, str, '\n');
}
inline void Err(int time = 1500) {
	std::cout << "Некорректный ввод!";
	Sleep(time);
	system("cls");
}