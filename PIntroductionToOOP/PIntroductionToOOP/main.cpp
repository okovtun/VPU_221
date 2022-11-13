//IntroductionToOOP
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//Объектно-Ориентированное программирование на языке C++
//ООП
//OOP - Object-Oriented Programming

class Point
{
	double x;
	double y;
public:
	//snake_case_style
	//camelCaseStyle
	//pascalCaseStyle
	//smallCamel
	//BigCamel
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

	//				Constructors:
	/*Point()
	{
		x = y = double();//значение по умолчанию для double
		cout << "Constructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1argConstructor:" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//				Methods:
	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK

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

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << "Расстояние от точки 'A' до точки 'B':\t" << A.distance(B) << endl;
	cout << "Расстояние от точки 'B' до точки 'A':\t" << B.distance(A) << endl;
	cout << "Расстояние между точками 'A' и 'B':\t" << distance(A, B) << endl;
	cout << "Расстояние между точками 'B' и 'A':\t" << distance(B, A) << endl;
#endif // DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHECK
	Point A;	//Default constructor
	A.print();

	Point B = 5;//Single-argument constructor
	B.print();

	Point C(8);	//Single-argument constructor
	C.print();

	Point D(5, 8);//Parametrised constructor
	D.print();

	Point E = D;
	E.print();	//CopyConstructor  
#endif // CONSTRUCTORS_CHECK

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

/*
----------------------------------------------------------
1. Constructor	- это метод, кторый создает объект, а именно....;
	-с параметрами;
	-без параметров;
	-по умолчанию - это конструктор, КОТОРЫЙ МОЖЕТ БЫТЬ ВЫЗВАН без параметров;
	-Конструктор копирования - это конструктор, который копирует объект;
	-Конструктор переноса;
2. ~Destructor	- это метод, который уничтожает объект по завершении его времени жизни;
3. Assignment operator;
----------------------------------------------------------
*/