#include "Vykladach.h";
using namespace std;

//гетери
string Vykladach::get_prizvyshe_vykl() { return prizvyshe_vykl; }
string Vykladach::get_posada() { return posada; }

//сетери
void Vykladach::set_prizvyshe_vykl(string set_prizvyshe) { prizvyshe_vykl = set_prizvyshe; }
void Vykladach::set_posada(string set_posada) { posada = set_posada; }

void Vykladach::OutputVykladach() { //метод для виводу інформації про викладача
	cout << "  Прізвище викладача: " << get_prizvyshe_vykl() << endl;
	cout << "  Посада: " << get_posada() << endl;
}

void Vykladach::InputVykladach() { //метод для вводу полів данних викладача
	cout << "  Прізвище викладача: ";
	string prizv;
	cin >> prizv;
	set_prizvyshe_vykl(prizv);
	cout << "  Посада: ";
	string pos;
	cin >> pos;
	set_posada(pos);
}

Vykladach::Vykladach() //контруктор за замовчуванням
{
	prizvyshe_vykl = "невідомо";
	posada = "невідомо";
}
Vykladach::Vykladach(string prizv, string pos) //контруктор з параметрами
{
	prizvyshe_vykl = prizv;
	posada = pos;
}

Vykladach::Vykladach(const Vykladach& vykladach) { //конструктор копіювання
	prizvyshe_vykl = vykladach.prizvyshe_vykl;
	posada = vykladach.posada;
}

Vykladach::~Vykladach() //деструктор
{

}

Vykladach& Vykladach::operator=(const Vykladach& other) { //перевантаження операції присвоювання
	this->prizvyshe_vykl = other.prizvyshe_vykl;
	this->posada = other.posada;
	return(*this);
}

ostream& operator<<(ostream& out, const Vykladach& vykladach) { //перевантаження операції виводу
	out << "   Прізвище викладача: " << vykladach.prizvyshe_vykl << endl;
	out << "   Посада: " << vykladach.posada << endl;

	return out;
}

istream& operator>>(istream& in, Vykladach& vykladach) { //перевантаження операції вводу
	cout << "Прізвище викладача: ";
	in >> vykladach.prizvyshe_vykl;
	cout << "Посада: ";
	in >> vykladach.posada;

	return in;
}