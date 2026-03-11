#ifndef _STOR_H_
#define _STOR_H_

#include "Libs.h"
#include "GlobVar.h"
#include "Sys.h"

//склад
void CreateStorage();
void CreateNewStorage();
void ShowStorage(int mode = 0);
void AddStorageItem();
void RemoveStorageItem();
void ChangePrice();
void ChangeStorage();
void AddNewItem();
void ChangeName();
void DeleteItem();
void DeleteNewStorageItems(int id);

#endif