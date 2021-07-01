#include <iostream>
#include <string>
using namespace std;

class Vykladach {
protected:
	string prizvyshe_vykl;
	string posada;
public:
	//геттери
	string get_prizvyshe_vykl();
	string get_posada();

	//сеттери
	void set_prizvyshe_vykl(string set_prizvyshe);
	void set_posada(string set_posada);
	
	void OutputVykladach(); //метод для виводу інформації про викладача
	void InputVykladach(); //метод для вводу полів данних викладача
	
	Vykladach(); //конструктор за замовчуванням
	Vykladach(string prizv, string pos); //конструктор з параметрами
	Vykladach(const Vykladach& vykladach); //конструктор копіювання

	//деструктори
	~Vykladach();

	//перегрузки операцій
	Vykladach& operator=(const Vykladach& other);
	friend ostream& operator<<(ostream& out, const Vykladach& vykladach);
	friend istream& operator>>(istream& in, Vykladach& vykladach);
};