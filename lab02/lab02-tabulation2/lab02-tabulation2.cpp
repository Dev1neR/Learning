// lab02-tabulation2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	double a = -5, b = 5, c = -4, d = 4, hx = 0.2, hy = 0.12;
	printf("%c\\%c", 'Y', 'X');
	for (double x = a; x <= b; x += hx) {
		printf("\t%8.2f", x);
	}
	printf("\n");
	for (double y = c; y <= d; y += hy) {
		printf("%.2f", y);
		for (double x = a; x <= b; x += hx) {
			double z = exp(y) / (x + y);
			printf("\t%8.2f", z);
		}
		printf("\n");
	}
	printf("\n");
	getchar();
    return 0;
}

