// Task3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

typedef double(*quad_func_t)(double);
double trapez(double, double, double, quad_func_t);
double f(double);
double res();

int main()
{
	SetConsoleOutputCP(1251);
	double a = 1, b = 2, eps = 1e-5, S;
	S = trapez(a, b, eps, f);
	double I = res();
	printf("Result:\nI=%.5f\nAnalytical:\nI=%.5f\n", S, I);
	system("pause");
	return 0;
}

double trapez(double a, double b, double eps, quad_func_t f)
{
	double S = 0, x, h = 0.01;
	x = a;
	while (x < b)
	{
		S = S + (f(x + h) + f(x))*h / 2;
		if (0.5*(f(x + h) + f(x))*h >= eps)
			x = x + h;
		else
			break;

	}
	return S;
}

double f(double x)
{
	return pow((sqrt(x) - 1.0),2.0);
}

double res()
{
	return -((pow(2,7.0/2.0)-12.0)/3.0) - 1.0/6.0;
}