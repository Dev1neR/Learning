// Lab03.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#define SPLIT_ROW(i, n) (i) < (n) - 1 ? '\t' : '\n'

int main()
{
	const int sz = 3;
	int array[sz][sz], idx[sz];
	srand(time(NULL));
	int i;
	for (i = 0; i < sz; ++i) {
		int j;
		for (j = 0; j < sz; ++j) {
			array[i][j] = rand() % 101 - 50;
			printf("%4d%c", array[i][j], SPLIT_ROW(j, sz));
		}
	}
    return 0;
}

