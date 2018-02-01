// task-3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#define FUNC(x)	(1/2)*log((pow(x, 2)+ 1) / (pow(x, 2)- 1))
#define Q(x, n) (pow(x, 4) * (2*n+1)) / (2*n+3)

int main()
{
	double x, S = 0;
	printf("%s", "Enter x: (Rule 1 < x <= 2)\n");
	scanf("%lf", &x);
	if (x > 1 && x <= 2) {
		double a = x;
		unsigned int n = 0, N = 5;
		for (; n <= N; ++n) {
			S += a;
			a *= Q(x, n);
		}
		double y = FUNC(x), tol = fabs(S - y);
		printf("Sum:\t\t%.7f\nControl:\t%.7f\nTolerance:\t%.7f\n", S, y, tol);
		system("pause");
	}
	else {
		printf("%s", "Invalid input. Look at the rule!\n");
		system("pause");
		return -1;
	}
    return 0;
}

