//IntroductionToOOP
#include<iostream>
using namespace std;

//Объектно-Ориентированное программирование на языке C++
//ООП
//OOP - Object-Oriented Programming

class Point
{
	double x;
	double y;
};

void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello OOP" << endl;

	//type name;
	int a;		//объявление переменной 'a' типа 'int'
	Point A;	//объявление переменной 'A' типа 'Point'
				//создание объекта 'A' структуры 'Point'
				//объявление экземпляра 'A' структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
}

/*
----------------------------------------------------------
.  - оператор прямого доступа (Point operator)
-> - оператор косвенного доступа (Arrow operator)
----------------------------------------------------------
*/