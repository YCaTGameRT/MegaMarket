#ifndef _SYS_H_
#define _SYS_H_

#include "Libs.h"
#include "GlobVar.h"

//система
template<typename Arr> void FillArr(Arr* dynamicArr, Arr* staticArr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		dynamicArr[i] = staticArr[i];
	}
}
inline void Getline(std::string& str) {
	std::getline(std::cin, str, '\n');
}
inline void Err(int time = 1500) {
	std::cout << "Некорректный ввод!";
	Sleep(time);
	system("cls");
}

//из программа
bool IsNumber(const std::string& str);
bool CheckLogin(const std::string& str);
bool CheckPass(const std::string& str);

#endif

