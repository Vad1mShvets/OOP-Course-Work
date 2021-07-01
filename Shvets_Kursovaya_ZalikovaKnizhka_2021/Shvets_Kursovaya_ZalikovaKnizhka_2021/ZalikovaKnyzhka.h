#include <iostream>
#include "Ekzamen.h"
using namespace std;

class ZalikovaKnyzhka {
private:
	int n;
	Ekzamen *array;
public:
	ZalikovaKnyzhka();
	ZalikovaKnyzhka(int count);
	~ZalikovaKnyzhka();

    class Iterator {
        Ekzamen* ekzamen;
    public:
        Iterator(Ekzamen* ekz);
        Ekzamen& get();
        bool operator>(const Iterator& it);
        bool operator<(const Iterator& it);
        Ekzamen& operator+(int n);
        Ekzamen& operator-(int n);
        Ekzamen& operator++(int);
        Ekzamen& operator--(int);
        Ekzamen& operator++();
        Ekzamen& operator--();
        bool operator!=(const Iterator& a);
        bool operator==(const Iterator& a);
        Ekzamen& operator*();
        Iterator& operator+=(int n);
        Iterator& operator-=(int n);
    };
    Iterator beg();
    Iterator end();

	void Erase();

	Ekzamen& operator[](int index);

	int getLength();
	void Resize(int newLength);

	void InsertBefore(Ekzamen& value, int index);
	void InsertAtTheEnd(Ekzamen& value);
	void InsertAtTheBeginning(Ekzamen& value);
    void Remove(int index);
    void Sorting();
	void OutputKnyzhka();
};
