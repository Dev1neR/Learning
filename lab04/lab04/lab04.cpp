// lab04.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

int main() {
	SetConsoleOutputCP(1251);

	int ctr1 = 0, ctr2 = 0;
	char str[100];
	printf("%s", "Підрахувати кількість знаків пунктуації у текстовому рядку.\nВведіть якусь інформацію (тільки англійською) : ");

	gets_s(str); //Считывать инфу с консоли

	while (str[ctr1]) 
	{
		if (ispunct(str[ctr1])) ctr2++; //Находит знак пунктуации - ++
		ctr1++;
	}

	printf("Кількість знаків пунктуації: %d\n", ctr2);
	getchar();
	return(0);
}

