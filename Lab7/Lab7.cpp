// Lab7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;
template<class T>
class vector
{
public:
	vector();
	~vector();
	void SetVector(const char * const caption);
	void display(const char * const caption);
	void add(vector *vec1, vector *vec2);
	void sub(vector *vec1, vector *vec2);
	void length(vector *vec1);
	void scalar(vector *vec1, vector *vec2);
	void cosinus(vector *vec1, vector *vec2);
private:
	T x, y;
};
template<class T>
vector<T>::vector()
{
	x = T(0);
	y = T(0);
}
template<class T>
vector<T>::~vector()
{
}
template<class T>
void vector<T>::SetVector(const char * const caption)
{
	cout << caption << endl;
	cout << "X = ";
	cin >> x;
	cout << "Y = ";
	cin >> y;
}
template<class T>
void vector<T>::add(vector *vec1, vector *vec2)
{
	x = vec1->x + vec2->x;
	y = vec1->y + vec2->y;
}
template<class T>
void vector<T>::sub(vector *vec1, vector *vec2)
{
	x = vec1->x - vec2->x;
	y = vec1->y - vec2->y;
}
template<class T>
void vector<T>::length(vector *vec1)
{
	cout << "Length of vector:" << endl;
	
	float u = sqrt((vec1->x * vec1->x) + (vec1->y * vec1->y));
	cout << u << endl;
}
template<class T>
void vector<T>::scalar(vector *vec1, vector *vec2)
{
	float dot = (vec1->x * vec2->x) + (vec1->y * vec2->y);
	
	cout << "Result of the scalar product of vectors:" << endl << dot << endl;
}
template<class T>
void vector<T>::cosinus(vector *vec1, vector *vec2)
{
	float dot = (vec1->x * vec2->x) + (vec1->y * vec2->y);
	float u = sqrt((vec1->x * vec1->x) + (vec1->y * vec1->y));
	float u2 = sqrt((vec2->x * vec2->x) + (vec2->y * vec2->y));
	
	float cos = (dot / (u * u2));
	cout << "The cosine of the angle between the vectors:" << endl << cos << endl;
}
template<class T>
void vector<T>::display(const char * const caption)
{
	cout << caption << endl	<< "Vector with coords:" << endl	<< "X = " << x << endl << "Y = " << y << endl;
}
int main(int argc, char *argv[])
{
	locale::global(locale(""));
	
	vector<float> *vector1 = new vector<float>;
	vector<float> *vector2 = new vector<float>;
	vector<float> *result_vector = new vector<float>;
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
			vector1->SetVector("Coords of vector 1:");
			vector2->SetVector("Coords of vector 2:");
			result_vector->add(vector1, vector2);
			result_vector->display("=======================Result=======================");
			break;
		case 2:
			vector1->SetVector("Coords of vector 1:");
			vector2->SetVector("Coords of vector 2:");
			result_vector->sub(vector1, vector2);
			result_vector->display("=======================Result=======================");
			break;
		case 3:
			vector1->SetVector("Coords of vector:");
			result_vector->length(vector1);
			break;
		case 4:
			vector1->SetVector("Coords of vector 1:");
			vector2->SetVector("Coords of vector:");
			result_vector->scalar(vector1, vector2);
			break;
		case 5:
			vector1->SetVector("Coords of vector:");
			vector2->SetVector("Coords of vector:");
			result_vector->cosinus(vector1, vector2);
			break;
		case 0:
			exit(0);
			break;
		}
	}
	system("pause");
	return 0;
}
