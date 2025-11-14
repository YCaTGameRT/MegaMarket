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
void ShowStorage(int mode = 0);
void AddStorageItem();
void RemoveStorageItem();
void ChangePrice();
void ChangeStorage();
void AddNewItem();

//программа
void Start();
bool Login();
void ShowSuperAdminMenu();
bool IsNumber(const std::string& str);

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
void ShowStorage(int mode) {
	if (mode == 0) {
		std::cout << "ID\t" << std::left << std::setw(25) << "название товаров\t\tкол-во\t\tцена\n";
		for (size_t i = 0; i < storageSize; i++) {
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << countArr[i] << "\t\t" << priceArr[i] << "\n";
			system("pause");
			system("cls");
			std::cout << "\n\n";
		}
	}
	else if (mode == 1) {
		std::cout << "ID\t" << std::left << std::setw(25) << "название товаров\t\tкол-во\n";
		for (size_t i = 0; i < storageSize; i++) {
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << countArr[i] << "\n";
		}
	}
	else if (mode == 2) {
		std::cout << "ID\t" << std::left << std::setw(25) << "название товаров\t\tцена\n";
		for (size_t i = 0; i < storageSize; i++) {
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << priceArr[i] << "\n";
		}
	}
	else {
		std::cout << "StorageMode Error\n";
		std::invalid_argument("StorageMode Error");
	}
	std::cout << "\n\n";
}
void AddStorageItem() {
	std::string choose, chooseId, chooseCount;
	int id = 0;
	unsigned count = 0;
	while (true) {
		system("cls");
		ShowStorage(1);
		std::cout << "Введите ID товара или \"exit\" для выхода\n>>: ";
		Getline(chooseId);
		if (chooseId == "exit") {
			std::cout << "Отмена операции пополнения\n";
			Sleep(1500);
			break;
		}
		std::cout << "Введите кол-во товара для пополнения\n>>: ";
		Getline(chooseCount);
		if (IsNumber(chooseId) && IsNumber(chooseCount)) {
			id = std::stoi(chooseId) - 1;
			count = std::stoi(chooseCount);
			if (id < 0 || id > storageSize - 1 || count < 0 || count > 132) {
				std::cout << "Некорректный id или кол-во\nМаксимальное кол-во 132\n";
				Sleep(1500);
			}
			else {
				std::cout << std::left << std::setw(25) << nameArr[id] << "\t" << countArr[id] << " ---> " << countArr[id] + count << "\n\n";
				std::cout << "Подтвердить?\n1 - да\n2 - нет\n>>: ";
				Getline(choose);
				if (choose == "1") {
					countArr[id] += count;
					std::cout << "Товар успешно пополнен\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2") {
					std::cout << "Отмена пополнения товара\n";
					Sleep(1500);
					system("cls");
				}
				else {
					Err();
				}
			}
		}
	}
}
void RemoveStorageItem() {
	std::string choose, chooseId, chooseCount;
	int id = 0;
	unsigned count = 0;
	while (true) {
		system("cls");
		ShowStorage(1);
		std::cout << "Введите ID товара или \"exit\" для выхода\n>>: ";
		Getline(chooseId);
		if (chooseId == "exit") {
			std::cout << "Отмена операции списания\n";
			Sleep(1500);
			break;
		}
		std::cout << "Введите кол-во товара для списания\n>>: ";
		Getline(chooseCount);
		if (IsNumber(chooseId) && IsNumber(chooseCount)) {
			id = std::stoi(chooseId) - 1;
			count = std::stoi(chooseCount);
			if (id < 0 || id > storageSize - 1 || count < 0 || count > countArr[id]) {
				std::cout << "Некорректный id или кол-во\\n";
				Sleep(1500);
			}
			else {
				std::cout << std::left << std::setw(25) << nameArr[id] << "\t" << countArr[id] << " ---> " << countArr[id] + count << "\n\n";
				std::cout << "Подтвердить?\n1 - да\n2 - нет\n>>: ";
				Getline(choose);
				if (choose == "1") {
					countArr[id] -= count;
					std::cout << "Товар успешно списан\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2") {
					std::cout << "Отмена списания товара\n";
					Sleep(1500);
					system("cls");
				}
				else {
					Err();
				}
			}
		}
	}
}
void ChangePrice() {
	std::string choose, chooseId, newPrice;
	int id = 0;
	double price = 0.0;
	while (true) {
		system("cls");
		ShowStorage(2);
		std::cout << "Введите ID товара или \"exit\" для выхода\n>>: ";
		Getline(chooseId);
		if (chooseId == "exit") {
			std::cout << "Отмена операции изменения цены\n";
			Sleep(1500);
			break;
		}
		std::cout << "Введите новую цену\n>>: ";
		Getline(newPrice);
		if (IsNumber(chooseId) && IsNumber(newPrice)) {
			id = std::stoi(chooseId) - 1;
			price = std::stod(newPrice) + 0.0;
			if (id < 0 || id > storageSize - 1 || price < 0.0 || price > 9999999.99) {
				std::cout << "Некорректный id или кол-во\nМаксимальный ценник 9999999.99\n";
				Sleep(1500);
			}
			else {
				std::cout << std::left << std::setw(25) << nameArr[id] << "\t" << priceArr[id] << " ---> " << price << "\n\n";
				std::cout << "Подтвердить?\n1 - да\n2 - нет\n>>: ";
				Getline(choose);
				if (choose == "1") {
					priceArr[id] = price;
					std::cout << "Цена успешно изменена\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2") {
					std::cout << "Отмена изменения цены\n";
					Sleep(1500);
					system("cls");
				}
				else {
					Err();
				}
			}
		}
	}
}
void ChangeStorage() {
	std::string choose;
	while (true) {
		std::cout << "1 - добавить новый товар\n2 - изменить имя товара\n3 - удалить товар\n0 - выйти из редактора\n>>: ";
		Getline(choose);
		if (choose == "1") {
			AddNewItem();
		}
		else if (choose == "2") {
			
		}
		else if (choose == "3") {
			
		}
		else if (choose == "0") {
			break;
		}
		else {
			Err();
		}
	}
}
void AddNewItem() {
	std::string newName, newPrice, newCount, choose;
	double price = 0.0;
	unsigned int count = 0;
	bool exit = true;
	while (true) {
		while (true) {
			system("cls");
			std::cout << "Добавление нового товара!\n\nВведите \"exit\" для прекращения операции\nВведите название товара >>: ";
			Getline(newName);
			if (newName == "exit") {
				std::cout << "Операция добавления товара прервана!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (newName.size() <= 0 || newName.size() >= 60) {
				std::cout << "Ошибка имени. Максимальная длина 60 символов!\n";
				Sleep(1500); 
			}
			else {
				break;
			}
		}
		while (exit) {
			system("cls");
			std::cout << "Добавление нового товара!\n\nВведите \"exit\" для прекращения операции\nВведите кол-во товара >>: ";
			Getline(newCount);
			if (newCount == "exit") {
				std::cout << "Операция добавления товара прервана!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (IsNumber(newCount)) {
				count = std::stoi(newCount);
				if (count > 132) {
					std::cout << "Ошибка максимального размера товара. Не боле 132 едениц!";
					Sleep(1500);
				}
				else {
					break;
				}
			}
		}
		while (exit) {
			system("cls");
			std::cout << "Добавление нового товара!\n\nВведите \"exit\" для прекращения операции\nВведите цену товара >>: ";
			Getline(newPrice);
			if (newPrice == "exit") {
				std::cout << "Операция добавления товара прервана!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (IsNumber(newPrice)) {
				price = std::stod(newPrice);
				if (price > 9999999.99) {
					std::cout << "Ошибка максимальной цены товара. Не боле 9999999.99!";
					Sleep(1500);
				}
				else {
					break;
				}
			}
		}
		system("pause");
		while (exit) {
			std::cout << "Новый товар " << newName << "\nКол-во " << count << "\nЦена " << price << "\n\nПодтвердить?\n1 - да\n2 - нет\n>>: ";
			Getline(choose);
			if (choose == "1") {
				storageSize++;
				int* idArrTemp = new int[storageSize];
				std::string* nameArrTemp = new std::string[storageSize];
				unsigned int* countArrTemp = new unsigned int[storageSize];
				double* priceArrTemp = new double[storageSize];
				FillArr(idArrTemp, idArr, storageSize - 1);
				FillArr(nameArrTemp, nameArr, storageSize - 1);
				FillArr(countArrTemp, countArr, storageSize - 1);
				FillArr(priceArrTemp, priceArr, storageSize - 1);
				idArrTemp[storageSize - 1] = storageSize;
				nameArrTemp[storageSize - 1] = newName;
				countArrTemp[storageSize - 1] = count;
				priceArrTemp[storageSize - 1] = price;
				std::swap(idArr, idArrTemp);
				std::swap(nameArr, nameArrTemp);
				std::swap(countArr, countArrTemp);
				std::swap(priceArr, priceArrTemp);
				delete[]idArrTemp, nameArrTemp, countArrTemp, priceArrTemp;
				std::cout << "Везу товар...\n";
				Sleep(2000);
				std::cout << "Товар успешно добавлен";
				Sleep(1500);
			}
			else if (choose == "2") {
				std::cout << "Отмена\n\n";
				Sleep(1500);
			}
			else {
				Err();
			}
		}
		if (exit == false) {
			break;
		}
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
					ShowSuperAdminMenu();
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
		std::cout << "1 - начать продажу\n2 - показать склад\n3 - пополнить склад\n4 - списать товар\n5 - изменить цену\n6 - редактировать склад\n7 - редактировать персонал\n8 - отчет о прибыли\n0 - закрыть смену\n>>: ";
		Getline(choose);
		if (choose == "1") {

		}
		else if (choose == "2") {
			ShowStorage();
		}
		else if (choose == "3") {
			AddStorageItem();
		}
		else if (choose == "4") {
			RemoveStorageItem();
		}
		else if (choose == "5") {
			ChangePrice();
		}
		else if (choose == "6") {
			AddNewItem();
		}
		else if (choose == "7") {

		}
		else if (choose == "8") {

		}
		else if (choose == "0") {

		}
		else {
			Err();
		}
	}
}
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


template<typename Arr> void FillArr(Arr* dynamicArr, Arr* staticArr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		dynamicArr[i] = staticArr[i];
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