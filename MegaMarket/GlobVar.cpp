#include "GlobVar.h"

//учётки
size_t userSize = 2;
size_t staffCount = 1;
std::string* loginArr = new std::string[userSize]{ "admin", "user" };
std::string* passArr = new std::string[userSize]{ "admin", "user" };
std::string userStatus[3]{ "Супер Администратор", "Администратор", "Сотрудник" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2] };
double* awardArr = new double[userSize] {0.0, 0.0};
unsigned int* userIdArr = new unsigned int[userSize] {1, 2};
std::string currentStatus;
int currentId = 0;

//склад
size_t storageSize = 0;
bool staticStorageCreated = false;
int* idArr;
std::string* nameArr;
unsigned int* countArr;
double* priceArr;

//продажи
size_t checkSize = 0;
int* idArrCheck;
std::string* nameArrCheck;
unsigned int* countArrCheck;
double* priceArrCheck;
double* totalPriceArrCheck;
double cash = 1900 + rand() % 300;
double cashIncome = 0.0;
double bankIncome = 0.0;
bool SaleAppleTrigger = false;