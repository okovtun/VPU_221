#include<iostream>
using namespace std;

class Vehicle
{
	int speed;
public:
	virtual void move() = 0;	//����� ����������� �����
};

class GroundVehicle :public Vehicle
{

};

class WaterVehicle :public Vehicle
{

};

class AirVehicle :public Vehicle
{
	int height;
};

class Car :public GroundVehicle
{
public:
	void move()
	{
		cout << "������ ���� �� ������� �������" << endl;
	}
};

class Bike :public GroundVehicle
{
public:
	void move()
	{
		cout << "Harley Devidson - The best";
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Vehicle v;
	//GroundVehicle car;

	Car car;
	car.move();

	Bike hd;
	hd.move();
}