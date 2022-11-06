//IntroductionToOOP
#include<iostream>
using namespace std;

//Объектно-Ориентированное программирование на языке C++
//ООП
//OOP - Object-Oriented Programming

class Point
{
private:
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
};

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
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
#endif // STRUCT_POINT

	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
}

/*
----------------------------------------------------------
.  - оператор прямого доступа (Point operator)
-> - оператор косвенного доступа (Arrow operator)
----------------------------------------------------------
*/

/*
----------------------------------------------------------
				OOP concepts:
1. Encapsulation;
2. Inheritance;
3. Polymorphism;

				Encapsulation:
Модификаторы доступа
private:	закрытые поля, доступные только внутри класса
public:		открытые поля, доступные из любого места программы
protected:	защищенные поля, доступны внутри класса, и его дочерних классов


get/set-методы
get - взять, получить
set - задать, установить
----------------------------------------------------------
*/