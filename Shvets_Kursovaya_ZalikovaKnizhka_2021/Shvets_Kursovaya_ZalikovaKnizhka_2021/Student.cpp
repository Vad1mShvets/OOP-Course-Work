#include "Student.h";
using namespace std;

//гетери
string Student::get_gruppa() { return gruppa; }
string Student::get_prizvyshe_st() { return prizvyshe_stud; }

//сетери
void Student::set_gruppa(string set_gruppa) {
		gruppa = set_gruppa;
}
void Student::set_prizvyshe_st(string set_prizvyshe) { prizvyshe_stud = set_prizvyshe; }

Student::Student() //контруктор за замовчуванням
{
	gruppa = "невідома";
	prizvyshe_stud = "невідоме";
}
Student::Student(string g, string p) //контруктор з параметрами
{
	gruppa = g;
	prizvyshe_stud = p;
}

Student::Student(const Student& student) //контруктор копіювання
{
	gruppa = student.gruppa;
	prizvyshe_stud = student.prizvyshe_stud;
}

Student::~Student() //деструктор
{

}

void Student::OutputStudent() { //метод для виводу інформації про студента
	cout << "  Група: " << get_gruppa() << endl;
	cout << "  Прізвище студента: " << get_prizvyshe_st() << endl;
}

void Student::InputStudent() { //метод для вводу полів данних студента
	cout << "  Група: ";
	string grp;
	cin >> grp;
	set_gruppa(grp);
	cout << "  Прізвище студента: ";
	string przv;
	cin >> przv;
	set_prizvyshe_st(przv);
}

void Student::OutputKlaster() {
	cout << "  Прізвище студента: " << get_prizvyshe_st() << endl;
}

Student& Student::operator=(const Student& other) { //перевантаження операції присвоювання
	this->gruppa = other.gruppa;
	this->prizvyshe_stud = other.prizvyshe_stud;
	return(*this);
}

ostream& operator<<(ostream& out, const Student& student) { //перевантаження операції виводу
	out << "  Група: " << student.gruppa << endl;
	out << "  Прізвище студента: " << student.prizvyshe_stud << endl;

	return out;
}

istream& operator>>(istream& in, Student& student) { //перевантаження операції вводу
	cout << "Група: ";
	in >> student.gruppa;
	cout << "Прізвище студента: ";
	in >> student.prizvyshe_stud;

	return in;
}