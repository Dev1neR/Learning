// Formula.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	float a = 20.1f, b = 1.07f, x = 0.19f;
	double y = 1 - tan(a * x) / b - sqrt(x + 1);
	SetConsoleOutputCP(1251);
	printf("%s", "Виконав: Волощук Сергій. Група 105. Варіант 6\n");
	printf("a = %.1f, b = %.2f, x = %.2f\n", a, b, x);
	printf("Результат: %f\n", y);
	getchar();
    return 0;
}

