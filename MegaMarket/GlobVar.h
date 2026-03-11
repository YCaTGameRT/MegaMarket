#ifndef _GLOB_VAR_H_
#define _GLOB_VAR_H_

#include "Libs.h"

//учётки
extern size_t userSize;
extern size_t staffCount;
extern std::string* loginArr;
extern std::string* passArr;
extern std::string userStatus[3];
extern std::string* statusArr;
extern double* awardArr;
extern unsigned int* userIdArr;
extern std::string currentStatus;
extern int currentId;

//склад
extern size_t storageSize;
extern bool staticStorageCreated;
extern int* idArr;
extern std::string* nameArr;
extern unsigned int* countArr;
extern double* priceArr;

//продажи
extern size_t checkSize;
extern int* idArrCheck;
extern std::string* nameArrCheck;
extern unsigned int* countArrCheck;
extern double* priceArrCheck;
extern double* totalPriceArrCheck;
extern double cash;
extern double cashIncome;
extern double bankIncome;
extern bool SaleAppleTrigger;

#endif