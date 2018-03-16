// DiskretkaRandomizer.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Stark.h"

struct variables {
	char numlet;
	const char *mth = 0;
	const char *months[12] = { "января", "февраля", "марта", "апреля", "мая", "июня", "июля", "августа", "сентября", "октября", "ноября", "декабря" }; // Массив месяцев
	int number, variant, taskcount, day, month, answer;
};

int scanError() {
	printf("%s", "Написал хуйню - получай хуйню\n");
	system("pause");
	exit(0);
}

int main()
{
	struct variables var; // Инициализатор структуры

	srand(time(NULL)); // Генератор рандомных чисел
	SetConsoleOutputCP(1251); // Русские символы в консольке

	puts("Ультра рандомайзер дискретной математики 2k18\nНажмите Enter - если у вас всё хуёво");
	getchar();
	puts("Введите сегодняшнюю дату (день/месяц)");
	if (scanf("%d/%d", &var.day, &var.month) != 2) {
		scanError();
	}
	else {
		switch (var.month) { // Какой по счету месяц ввёл пользователь - преобразуем в буквенном виде
		case 1:
			var.mth = var.months[0];
			break;
		case 2:
			var.mth = var.months[1];
			break;
		case 3:
			var.mth = var.months[2];
			break;
		case 4:
			var.mth = var.months[3];
			break;
		case 5:
			var.mth = var.months[4];
			break;
		case 6:
			var.mth = var.months[5];
			break;
		case 7:
			var.mth = var.months[6];
			break;
		case 8:
			var.mth = var.months[7];
			break;
		case 9:
			var.mth = var.months[8];
			break;
		case 10:
			var.mth = var.months[9];
			break;
		case 11:
			var.mth = var.months[10];
			break;
		case 12:
			var.mth = var.months[11];
			break;
		default:
			printf("Чё ты блять наделал, дуроёб? Сломал программу - запускай теперь по новой. Чтобы такой хуйни больше не было\n");
			system("pause");
			exit(0);
		}
	}
	puts("Введите номер работы и вариант (пример: 1[а] 2)");
	if (scanf("%d[%c] %d", &var.number, &var.numlet, &var.variant) != 3) {
		scanError();
	}
	puts("Введите кол-во заданий");
	if (scanf("%d", &var.taskcount) != 1) {
		scanError();
	}
	
	printf("%s","Обработка.. |");
	fflush(stdout);
	for (int count = 0; count < 3; ++count) {	// Анимация
		printf("\b/");
		fflush(stdout);
		Sleep(1000);
		printf("\b-");
		fflush(stdout);
		Sleep(1000);
		printf("\b\\");
		fflush(stdout);
		Sleep(1000);
		printf("\b|");
		fflush(stdout);
		Sleep(1000);
	}
	system("cls"); // Очистка консоли
	
	printf("\nДата: %d %s\nНомер работы: %d(%c) - Вариант: %d\nКоличество заданий: %d\n", var.day, var.mth, var.number, var.numlet, var.variant, var.taskcount);

	for (int i = 1; i <= var.taskcount; ++i) 
	{
		var.answer = rand() % 9 + 1;
		Sleep(2 * 1000);
		printf("Задание %d - %d\n", i, var.answer); // Вывод результата
	}
	Stark(); // Призыв Старка

	system("pause"); // Чтобы программа не дропалась сразу
    return 0;
}

