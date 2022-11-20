#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define WIDTH	27

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//				Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout.width(WIDTH);
		cout << std::left << "DefaultConstructor:" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout.width(WIDTH);
		cout << std::left << "SingleArgumentConstructor:" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout.width(WIDTH);
		cout << std::left << "Constructor:" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout.width(WIDTH);
		cout << std::left << "Constructor:" << this << endl;
	}
	~Fraction()
	{
		cout.width(WIDTH);
		cout << std::left << "Destructor:" << this << endl;
	}

	//				Methods:
	void to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
	}
	void to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
	}

	void print()const
	{
		/*
				1/2
				5
				5 0/2
		*/
		if (integer)cout << integer << " ";
		if (numerator)
		{
			cout << numerator << "/" << denominator;
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};

//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;		//Default constructor
	A.print();

	Fraction B = 5;	//Single-argument constructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	D.to_improper();
	D.print();

	D.to_proper();
	D.print();
#endif // CONSTRUCTORS_CHECK

	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	Fraction C = A * B;
	C.print();
}

/*
------------------------------------------------------------
				Operators overloading rules:
1. Перегрузить можно только существующие операторы, 
   создавать новые операторы невозможно!!!
   Например:
   +  - перегружается;
   ++ - перегружается;
   *  - перегружается;
   ** - НЕ перегружается;
2. Не все существующие операторы можно перегрузить.
   НЕ перегружаются:
	?: - Conditional ternary;
	:: - Оператор разрешения видимости (Scope operator)
	.  - Оператор прямого доступа (Point operator)
	.* - Pointer to member selection
	#  - Preprocessor directive
	## - Preprocessor concatenation
3. Перегруженные операторы сохраняют приоритет;
4. Переопределить поведение операторов со встроенными типами НЕВОЗМОЖНО!!!
------------------------------------------------------------
		type operator@(parameters)
		{
			group-of-statements;
		}
------------------------------------------------------------
*/