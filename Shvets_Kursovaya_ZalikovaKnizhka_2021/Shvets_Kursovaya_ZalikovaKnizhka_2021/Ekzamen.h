#include "Student.h"
#include "Vykladach.h"
using namespace std;

class Ekzamen : public Student, public Vykladach {

protected:
	string nazvaPredmetu;
	float kilkistGod;
	string dataProvedennya;
	int otsinka;

public:
	string get_nazva();
	float get_kilkistGod();
	string get_dataProv();
	int get_otsinka();

	void set_nazva(string nazva);
	void set_kilkistGod(float kilkist);
	void set_dataProv(string data);
	void set_otsinka(int otsink);

	Ekzamen();
	Ekzamen(string prizvStud, string grp, string prizvVykl, string pos, string nazvaP, float kilGod, string data, int ots);
	Ekzamen(const Ekzamen& ekz);
	~Ekzamen();

	void Output();
	void Input();
	void OutputKlaster()override;

	friend ostream& operator<<(ostream& out, const Ekzamen& ekz); //перевантаження операції виводу
	friend istream& operator>>(istream& in, Ekzamen& ekz); //перевантаження операції вводу
};
