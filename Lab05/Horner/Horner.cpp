// Horner.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

int horner(int poly[], int n, int x)
{
	int result = poly[0]; 
						  
	for (int i = 1; i < n; i++) {
		result = result * x + poly[i];
	}
	return result;
}


int main()
{
	int poly[] = { 4, 1, 3, 3 };
	int x = 3;
	int n = sizeof(poly) / sizeof(int);
	printf("Value of the polynomial is: %d\n", horner(poly, n, x));
	return 0;
}
