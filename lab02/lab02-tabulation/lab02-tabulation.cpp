// lab02-tabulation.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#define PUT_DELIM(x, h, b) (x) + (h) >= (b) ? '\n' : ' '
#define COND1(x) (x) <= -1.0
#define FUNC1(x) sqrt(1-(x))
#define COND2(x) (x) < 1.0 && (x) > -1.0
#define FUNC2(x) asin((x)+2)
#define FUNC3(x) (x) + 1
#define FUNC(x) COND1(x) ? FUNC1(x): (COND2(x) ? FUNC2(x) : FUNC3(x))

int main()
{
	double a = -3.0, b = 3.0, x, h = 0.2;
	printf("x:\t");
	for (x = a; x <= b; x += h)
	{
		printf("%6.2f%c", x, PUT_DELIM(x, h, b));
	}
	printf("y:\t");
	for (x = a; x <= b; x += h)
	{
		printf("%6.3f%c", FUNC(x), PUT_DELIM(x, h, b));
	}
	getchar();

    return 0;
}

