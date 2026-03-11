#include "Prog.h"

void Start() {
	std::string choose;
	while (true) {
		if (Login()) {
			if (currentStatus == userStatus[0]) {
				while (true) {
					std::cout << "Выберите склад:\n1 - готовый\n2 - создать новый\n>>: ";
					Getline(choose);
					if (choose == "1") {
						if (staticStorageCreated == false) {
							CreateStorage();
						}
						system("cls");
						ShowSuperAdminMenu();
						break;
					}
					else if (choose == "2") {
						CreateNewStorage();
						ShowSuperAdminMenu();
						break;
					}
					else {
						Err();
					}
				}
				//создание склада/нового склада и открытие магазина
			}
			else if (currentStatus == userStatus[1]) {
				if (staticStorageCreated == false) {
					CreateStorage();
				}
				system("cls");
				ShowAdminMenu();
			}
			else if (currentStatus == userStatus[2]) {
				if (staticStorageCreated == false) {
					CreateStorage();
				}
				system("cls");
				ShowUserMenu();
			}
		}
		else {
			system("cls");
			std::cout << "Введите пароль супер администратора для закрытия смены\n>>: \\";
			Getline(choose);
			if (choose == passArr[0]) {
				system("cls");
				std::cout << "Прибыль за смену: " << cashIncome + bankIncome << " рублей\n";
				Sleep(1500);
				std::cout << "Завершение работы магазина\n";
				Sleep(2000);
				break;
			}
			else {
				Err();
			}
		}
	}
}
bool Login() {
	std::string login, pass;
	std::cout << "Привет! Ты попал в MegaMarket!\n\n";
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
				currentId = userIdArr[i];
				Sleep(1500);
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
		if (choose == "1" && storageSize > 0) {
			Selling();
		}
		else if (choose == "2" && storageSize > 0) {
			ShowStorage();
		}
		else if (choose == "3" && storageSize > 0) {
			AddStorageItem();
		}
		else if (choose == "4" && storageSize > 0) {
			RemoveStorageItem();
		}
		else if (choose == "5" && storageSize > 0) {
			ChangePrice();
		}
		else if (choose == "6") {
			ChangeStorage();
		}
		else if (choose == "7") {
			ChangeUsers();
		}
		else if (choose == "8") {
			ShowIncome();
		}
		else if (choose == "0") {
			if (LogOut()) {
				break;
			}
		}
		else {
			if (storageSize <= 0) {
				std::cout << "Склад пустой!\n";
			}
			Err();
		}
	}
}
void ShowAdminMenu() {
	std::string choose;
	while (true) {
		std::cout << "1 - начать продажу\n2 - показать склад\n3 - пополнить склад\n4 - списать товар\n5 - редактировать склад\n6 - редактировать персонал\n7 - отчет о прибыли\n0 - закрыть смену\n>>: ";
		Getline(choose);
		if (choose == "1" && storageSize > 0) {
			Selling();
		}
		else if (choose == "2" && storageSize > 0) {
			ShowStorage();
		}
		else if (choose == "3" && storageSize > 0) {
			AddStorageItem();
		}
		else if (choose == "4" && storageSize > 0) {
			RemoveStorageItem();
		}
		else if (choose == "5") {
			ChangeStorage();
		}
		else if (choose == "6") {
			ChangeUsers();
		}
		else if (choose == "7") {
			ShowIncome();
		}
		else if (choose == "0") {
			if (LogOut()) {
				break;
			}
		}
		else {
			if (storageSize <= 0) {
				std::cout << "Склад пустой!\n";
			}
			Err();
		}
	}
}
void ShowUserMenu() {
	std::string choose;
	while (true) {
		std::cout << "1 - начать продажу\n2 - показать склад\n3 - отчет о прибыли\n0 - закрыть смену\n>>: ";
		Getline(choose);
		if (choose == "1" && storageSize > 0) {
			Selling();
		}
		else if (choose == "2" && storageSize > 0) {
			ShowStorage();
		}
		else if (choose == "3") {
			ShowIncome();
		}
		else if (choose == "0") {
			if (LogOut()) {
				break;
			}
		}
		else {
			if (storageSize <= 0) {
				std::cout << "Склад пустой!\n";
			}
			Err();
		}
	}
}
void ShowIncome() {
	system("cls");
	std::cout << "Текущая прибыль за смену:\nНаличный расчет " << cashIncome << "\nБезналичный расчет " << bankIncome << "\nИтого: " << cashIncome + bankIncome << "\nСумма ваших продаж: " << awardArr[currentId] << "\n";
	system("pause");
	system("cls");
}
bool LogOut() {
	std::string choose;
	while (true) {
		system("cls");
		std::cout << "Для подтверждения выхода введите свой пароль или \"exit\" для возврата в меню\n>>: ";
		Getline(choose);
		if (choose == "exit") {
			system("cls");
			return false;
		}
		else if (choose == passArr[currentId - 1] || choose == passArr[0]) {
			system("cls");
			return true;
		}
		else {
			Err();
		}
	}
}