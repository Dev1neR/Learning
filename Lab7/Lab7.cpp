// Lab7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;

class vector2d
{
public:
	vector2d();
	vector2d(float x, float y) :x(x), y(y) {}
	~vector2d();
	void SetVector(const char * const caption);
	void display(const char * const caption);
	void length(vector2d& vec1);
	void scalar(vector2d& vec1, vector2d& vec2);
	void cosinus(vector2d& vec1, vector2d& vec2);

	vector2d operator+(vector2d& b) {
		return vector2d(this->x + b.x, this->y + b.y);
	}
	vector2d operator-(vector2d& b) {
		return vector2d(this->x - b.x, this->y - b.y);
	}


private:
	float x, y;
};


vector2d::vector2d()
{
	x = 0.0;
	y = 0.0;
}

vector2d::~vector2d()
{
}

void vector2d::SetVector(const char * const caption)
{
	cout << caption << endl;
	cout << "X = ";
	cin >> x;
	cout << "Y = ";
	cin >> y;
}



void vector2d::length(vector2d& vec1)
{
	cout << "Length of vector:" << endl;
	float u = sqrt((vec1.x * vec1.x) + (vec1.y * vec1.y));
	cout << u << endl;
}

void vector2d::scalar(vector2d& vec1, vector2d& vec2)
{
	float dot = (vec1.x * vec2.x) + (vec1.y * vec2.y);

	cout << "Result of the scalar product of vectors:" << endl << dot << endl;
}

void vector2d::cosinus(vector2d& vec1, vector2d& vec2)
{
	float dot = (vec1.x * vec2.x) + (vec1.y * vec2.y);
	float u = sqrt((vec1.x * vec1.x) + (vec1.y * vec1.y));
	float u2 = sqrt((vec2.x * vec2.x) + (vec2.y * vec2.y));

	float cos = (dot / (u * u2));
	cout << "The cosine of the angle between the vectors:" << endl << cos << endl;
}

void vector2d::display(const char * const caption)
{
	cout << caption << endl << "Vector with coords:" << endl << "X = " << x << endl << "Y = " << y << endl;
}
int main(int argc, char *argv[])
{
	locale::global(locale(""));

	vector2d vector1;
	vector2d vector2;
	vector2d result_vector;
	int p;
	while (true)
	{
		cout << "========================Menu========================" << endl
			<< "\t1 - Addition of two vectors" << endl
			<< "\t2 - Subtraction of two vectors" << endl
			<< "\t3 - Calculate the length of a vector" << endl
			<< "\t4 - Scalar product of vectors" << endl
			<< "\t5 - The cosine of the angle between the vectors" << endl
			<< "\t0 - Exit" << endl
			<< "Your choice: ";
		cin >> p;
		system("cls");
		switch (p)
		{
		case 1:
			vector1.SetVector("Coords of vector 1:");
			vector2.SetVector("Coords of vector 2:");
			result_vector = vector1 + vector2;
			result_vector.display("=======================Result=======================");
			break;
		case 2:
			vector1.SetVector("Coords of vector 1:");
			vector2.SetVector("Coords of vector 2:");
			result_vector = vector1 - vector2;
			result_vector.display("=======================Result=======================");
			break;
		case 3:
			vector1.SetVector("Coords of vector:");
			result_vector.length(vector1);
			break;
		case 4:
			vector1.SetVector("Coords of vector 1:");
			vector2.SetVector("Coords of vector 2:");
			result_vector.scalar(vector1, vector2);
			break;
		case 5:
			vector1.SetVector("Coords of vector 1:");
			vector2.SetVector("Coords of vector 2:");
			result_vector.cosinus(vector1, vector2);
			break;
		case 0:
			exit(0);
			break;
		}
	}
	system("pause");
	return 0;
}
