#include "Libs.h"
#include "Prog.h"

//Danger Zone!!!
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Start();

	delete[]loginArr;
	delete[]passArr;
	delete[]statusArr;
	if (staticStorageCreated) {
		delete[]idArr;
		delete[]nameArr;
		delete[]countArr;
		delete[]priceArr;
	}

	return 0;
}

//функции