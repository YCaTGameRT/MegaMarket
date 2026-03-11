#include "Sell.h"

void Selling() {
	std::string chooseId, chooseCount, choose, chooseCash;
	unsigned int id = 0, count = 0, index = -1;
	double totalSum = 0.0, money = 0.0;
	bool isFirst = false;
	checkSize = 0;
	while (true) {
		system("cls");
		ShowStorage();
		std::cout << "Введите ID товара для покупки или \"exit\" для завершения покупок\n>>: ";
		Getline(chooseId);
		if (chooseId == "exit") {
			//оплата
			if (isFirst == false) {
				std::cout << "Выход без покупок\n";
				Sleep(1500);
				continue;
			}
			PrintCheck(totalSum);
			std::cout << "Подтвердить покупку?\n1 - да\n2 - добавить ещё товар\n3 - отмена\n>>: ";
			Getline(choose);
			if (choose == "1") {
				while (true) {
					std::cout << "У вас есть дисконтная карта?\n1 - да\n2 - нет\n>>: ";
					Getline(choose);
					if (choose == "1")
					{
						SaleDiscount(totalSum);
						break;
					}
					else {
						Err();
					}
				}
				while (true) {
					std::cout << "Выберите способ оплаты\n1 - наличными\n2 - безнал\n>>: ";
					Getline(choose);
					system("cls");
					if (choose == "1") {
						std::cout << "Введите кол-во наличных\n>>: \n";
						Getline(chooseCash);
						if (IsNumber(chooseCash)) {
							money = stod(chooseCash);
							if (money < totalSum) {
								std::cout << "Недостаточно средств!\n";
								Sleep(1500);
								continue;
							}
							else if (money > (money - totalSum) > cash) {
								std::cout << "Нет возможности сдать сдачи! Повторите попытку\n";
								Sleep(1500);
								continue;
							}
							else {
								std::cout << "Ваши " << money << "\n";
								std::cout << "Оплата прошла успешно! Сдача " << money - totalSum << " рублей\n";
								Sleep(1500);
								cash -= money - totalSum;
								cashIncome += totalSum;
								awardArr[currentId] += totalSum;
								system("cls");
								break;
							}
						}
					}
					else if (choose == "2") {
						std::cout << "Приложите карту\n";
						if (rand() % 10 <= 2) {
							for (size_t i = 0; i < 5; i++) {
								std::cout << i + 1 << "\n";
								Sleep(800);
							}
							std::cout << "Соединение не установлено. Повторите попытку\n";
						}
						else {
							for (size_t i = 0; i < 5; i++) {
								std::cout << i + 1 << "\n";
								Sleep(800);
							}
						}
						std::cout << "Операция проведена успешно!\nСПАСИБО ЗА ПОКУПКУ!\n";
						Sleep(1500);
						bankIncome += totalSum;
						awardArr[currentId] += totalSum;
						system("cls");
						break;
					}
					else if (choose == "CaT") {
						std::cout << "Кот принят! ВСЁ БЕСПЛАТНО!\n";
						Sleep(1500);
						system("cls");
						break;
					}
					else {
						Err();
					}
				}
			}
			else if (choose == "2") {
				continue;
			}
			else if (choose == "3") {
				std::cout << "Отмена покупки!\n";
				StorageReturner();
				Sleep(1500);
				return;
			}
			else {
				Err();
				continue;
			}
			delete[]idArrCheck;
			delete[]nameArrCheck;
			delete[]priceArrCheck;
			delete[]countArrCheck;
			delete[]totalPriceArrCheck;
			idArrCheck = nullptr;
			nameArrCheck = nullptr;
			priceArrCheck = nullptr;
			countArrCheck = nullptr;
			totalPriceArrCheck = nullptr;
			break;
		}
		if (IsNumber(chooseId)) {
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > storageSize - 1) {
				std::cout << "Ошибка ID!\n";
				Sleep(1500);
				continue;
			}
		}
		else {
			Err();
		}
		std::cout << "Введите кол-во товара или \"exit\" для выбора другого товара\n>>: ";
		Getline(chooseCount);
		if (chooseCount == "exit") {
			std::cout << "Отмена покупки товара: " << nameArr[id] << "\n";
			Sleep(1500);
			continue;
		}
		if (IsNumber(chooseCount)) {
			count = std::stoi(chooseCount);
			if (count < 1 || count > countArr[id]) {
				std::cout << "Ошибка кол-ва! Максимум: " << countArr[id] << "\n";
				Sleep(1500);
				continue;
			}
		}
		else {
			Err();
		}
		CheckArrAppend();
		index++;
		idArrCheck[index] = idArr[id];
		nameArrCheck[index] = nameArr[id];
		priceArrCheck[index] = priceArr[id];
		countArrCheck[index] = count;
		totalPriceArrCheck[index] = count * priceArr[id];
		SaleApple(idArrCheck[index], countArrCheck[index], priceArrCheck[index], totalPriceArrCheck[index]);
		countArr[id] -= count;
		totalSum += totalPriceArrCheck[index];
		std::cout << "Товар добавлен в чек\n\n";
		isFirst = true;
		Sleep(1000);
	}
}
void CheckArrAppend() {
	checkSize++;
	int* idArrCheckTemp = new int[checkSize];
	std::string* nameArrCheckTemp = new std::string[checkSize];
	unsigned int* countArrCheckTemp = new unsigned int[checkSize];
	double* priceArrCheckTemp = new double[checkSize];
	double* totalPriceArrCheckTemp = new double[checkSize];
	//!!!!
	FillArr(idArrCheckTemp, idArrCheck, checkSize - 1);
	FillArr(nameArrCheckTemp, nameArrCheck, checkSize - 1);
	FillArr(countArrCheckTemp, countArrCheck, checkSize - 1);
	FillArr(priceArrCheckTemp, priceArrCheck, checkSize - 1);
	FillArr(totalPriceArrCheckTemp, totalPriceArrCheck, checkSize - 1);
	std::swap(idArrCheckTemp, idArrCheck);
	std::swap(nameArrCheckTemp, nameArrCheck);
	std::swap(countArrCheckTemp, countArrCheck);
	std::swap(priceArrCheckTemp, priceArrCheck);
	std::swap(totalPriceArrCheckTemp, totalPriceArrCheck);
	delete[]idArrCheckTemp;
	delete[]nameArrCheckTemp;
	delete[]countArrCheckTemp;
	delete[]priceArrCheckTemp;
	delete[]totalPriceArrCheckTemp;
}
void PrintCheck(double& totalSum) {
	std::cout << "#\t" << "ID\t" << std::left << std::setw(25) << "название товаров\t\tкол-во\t\tцена за ед.\tитого\n";
	for (size_t i = 0; i < checkSize; i++) {
		std::cout << i + 1 << "\t" << idArrCheck[i] << "\t" << std::left << std::setw(25) << nameArrCheck[i] << "\t" << countArrCheck[i] << "\t\t" << priceArrCheck[i] << "\t\t" << totalPriceArrCheck[i] << "\n";
		if (idArrCheck[i] == 2 && SaleAppleTrigger) {
			std::cout << "АКЦИЯ! Вы получаете " << countArrCheck[i] / 5 << "кг яблок в подарок!\n";
			SaleAppleTrigger = false;
		}
	}
	std::cout << "Итого к оплате: " << totalSum << "\n";
}
void StorageReturner() {
	for (size_t i = 0; i < checkSize; i++) {
		countArr[idArrCheck[i] - 1] += countArrCheck[i];
	}
	delete[]idArrCheck;
	delete[]nameArrCheck;
	delete[]priceArrCheck;
	delete[]countArrCheck;
	delete[]totalPriceArrCheck;
	idArrCheck = nullptr;
	nameArrCheck = nullptr;
	priceArrCheck = nullptr;
	countArrCheck = nullptr;
	totalPriceArrCheck = nullptr;
	checkSize = 0;
}
void SaleDiscount(double& totalSum) {
	totalSum = totalSum - (totalSum * 3 / 100);
	std::cout << "Вы предъявили дисконтную карту! Скидка 3%!\n";
	Sleep(1500);
}
void SaleApple(int id, unsigned int& countArrCheck, double price, double& totalSum) {
	if (id == 2 && (countArrCheck % 5 == 0)) {
		totalSum -= price * countArrCheck / 5;
		SaleAppleTrigger = true;
	}
}