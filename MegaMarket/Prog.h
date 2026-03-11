#ifndef _PROG_H_
#define _PROG_H_

#include "Libs.h"
#include "GlobVar.h"
#include "Sys.h"
#include "Usr.h"
#include "Stor.h"
#include "Sell.h"

//программа
void Start();
bool Login();
void ShowSuperAdminMenu();
void ShowAdminMenu();
void ShowUserMenu();
void ShowIncome();
bool LogOut();

#endif