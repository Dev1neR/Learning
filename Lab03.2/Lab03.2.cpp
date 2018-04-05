// Lab03.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#define SPLIT_ROW(i, n) (i) < (n) - 1 ? '\t' : '\n'
#define sz 3

//Поиск простых чисел
bool prime(int n) {
	if (n == 1) { return false; }
	if (n == 2 || n == 3) { return true; }
	if (n % 2 == 0) { return false; }
	int s = sqrt(n + 1);
	for (int i = 4; i <= s; i += 2) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;

}

int main()
{
	int array2d[sz][sz];
	srand(time(NULL));
	int i, j, z, counter = 0;
	double s = 0;
	//Работа с массивом
	for (i = 0; i < sz; ++i) {
		for (j = 0; j < sz; ++j) {
			array2d[i][j] = rand() % 101 + 1 ;
			printf("%4d%c", array2d[i][j], SPLIT_ROW(j, sz));
		}
	}

	printf("\n");
	//Вывод простых чисел и их индексов
	for (i = 0; i < sz; ++i) {
		for (j = 0; j < sz; ++j) {
			if (prime(array2d[i][j])) {
				printf("%d - is prime at indexes %d %d\n", array2d[i][j], i, j);
				s += array2d[i][j];
				counter++;
			}
		}
	}
	// Вывод кол-ва простых чисел и их среднее значение
	printf("\nThere are '%d' prime numbers\n", counter);
	if (counter != 0) {
		printf("\nAverage value is %.4f\n", s/counter);
	}
	getchar();
    return 0;
}

