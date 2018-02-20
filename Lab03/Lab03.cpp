// Lab03.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#define SPLIT_ROW(i, n) (i) < (n) - 1 ? '\t' : '\n'

int main()
{
	const int sz = 5;
	int array[sz], avg = 0;
	srand(time(NULL));
	for (int i = 0; i < sizeof(array)/sizeof(int); ++i) 
	{
		array[i] = rand() % 100 + 1;
		printf("%d%c", array[i], SPLIT_ROW(i, sz));
		avg += array[i];
	}
	avg /= sz;
	printf("Average: %d\n", avg);
	getchar();
	printf("Now, you see the result of operation: array element - average \n");
	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
	{
		array[i] = array[i] - avg;
		printf("%d%c", array[i], SPLIT_ROW(i, sz));
	}
	getchar();
    return 0;
}

