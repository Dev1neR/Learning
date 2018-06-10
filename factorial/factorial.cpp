// factorial.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;

int a[3000];
int k = 1;

void mult(int a[], int n) {
	int perenos = 0;
	int res;
	for (int i = 0; i<k; i++) {
		res = a[i] * n + perenos;
		a[i] = res % 10000;
		perenos = res / 10000;
	}

	if (perenos>0) {
		a[k++] = perenos;
	}
}

void f(int n) {
	if (n<2)a[0] = 1;
	else {
		f(n - 1);
		mult(a, n);
	}

}
void print(int a[]) {
	for (int i = k - 1; i >= 0; i--) {
		if (i != k - 1) {
			if (a[i]<10)cout << "000";
			else if (a[i]<100)cout << "00";
			else if (a[i]<1000)cout << "0";
		}
		cout << a[i];
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i<n; i++) {
		a[i] = 0;
	}
	f(n);
	print(a);
	cout << endl;
	return 0;
}

