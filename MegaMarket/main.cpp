#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>

//учётки
size_t userSize = 2;
std::string* loginArr = new std::string[userSize]{ "admin", "user" };
std::string* passArr = new std::string[userSize]{ "admin", "user" };
std::string userStatus[3]{ "Супер Администратор", "Администратор", "Сотрудник" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2] };
std::string currentStatus;

//склад
size_t storageSize = 0;
bool staticStorageCreated = false;
int* idArr;
std::string* nameArr;
unsigned int* countArr;
double* priceArr;
void CreateStorage();
void ShowStorage();

//программа
void Start();
bool Login();
void ShowSuperAdminMenu();

//система
template<typename Arr> void FillArr(Arr* dynamicArr, Arr* staticArr, size_t size);
inline void Getline(std::string& str);
inline void Err(int time = 1500);

//Danger Zone!!!
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Start();

	delete[]loginArr, passArr, statusArr;
	if (staticStorageCreated) {
		delete[]idArr, nameArr, countArr, priceArr;
	}

	return 0;
}

//функции2
void CreateStorage() {
	const int staticSize = 10;
	int id[staticSize]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::string name[staticSize]{ "Апельсины", "Яблоки", "Молоко", "Хлеб", "Пылесос", "Тарелки", "Туалетная бумага", "Отбеливатель", "Ручки", "Карандаши" };
	unsigned int count[staticSize]{ 42, 15, 73, 62, 844, 14, 52, 252, 51, 99 };
	double price[staticSize]{ 129.99, 339.99, 49.99, 59.99, 3259.99, 99.99, 159.99, 299.99, 5.99, 6.99 };
	storageSize = staticSize;
	idArr = new int[storageSize];
	nameArr = new std::string[storageSize];
	countArr = new unsigned int[storageSize];
	priceArr = new double[storageSize];
	staticStorageCreated = true;
	FillArr(idArr, id, storageSize);
	FillArr(nameArr, name, storageSize);
	FillArr(countArr, count, storageSize);
	FillArr(priceArr, price, storageSize);
}
void ShowStorage() {
	std::cout << "ID\t" << std::left << std::setw(25) << "название товаров\t\tкол-во\t\tцена\n";
	for (size_t i = 0; i < storageSize; i++) {
		std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << countArr[i] << "\t\t" << priceArr[i] << "\n";
	}
}
template<typename Arr> void FillArr(Arr* dynamicArr, Arr* staticArr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		dynamicArr[i] = staticArr[i];
	}
}
void Start() {
	std::string choose;
	std::cout << "Привет! Ты попал в MegaMarket!\n\n";
	if (Login()) {
		if (currentStatus == userStatus[0]) {
			while (true) {
				std::cout << "Выберите склад:\n1 - готовый\n2 - создать новый\n>>: ";
				Getline(choose);
				if (choose == "1") {
					CreateStorage();
					break;
				}
				else if (choose == "2") {
					//новый склад с нуля
					break;
				}
				else {
					Err();
				}
			}
			//создание склада/нового склада и открытие магазина
		}
		else if (currentStatus == userStatus[1]) {
			CreateStorage();
			//создание склада и открытие магазина
		}
		else if (currentStatus == userStatus[2]) {
			CreateStorage();
			//создание склада и открытие магазина
		}
	}
	else {
		system("cls");
		std::cout << "Завершение работы магазина";
	}
}
bool Login() {
	std::string login, pass;
	while (true) {
		std::cout << "Введите логин\n>>: ";
		Getline(login);
		std::cout << "Введите пароль\n>>: ";
		Getline(pass);
		if (login == "exit" && pass == "exit") {
			currentStatus = "";
			return false;
		}
		if (login == loginArr[0] && pass == passArr[0]) {
			std::cout << "\nДобро пожаловать, " << loginArr[0] << "\nВаш статус: " << statusArr[0] << "\n\n";
			currentStatus = statusArr[0];
			return true;
		}
		for (size_t i = 1; i < userSize; i++) {
			if (login == loginArr[i] && pass == passArr[i]) {
				std::cout << "\nДобро пожаловать, " << loginArr[i] << "\nВаш статус: " << statusArr[i] << "\n\n";
				currentStatus = statusArr[i];
				return true;
			}
		}
		Err(1500);
	}
}
void ShowSuperAdminMenu() {
	std::string choose;
	while (true) {
		system("cls");
		std::cout << "1 - начать продажу\n2 - показать склад\n3 - пополнить склад\n4 - списать товар\n5 - изменить цену\n6 - редактировать склад\n7 - редактировать персонал\n8 - отчет о прибыли\n0 - закрвть смену\n>>: ";
		Getline(choose);
	}
}
inline void Getline(std::string& str) {
	std::getline(std::cin, str, '\n');
}
inline void Err(int time) {
	std::cout << "Некорректный ввод!";
	Sleep(time);
	system("cls");
}

/*
std::string name[staticSize]{
		"Апельсины 1кг", "Яблоки 1кг", "Молоко 1л", "Хлеб 1шт",
		"Пылесос 1шт",
		"Тарелки 1шт",
		"Туалетная бумага 1уп",
		"Отбеливатель 1л",
		"Ручки 1шт", "Карандаши 1шт"
	};
*/