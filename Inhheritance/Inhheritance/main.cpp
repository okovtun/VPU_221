#include<iostream>
#include<string>
using namespace std;

#define delimiter "\n----------------------------\n"

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	//						Constructor:
	Human(const std::string& last_name, const std::string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//						Methods:
	virtual std::ostream& info(std::ostream& os)const
	{
		return os << last_name << " " << first_name << " " << age;
	}
};
std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.info(os);
	//return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age();
}

class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating;		//успеваемость
	double attendance;	//посещаемость
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	//				Constructors:
	Student
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, double rating, double attendance
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//					Methods:
	std::ostream& info(std::ostream& os)const
	{
		return Human::info(os) << " " << speciality << " " << group << " " << rating << " " << attendance;
	}
};

class Teacher :public Human
{
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}

	//							Constructors:
	Teacher
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		std::cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		std::cout << "TDestructor:\t" << this << endl;
	}

	//				Methods:
	std::ostream& info(std::ostream& os)const
	{
		return Human::info(os) << " " << speciality << " " << experience;
	}
};

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subhect()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	Graduate
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, double rating, double attendance,
		const std::string subject
	) :Student(last_name, first_name, age, speciality, group, rating, attendance)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	std::ostream& info(std::ostream& os)const
	{
		return Student::info(os) << " " << subject;
	}
};

//#define INHERITANCE
#define POLYMORPHISM	//многоформенность (poly - много, morphis - форма)

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE
	Human human("Montana", "Antonio", 25);
	human.info();

	Student stud("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 90, 87);
	stud.info();

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	teacher.info();

	Graduate grad("Schreder", "Hank", 40, "Criminalistic", "OBN", 95, 90, "How to catch Heizenberg");
	grad.info();
#endif // INHERITANCE

#ifdef POLYMORPHISM
	//Ad-hoc polymorphism		(Compile-time polymorphism)
	//Inclusion polymorphism	(Runtime-polymorphism)
	/*
		1. Указатели на базовый класс;
			Generalisation - обобщение
			UPcast - приведение дочернего объекта к базовоу типу
		2. Виртуальные методы;
			Виртуальным называется метод, который может быть переопределен в дочернем классе.
			Для того чтобы сделать метод виртуальным, перед ним достаточно написать ключевое слово virtual
	*/

	//Generalisation (UPcast) - переход от чего-то конктретного, к чему-то абстрактному.
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 90, 87),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Schreder", "Hank", 40, "Criminalistic", "OBN", 95, 90, "How to catch Heizenberg")
	};
	cout << delimiter << endl;
	//Specialisation (Уточнение)
	//Downcast - приведение от общего типа к частному типу
	//Downcast - это переход от чего-то более абстрактого к более конкретному.
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		cout << typeid(*group[i]).name() << ":\n";
		//group[i]->info();
		cout << *group[i] << endl;
		cout << delimiter << endl;
	}

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
#endif // POLYMORPHISM

}