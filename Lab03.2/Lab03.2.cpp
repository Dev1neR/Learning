// Lab03.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#define SPLIT_ROW(i, n) (i) < (n) - 1 ? '\t' : '\n'

int main()
{
	const int sz = 3;
	int array[sz][sz], idx[sz];
	srand(time(NULL));
	int i, j;
	//Работа с массивом
	for (i = 0; i < sz; ++i) {
		for (j = 0; j < sz; ++j) {
			array[i][j] = rand() % 101 - 50;
		}
	}
	
	//Вывод
	for (i = 0; i < sz; ++i) {
		for (j = 0; j < sz; ++j) {
			printf("%4d%c", array[i][j], SPLIT_ROW(j, sz));
		}
	}
    return 0;
}

