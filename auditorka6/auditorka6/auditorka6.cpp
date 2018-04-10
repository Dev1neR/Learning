// auditorka6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

char UI();
void create();
void rmv();
int view();

int main()
{
	int(*pf) = NULL;
	do {
		switch (UI()) {
		case '1':
			create();
			break;
		case '2':
			rmv();
			break;
		case '3':
			view();
			break;
		default:
			printf("Bye\n");
		}
	} while (pf);
    return 0;
}

char UI() {
	printf("%s\n", "Choose from the following");
	printf("%s\n", "1. Create file");
	printf("%s\n", "2. Delete file");
	printf("%s\n", "3. View file");
	printf("%s\n", "Any key to exit");
	printf("%s", "Enter your choice: ");
	fflush(stdin);
	return tolower(getchar());
}

int view() {
	FILE *f;
	char file[999];
	char str[255];
	printf("%s\n", "Locate your file (ex. C:\\temp\\temp.txt)");
	scanf("%s", &file);
	f = fopen(file, "r+");

	if (!f) {
		printf("Error while opening file: %s\n", file);
		return -1;
	}

	while (!feof(f)) {
		fgets(str, 255, (FILE*)f);
		printf("%s", str);
	}
	fclose(f);
}

void rmv() {
	int rem;
	char file[999];
	printf("%s\n", "Choose location for file to delete (ex. C:\\temp\\temp.txt)");
	scanf("%s", &file);
	rem = remove(file);

	if (rem == 0) {
		printf("File deleted successfully\n");
	}
	else {
		printf("Error: unable to delete the file\n");
	}
}

void create() {
	FILE *f;
	char file[999];
	printf("%s\n", "Choose name & location for your file (ex. C:\\temp\\temp.txt)");
	scanf("%s", &file);
	f = fopen(file, "w");
	fclose(f);
	printf("%s\n", "File successfully created");	
}