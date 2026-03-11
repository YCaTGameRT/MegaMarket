#include "Usr.h"

void ChangeUsers() {
	std::string choose;
	while (true) {
		std::cout << "1 - добавить нового пользователя\n2 - показать пользователей\n3 - изменить пароль\n4 - удалить пользователя\n0 - выйти из редактора\n>>: ";
		Getline(choose);
		if (choose == "1") {
			AddNewUser();
		}
		else if (choose == "2" && userSize > 1) {
			ShowUsers();
		}
		else if (choose == "3" && userSize > 1) {
			ChangePass();
		}
		else if (choose == "4" && userSize > 1) {
			DeleteUser();
		}
		else if (choose == "0") {
			system("cls");
			break;
		}
		else {
			if (userSize <= 1) {
				std::cout << "Пользователей нет!\n";
			}
			Err();
		}
	}
}
void ShowUsers(int mode) {
	system("cls");
	if (mode == 0) {
		std::cout << "#\t" << std::left << std::setw(10) << "Логин\t\tПароль\tРоль\n";
		for (size_t i = 1; i < userSize; i++) {
			std::cout << i << "\t" << std::left << std::setw(10) << loginArr[i] << "\t" << passArr[i] << "\t" << statusArr[i] << "\n";
		}
		Sleep(1500);
	}
	else if (mode == 1) {
		std::cout << "#\t" << std::left << std::setw(10) << "Логин\t\tПароль\tРоль\n";
		for (size_t i = 0; i < userSize; i++) {
			std::cout << i << "\t" << std::left << std::setw(10) << loginArr[i] << "\t" << passArr[i] << "\t" << statusArr[i] << "\n";
		}
		Sleep(1500);
	}
}
void AddNewUser() {
	std::string newLogin, newPass, newRole, choose;
	bool exit;
	while (true) {
		exit = true;
		while (true) {
			system("cls");
			std::cout << "\tСоздание нового пользователя\n\n";
			std::cout << "\tВведите логин нового пользователя или \"exit\" для выхода\n>>: ";
			Getline(newLogin);
			if (newLogin == "exit") {
				std::cout << "Создание нового пользователя прервано!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			else if (CheckLogin(newLogin)) {
				break;
			}
		}
		while (exit) {
			system("cls");
			std::cout << "\tСоздание нового пользователя\n\n";
			std::cout << "\tВведите пароль нового пользователя\n>>: ";
			Getline(newPass);
			if (newPass == "exit") {
				std::cout << "Создание нового пользователя прервано!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (CheckLogin(newPass)) {
				break;
			}
		}
		while (exit) {
			system("cls");
			std::cout << "\tСоздание нового пользователя\n\n";
			std::cout << "\tВыберите роль нового пользователя\n1 - администратор\n2 - сотрудник\n>>: ";
			Getline(choose);
			if (choose == "exit") {
				std::cout << "Создание нового пользователя прервано!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (choose == "1") {
				newRole = userStatus[1];
				break;
			}
			else if (choose == "2") {
				newRole = userStatus[2];
				break;
			}
			else {
				Err();
			}
		}
		while (exit) {
			std::cout << "Пользователь: " << newLogin << "\nПароль: " << newPass << "\nРоль: " << newRole << "\nПодтвердить?\n1 - да\n2 - нет\n>>: ";
			Getline(choose);
			if (choose == "1") {
				if (newRole == userStatus[2]) {
					staffCount++;
				}
				userSize++;
				std::string* loginArrTemp = new std::string[userSize];
				std::string* passArrTemp = new std::string[userSize];
				std::string* statusArrTemp = new std::string[userSize];
				double* awardArrTemp = new double[userSize];
				unsigned int* userIdArrTemp = new unsigned int[userSize];
				FillArr(loginArrTemp, loginArr, userSize - 1);
				FillArr(passArrTemp, passArr, userSize - 1);
				FillArr(statusArrTemp, statusArr, userSize - 1);
				FillArr(awardArrTemp, awardArr, userSize - 1);
				FillArr(userIdArrTemp, userIdArr, userSize - 1);
				loginArrTemp[userSize - 1] = newLogin;
				passArrTemp[userSize - 1] = newPass;
				statusArrTemp[userSize - 1] = newRole;
				awardArrTemp[userSize - 1] = 0.0;
				userIdArrTemp[userSize - 1] = userSize;
				std::swap(loginArr, loginArrTemp);
				std::swap(passArr, passArrTemp);
				std::swap(statusArr, statusArrTemp);
				std::swap(awardArr, awardArrTemp);
				std::swap(userIdArr, userIdArrTemp);
				delete[]loginArrTemp;
				delete[]passArrTemp;
				delete[]statusArrTemp;
				delete[]awardArrTemp;
				delete[]userIdArrTemp;
				std::cout << "Пользователь успешно добавлен!\n";
				Sleep(1500);
				break;
			}
			else if (choose == "2") {
				std::cout << "Отмена\n";
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
void ChangePass() {
	std::string newPass1, newPass2, choose;
	int userNumber = 0, isAdmin = 0;
	while (true) {
		if (currentStatus == userStatus[0]) {
			ShowUsers(1);
			isAdmin = 0;
		}
		else {
			ShowUsers(0);
			isAdmin = 1;
		}
		std::cout << "Выберите номер пользователя для смены пароля или \"exit\" для выхода\n>>: ";
		Getline(choose);
		if (choose == "exit") {
			std::cout << "Отмена операции пополнения\n";
			Sleep(1500);
			break;
		}
		else if (IsNumber(choose)) {
			userNumber = std::stoi(choose);
			if (userNumber < isAdmin || userNumber > userSize - 1) {
				std::cout << "Пользователя с таким номером не существует!\n";
				Sleep(1500);
			}
			else {
				while (true) {
					system("cls");
					if (currentStatus == userStatus[1] && statusArr[userNumber] == userStatus[1]) {
						std::cout << "нельзя менять пароли администраторам!\n";
						Sleep(1500);
						break;
					}
					std::cout << "Введите новый пароль для пользователя " << loginArr[userNumber] << "\n>>: ";
					Getline(newPass1);
					std::cout << "Подтвердите новый пароль для пользователя " << loginArr[userNumber] << "\n>>: ";
					Getline(newPass2);
					if (CheckPass(newPass1) && CheckPass(newPass1) && newPass1 == newPass2) {
						passArr[userNumber] = newPass1;
						std::cout << "Пароль успешно сменён\n";
						Sleep(1500);
						break;
					}
					else {
						std::cout << "Повторите попытку\n";
						Sleep(1500);
					}
				}
			}
		}
		else {
			Err();
		}
	}
}
void DeleteUser() {
	std::string chooseNumber, checkPass, choose;
	int userNumber = 0, isAdmin = 0;
	while (true) {
		if (currentStatus == userStatus[0]) {
			if (userSize < 2) {
				std::cout << "Нет доступных пользователей для удаления!\n";
				Sleep(1500);
				return;
			}
		}
		else if (currentStatus == userStatus[1]) {
			if (staffCount < 2) {
				std::cout << "Нет доступных пользователей для удаления!\n";
				Sleep(1500);
				return;
			}
		}
		ShowUsers();
		isAdmin = 1;
		std::cout << "Выберите номер пользователя для удаления или \"exit\" для выхода\n>>: ";
		Getline(choose);
		if (choose == "exit") {
			std::cout << "Отмена операции удаления\n";
			Sleep(1500);
			break;
		}
		else if (IsNumber(choose)) {
			userNumber = std::stoi(choose);
			if (userNumber < isAdmin || userNumber > userSize - 1) {
				std::cout << "Пользователя с таким номером не существует!\n";
				Sleep(1500);
			}
			while (true) {
				system("cls");
				if (currentStatus == userStatus[1] && statusArr[userNumber] != userStatus[2]) {
					std::cout << "Нельзя удалять суперадминестратора\n";
					Sleep(1500);
					break;
				}
				std::cout << "Удаление пользователя: " << loginArr[userNumber] << "\nДля подтверждения введите пароль суперадминистратора или \"exit\" для выхода\n>>: ";
				Getline(checkPass);
				if (checkPass == "exit") {
					std::cout << "Отмена удаления пользователя" << loginArr[userNumber] << "\n";
					Sleep(1500);
					break;
				}
				else if (checkPass == passArr[0]) {
					if (statusArr[userNumber] == userStatus[2]) {
						staffCount--;
					}
					std::cout << "Удаляемый пользователь: " << std::left << std::setw(25) << loginArr[userNumber] << "\nПодтвердить?\n1 - да\n2 - нет\n>>: ";
					Getline(choose);
					if (choose == "1") {
						storageSize--;
						std::string* loginArrTemp = new std::string[storageSize];
						std::string* passArrTemp = new std::string[storageSize];
						std::string* statusArrTemp = new std::string[storageSize];
						double* awardArrTemp = new double[userSize];
						unsigned int* userIdArrTemp = new unsigned int[userSize];
						for (size_t i = 0, c = 0; i < userSize; i++, c++) {
							if (userNumber == c) {
								c++;
							}
							loginArrTemp[i] = loginArr[c];
							passArrTemp[i] = passArr[c];
							statusArrTemp[i] = statusArr[c];
							awardArrTemp[i] = awardArr[c];
							userIdArrTemp[i] = userIdArr[c];
						}
						std::swap(loginArr, loginArrTemp);
						std::swap(passArr, passArrTemp);
						std::swap(statusArr, statusArrTemp);
						std::swap(awardArr, awardArrTemp);
						std::swap(userIdArr, userIdArrTemp);
						delete[]loginArrTemp;
						delete[]passArrTemp;
						delete[]statusArrTemp;
						delete[]awardArrTemp;
						delete[]userIdArrTemp;
						std::cout << "Удаление завершено\n";
						Sleep(1500);
						break;
					}
				}
				else {
					std::cout << "Некорректный пароль суперадмина\n";
					Sleep(1500);
				}
			}
		}
		else {
			Err();
		}
	}
}