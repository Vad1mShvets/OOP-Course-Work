#include <iostream>
#include <string>
using namespace std;

class Student 
{
protected:
	string gruppa;
	string prizvyshe_stud;
public:
	string get_gruppa();
	string get_prizvyshe_st();

	void set_gruppa(string set_gruppa);
	void set_prizvyshe_st(string set_prizvyshe);

	Student(); //конструктор за замовчуванням
	Student(string gruppa, string prizvyshe); //констуктор з параметрами
	Student(const Student& student); //конструктор копіювання

	//деструктори
	~Student();

	//методи
	void OutputStudent();
	void InputStudent();
	virtual void OutputKlaster();

	//перегрузки операцій
	Student& operator=(const Student& other);
	friend ostream& operator<<(ostream& out, const Student& student);
	friend istream& operator>>(istream& in, Student& student);
};