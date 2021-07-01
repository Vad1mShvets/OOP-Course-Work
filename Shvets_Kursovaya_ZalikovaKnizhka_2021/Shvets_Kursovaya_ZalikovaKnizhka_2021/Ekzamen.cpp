#include "Ekzamen.h"
using namespace std;

string Ekzamen::get_nazva() { return nazvaPredmetu; }
float Ekzamen::get_kilkistGod() { return kilkistGod; }
string Ekzamen::get_dataProv() { return dataProvedennya; }
int Ekzamen::get_otsinka() { return otsinka; }

void Ekzamen::set_nazva(string nazva) { nazvaPredmetu = nazva; }
void Ekzamen::set_kilkistGod(float kilkist) { kilkistGod = kilkist; }
void Ekzamen::set_dataProv(string data) { dataProvedennya = data; }
void Ekzamen::set_otsinka(int otsink) { otsinka = otsink; }

Ekzamen::Ekzamen() {
	prizvyshe_stud = "невідомо";
	gruppa = "невідома";
	prizvyshe_vykl = "невідомо";
	posada = "невідома";
	nazvaPredmetu = "невідома";
	kilkistGod = 0;
	dataProvedennya = "01.01.1970";
	otsinka = 0;
}

Ekzamen::Ekzamen(const Ekzamen& ekz) {
	prizvyshe_stud = ekz.prizvyshe_stud;
	gruppa = ekz.gruppa;
	prizvyshe_vykl = ekz.prizvyshe_vykl;
	posada = ekz.posada;
	nazvaPredmetu = ekz.nazvaPredmetu;
	kilkistGod = ekz.kilkistGod;
	dataProvedennya = ekz.dataProvedennya;
	otsinka = ekz.otsinka;
}

Ekzamen::Ekzamen(string prizvStud, string grp, string prizvVykl, string pos, string nazvaP, float kilGod, string data, int ots) {
	prizvyshe_stud = prizvStud;
	gruppa = grp;
	prizvyshe_vykl = prizvVykl;
	posada = pos;
	nazvaPredmetu = nazvaP;
	kilkistGod = kilGod;
	dataProvedennya = data;
	otsinka = ots;
}
Ekzamen::~Ekzamen() {

}

void Ekzamen::Output() {
	OutputStudent();
	OutputVykladach();
	cout << "  Назва предмету: " << get_nazva() << endl;
	cout << "  Кулькість годин: " << get_kilkistGod() << endl;
	cout << "  Дата проведення: " << get_dataProv() << endl;
	cout << "  Оцінка: " << get_otsinka() << endl;
}

void Ekzamen::Input() {
	cout << "Прізвище студента: ";
	cin >> prizvyshe_stud;
	cout << "Група: ";
	cin >> gruppa;
	cout << "Прізвище викладача: ";
	cin >> prizvyshe_vykl;
	cout << "Посада: ";
	cin >> posada;
	cout << "Назва предмету: ";
	cin >> nazvaPredmetu;

	cout << "Кулькість годин: ";
	try {
		cin >> kilkistGod;
		if (kilkistGod < 0)
		{
			throw - 1;
		}
	}
	catch (int errorNum) {
		kilkistGod = 0;
		cout << "Помилка! Кількість годин не може бути нижче нуля, " << endl << " цьому полю присвоєно 0\n" << endl;
	}

	cout << "Дата проведення: ";
	cin >> dataProvedennya;

	cout << "Оцінка: ";
	try {
		cin >> otsinka;
		if (otsinka < 0)
		{
			throw - 1;
		}
	}catch (int errorNum) {
		otsinka = 0;
		cout << "Помилка! Оцінка не може бути нижче нуля, " << endl << " цьому полю присвоєно 0\n" << endl;
	}

}

void Ekzamen::OutputKlaster() {
	cout << "  Прізвище студента: " << get_prizvyshe_st() << endl;
	cout << "  Назва предмету: " << get_nazva() << endl;
}

ostream& operator<<(ostream& out, const Ekzamen& ekz) { //перевантаження операції виводу
	out << "  Прізвище студента: " << ekz.prizvyshe_stud << endl;
	out << "  Група: " << ekz.gruppa << endl;
	out << "  Прізвище викладача: " << ekz.prizvyshe_vykl << endl;
	out << "  Посада: " << ekz.posada << endl;
	out << "  Назва предмету: " << ekz.nazvaPredmetu << endl;
	out << "  Кулькість годин: " << ekz.kilkistGod << endl;
	out << "  Дата проведення: " << ekz.dataProvedennya << endl;
	out << "  Оцінка: " << ekz.otsinka << endl;

	return out;
}

istream& operator>>(istream& in, Ekzamen& ekz) { //перевантаження операції вводу
	cout << "  Прізвище студента: ";
	in >> ekz.prizvyshe_stud;
	cout << "  Група: ";
	in >> ekz.gruppa;
	cout << "  Прізвище викладача: ";
	in >> ekz.prizvyshe_vykl;
	cout << "  Посада: ";
	in >> ekz.posada;
	cout << "Назва предмету: ";
	in >> ekz.nazvaPredmetu;

	cout << "Кулькість годин: ";
	try {
		in >> ekz.kilkistGod;
		if (ekz.kilkistGod < 0)
		{
			throw - 1;
		}
	}
	catch (int errorNum) {
		ekz.kilkistGod = 0;
		cout << "Помилка! Кількість годин не може бути нижче нуля, " << endl << " цьому полю присвоєно 0\n" << endl;
	}

	cout << "Дата проведення: ";
	in >> ekz.dataProvedennya;

	cout << "Оцінка: ";
	try {
		in >> ekz.otsinka;
		if (ekz.otsinka < 0)
		{
			throw - 1;
		}
	}
	catch (int errorNum) {
		ekz.otsinka = 0;
		cout << "Помилка! Оцінка не може бути нижче нуля, " << endl << " цьому полю присвоєно 0\n" << endl;
	}

	return in;
}