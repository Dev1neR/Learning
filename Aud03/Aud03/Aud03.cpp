// Aud03.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#define BUFFER_SIZE 120
int main()
{
	SetConsoleOutputCP(1251);
	int buffer[BUFFER_SIZE], min, max, cn_gt_neg, sum = 0, current = 0, negative = 0;
	printf("%s", "Enter range: \n");
	scanf("%d %d", &min, &max);
	printf("%s", "Enter decimal for task 2: \n");
	scanf("%d", &cn_gt_neg);
	srand(time(NULL));
	for (int i = 0; i < sizeof(buffer) / sizeof(int); ++i)
	{
		buffer[i] = rand() % (max - min + 1) + min;
		printf("%d%c", buffer[i], i < BUFFER_SIZE - 1 ? '\t' : '\n');
		if (buffer[i] < 0 && buffer[i] > cn_gt_neg) {
			++current;
			if (current > negative) {
				negative = current;
			}
		}
		sum += buffer[i];
	}
	printf("Сума елементів у масиві: %d\n", sum);
	printf("Від'ємні значення більше ніж %d: %d\n", cn_gt_neg, negative);
	getchar();
	return 0;
}

