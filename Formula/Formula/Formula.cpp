// Formula.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	float a, b, x;
	a = 20.1f;
	b = 1.07f;
	x = 0.19f;
	SetConsoleOutputCP(1251);
	printf("%s", "Виконав: Волощук Сергій. Група 105. Варіант 6\n");
	printf("a = %.1f, b = %.2f, x = %.2f\n", a, b, x);
	printf("Результат: %.5f\n", 1 - tan(a*x)/b-sqrt(x+1));
	getchar();
    return 0;
}

