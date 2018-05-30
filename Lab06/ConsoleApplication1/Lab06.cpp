//Lab06.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define PUT_DELIM(x, h, b) (x) + (h) >= (b) ? '\n' : ' '

typedef int(*handler_t)(void*);
int menu(const char**);
void tabulate_func(double a, double b, double h, double(*pf)(double));
int tab_handler1(void*);
int tab_handler2(void*);
int view_result(void*);
double f(double);
double f2(double);
double(*pf[2])(double) = { f, f2 };
typedef double(*func_t)(double);

double a = -1, b = 1, h = 0.01;
double a1 = -3.0, b1 = 3.0, x1, h1 = 0.2;

int main()
{

    const char* menu_items[] =
    {
        "Tabulate func"
        , "Tabulate func 2"
        , "View result"
        , NULL
    };

    handler_t handlers[] = {
        tab_handler1
        ,tab_handler2
        , view_result
    };

    int idx;

    do {

        idx = menu(menu_items);

        if (idx < 0)
        {
            perror("\tError index handler\n");
            return -1;
        }

        if (handlers[idx](NULL))
        {
            perror("\tError handling\n");
        }
    } while (idx >= 0);
    return 0;
}

int menu(const char* menu_items[])
{
    int n;
    for (n = 0; menu_items[n]; ++n)
    {
        printf("\t[%d]. %s\n", n, menu_items[n]);
    }

    int i = -1;
    printf("\tChoice: ");
    if (scanf("%d", &i) == 1)
    {
        if (i >= 0 && i < n)
        {
            return i;
        }
    }

    return i;
}

int tab_handler1(void* p)
{
    tabulate_func(a, b, h, pf[0]);
    return 0;
}

int tab_handler2(void* p)
{
    tabulate_func(a1, b1, h1, pf[1]);
    return 0;
}

int is_min(double y1, double y2, double y3)
{
    return y2 < y1 && y2 < y3;
}

int is_max(double y1, double y2, double y3)
{
    return y2 > y1 && y2 > y3;
}

void get_mark_extr(double y[], int sz, char* mark)
{
    if (sz < 3)
    {
        perror("\tInvalid count of points\n");
        exit(-1);
    }

    strcpy(mark, "");
    if (is_min(y[0], y[1], y[2]))
    {
        strcpy(mark, "Min");
    }
    else
    {
        if (is_max(y[0], y[1], y[2]))
        {
            strcpy(mark, "Max");
        }
    }
}

void tabulate_func(double a, double b, double h, double(*pf)(double))
{
    FILE *fl;
    char file[999];
    printf("\t%s\n", "Choose name & location for your file (ex. C:\\temp\\temp.txt)");
    scanf("%s", file);
    fl = fopen(file, "w");

    double x[3], y[3];
    x[0] = a; y[0] = f(x[0]);

    int j;

    for (j = 0; j < 2; ++j)
    {
        x[j + 1] = x[j] + h;
        y[j + 1] = pf(x[j + 1]);
    }

    {
        char mark[20] = "";
        get_mark_extr(y, 3, mark);
        for (j = 0; j < 3; ++j)
        {
            fprintf(fl, "\t%.3f %.3f %s\n", x[j], y[j], j == 1 ? mark : "");
        }
    }

    for (; x[2] <= b;)
    {
        for (j = 0; j < 2; ++j)
        {
            x[j] = x[j + 1];
            y[j] = y[j + 1];
        }

        x[2] += h;
        y[2] = pf(x[2]);
        {
            char mark[20] = "";
            get_mark_extr(y, 3, mark);
            fprintf(fl, "\t%.3f %.3f %s\n", x[j], y[j], mark);
        }
    }
    fclose(fl);
    printf("\t%s\n\n", "Successfully tabulated");
}

int view_result(void*)
{
    FILE *fl;
    char file[999];
    char str[255];
    printf("\t%s\n", "Locate your file (ex. C:\\temp\\temp.txt)");
    scanf("%s", file);
    fl = fopen(file, "r+");

    if (!fl) {
        printf("\tError while opening file: %s\n", file);
        return -1;
    }

    while (!feof(fl)) {
        fgets(str, 255, (FILE*)fl);
        printf("%s", str);
    }
    fclose(fl);
    printf("\t%s\n\n", "File opened without errors");
    return 0;
}

double f(double x)
{
    return -3 * x*x + 2 * sqrt(2 + x)*x;
}

double f2(double x)
{
    if (x <= -1.0)
    {
        return sqrt(1.0 - (x));
    }
    else {
        if (x < 1.0 && x > -1.0)
        {
            return asin((x) + 2.0);
        }
        else {
            return x + 1.0;
        }
    }
}

