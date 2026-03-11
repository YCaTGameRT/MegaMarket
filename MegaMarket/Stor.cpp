#include "Stor.h"

void CreateStorage() {
	const int staticSize = 10;
	int id[staticSize]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::string name[staticSize]{ "Апельсины 1кг", "Яблоки 1кг", "Молоко 1шт", "Хлеб 1шт", "Пылесос 1шт", "Тарелки 1шт", "Туалетная бумага 1уп", "Отбеливатель 1шт", "Ручки 1шт", "Карандаши 1шт" };
	unsigned int count[staticSize]{ 42, 15, 73, 62, 844, 14, 52, 252, 51, 99 };
	double price[staticSize]{ 129.99, 339.99, 49.99, 59.99, 3259.99, 99.99, 159.99, 299.99, 5.99, 6.99 };
	if (staticStorageCreated) {
		delete[]idArr;
		delete[]nameArr;
		delete[]countArr;
		delete[]priceArr;
		staticStorageCreated = false;
	}
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
void CreateNewStorage() {
	CreateStorage();
	for (size_t i = 0; i < 10; i++) {
		DeleteNewStorageItems(i);
	}
	AddNewItem();
	std::cout << "Новый склад готов!\n\n";
	ShowStorage();
	system("cls");
}
void ShowStorage(int mode) {
	if (mode == 0) {
		std::cout << "ID\t" << std::left << std::setw(25) << "название товаров\t\tкол-во\t\tцена\n";
		for (size_t i = 0; i < storageSize; i++) {
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << countArr[i] << "\t\t" << priceArr[i] << "\n";
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
	else if (mode == 3) {
		std::cout << "ID\t" << std::left << std::setw(25) << "название товаров\n";
		for (size_t i = 0; i < storageSize; i++) {
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\n";
		}
	}
	else {
		std::cout << "StorageMode Error\n";
	}
	system("pause");
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
		else if (choose == "2" && storageSize > 0) {
			ChangeName();
		}
		else if (choose == "3" && storageSize > 0) {
			DeleteItem();
		}
		else if (choose == "0") {
			system("cls");
			break;
		}
		else {
			if (storageSize <= 0) {
				std::cout << "Склад пустой!\n";
			}
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
				delete[]idArrTemp;
				delete[]nameArrTemp;
				delete[]countArrTemp;
				delete[]priceArrTemp;
				std::cout << "Товар успешно добавлен!\n";
				Sleep(1500);
				break;
			}
			else if (choose == "2") {
				std::cout << "Отмена\n\n";
				Sleep(1500);
				break;
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
void ChangeName() {
	std::string newName, choose, chooseId;
	unsigned int id = 0;
	while (true) {
		system("cls");
		ShowStorage(3);
		std::cout << "Введите ID товара или \"exit\" для выхода\n>>: ";
		Getline(chooseId);
		if (chooseId == "exit") {
			std::cout << "Отмена операции изменения цены\n";
			Sleep(1500);
			break;
		}
		std::cout << "Введите новое название товара\n>>: ";
		Getline(newName);
		if (newName.size() <= 0 || newName.size() >= 60) {
			std::cout << "Ошибка имени. Максимальная длина 60 символов!\n";
			Sleep(1500);
		}
		else if (IsNumber(chooseId)) {
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > storageSize - 1) {
				std::cout << "Ошибка ID!\n";
				Sleep(1500);
			}
			else {
				std::cout << std::left << std::setw(25) << nameArr[id] << "\t" << priceArr[id] << " ---> " << newName << "\n\n";
				std::cout << "Подтвердить?\n1 - да\n2 - нет\n>>: ";
				Getline(choose);
				if (choose == "1") {
					nameArr[id] = newName;
					std::cout << "Смена имени завершена\n";
					Sleep(1500);
					break;
				}
				else if (choose == "2") {
					std::cout << "Отмена операции\n";
					Sleep(1500);
				}
				else {
					Err();
				}
			}
		}
	}
}
void DeleteItem() {
	std::string chooseId, choose;
	unsigned int id = 0;
	while (true) {
		system("cls");
		ShowStorage(3);
		std::cout << "Введите ID товара для удаления или \"exit\" для выхода\n>>: ";
		Getline(chooseId);
		if (chooseId == "exit") {
			std::cout << "Отмена операции удаления\n";
			Sleep(1500);
			break;
		}
		if (IsNumber(chooseId)) {
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > storageSize - 1) {
				std::cout << "Ошибка ID!\n";
				Sleep(1500);
			}
			else {
				std::cout << "Удаляемый товар: " << std::left << std::setw(25) << nameArr[id] << "\nПодтвердить?\n1 - да\n2 - нет\n>>: ";
				Getline(choose);
				if (choose == "1") {
					storageSize--;
					int* idArrTemp = new int[storageSize];
					std::string* nameArrTemp = new std::string[storageSize];
					unsigned int* countArrTemp = new unsigned int[storageSize];
					double* priceArrTemp = new double[storageSize];
					for (size_t i = 0, c = 0; i < storageSize; i++, c++) {
						if (id == c) {
							c++;
						}
						idArrTemp[i] = i + 1;
						nameArrTemp[i] = nameArr[c];
						countArrTemp[i] = countArr[c];
						priceArrTemp[i] = priceArr[c];
					}
					std::swap(idArr, idArrTemp);
					std::swap(nameArr, nameArrTemp);
					std::swap(countArr, countArrTemp);
					std::swap(priceArr, priceArrTemp);
					delete[]idArrTemp;
					delete[]nameArrTemp;
					delete[]countArrTemp;
					delete[]priceArrTemp;
					std::cout << "Удаление завершено\n";
					Sleep(1500);
					break;
				}
				else if (choose == "2") {
					std::cout << "Отмена операции удаления!\n";
					Sleep(1500);
				}
				else {
					Err();
				}
			}
		}
	}
}
void DeleteNewStorageItems(int id) {
	storageSize--;
	int* idArrTemp = new int[storageSize];
	std::string* nameArrTemp = new std::string[storageSize];
	unsigned int* countArrTemp = new unsigned int[storageSize];
	double* priceArrTemp = new double[storageSize];
	for (size_t i = 0, c = 0; i < storageSize; i++, c++) {
		if (id == c) {
			c++;
		}
		idArrTemp[i] = i + 1;
		nameArrTemp[i] = nameArr[c];
		countArrTemp[i] = countArr[c];
		priceArrTemp[i] = priceArr[c];
	}
	std::swap(idArr, idArrTemp);
	std::swap(nameArr, nameArrTemp);
	std::swap(countArr, countArrTemp);
	std::swap(priceArr, priceArrTemp);
	delete[]idArrTemp;
	delete[]nameArrTemp;
	delete[]countArrTemp;
	delete[]priceArrTemp;
}