#ifndef _SELL_H_
#define _SELL_H_

#include "Libs.h"
#include "GlobVar.h"
#include "Sys.h"
#include "Stor.h"

//продажи
void Selling();
void CheckArrAppend();
void PrintCheck(double& totalSum);
void StorageReturner();
void SaleDiscount(double& totalSum);
void SaleApple(int id, unsigned int& countArrCheck, double price, double& totalSum);

#endif