#include "ZalikovaKnyzhka.h";
#include <cassert>;

ZalikovaKnyzhka::ZalikovaKnyzhka() {
	n = 0;
	array = nullptr;
}
ZalikovaKnyzhka::ZalikovaKnyzhka(int count) : n(count) {

	assert(count >= 0);
	
	if (count > 0)
	{
		array = new Ekzamen[count];
	}
	else {
		array = nullptr;
	}
}
ZalikovaKnyzhka::~ZalikovaKnyzhka() {
	delete[] array;
}

ZalikovaKnyzhka::Iterator::Iterator(Ekzamen* ekz) { ekzamen = ekz; };
Ekzamen& ZalikovaKnyzhka::Iterator::get() { return *ekzamen; }
bool ZalikovaKnyzhka::Iterator::operator>(const Iterator& it) { return ekzamen > it.ekzamen; }
bool ZalikovaKnyzhka::Iterator::operator<(const Iterator& it) { return ekzamen < it.ekzamen; }
Ekzamen& ZalikovaKnyzhka::Iterator::operator+(int n) { return*(ekzamen + n); }
Ekzamen& ZalikovaKnyzhka::Iterator::operator-(int n) { return*(ekzamen - n); }
Ekzamen& ZalikovaKnyzhka::Iterator::operator++(int) { return*(ekzamen++); }
Ekzamen& ZalikovaKnyzhka::Iterator::operator--(int) { return*(ekzamen--); }
Ekzamen& ZalikovaKnyzhka::Iterator::operator++() { return*++ekzamen; }
Ekzamen& ZalikovaKnyzhka::Iterator::operator--() { return*--ekzamen; }
bool ZalikovaKnyzhka::Iterator::operator!=(const Iterator& a) { return ekzamen != a.ekzamen; }
bool ZalikovaKnyzhka::Iterator::operator==(const Iterator& a) { return ekzamen == a.ekzamen; }
Ekzamen& ZalikovaKnyzhka::Iterator::operator*() { return *ekzamen; }
ZalikovaKnyzhka::Iterator& ZalikovaKnyzhka::Iterator::operator+=(int n) { ekzamen += n; return *this; }
ZalikovaKnyzhka::Iterator& ZalikovaKnyzhka::Iterator::operator-=(int n) { ekzamen -= n; return *this; }

ZalikovaKnyzhka::Iterator ZalikovaKnyzhka::beg() { return Iterator(array); }
ZalikovaKnyzhka::Iterator ZalikovaKnyzhka::end() { return Iterator(array + n); }

void ZalikovaKnyzhka::Erase() {
	delete[] array;
	array = nullptr;
	n = 0;
}

Ekzamen& ZalikovaKnyzhka::operator[](int index) {
	assert(index >= 0 && index < n);
	return array[index];
}

int ZalikovaKnyzhka::getLength() { return n; }

void ZalikovaKnyzhka::Resize(int newLength) { //зміна розміру массима. всі існуючі елементи видаляються
	if (newLength == n)
	{
		return;
	}

	if (newLength <= 0)
	{
		Erase();
		return;
	}

	array = new Ekzamen[newLength];
	n = newLength;
}

//фунція дозволяє додавати елемент перед елементом з індексом, що може ввести користувач
void ZalikovaKnyzhka::InsertBefore(Ekzamen& value, int index) {
	assert(index >= 0 && index <= n); //перевірка коректності переданого індексу

	Ekzamen* data = new Ekzamen[n + 1]; //створюємо новий массив на один елемент більше, ніж старий

	//копіюємо всі елементи аж до index'y
	for (int before = 0; before < n; before++)
	{
		data[before] = array[before];
	}

	//вставляємо наш новий елемент в новий массив
	data[index] = value;

	//копіюємо всі значення після вставленого елемента
	for (int after = index; after < n; after++)
	{
		data[after + 1] = array[after];
	}

	//видаляємо старий массив та використовуємо замість нього новий
	delete[] array;
	array = data;
	n++;
}

void ZalikovaKnyzhka::InsertAtTheEnd(Ekzamen& value) {
	InsertBefore(value, n);
}

void ZalikovaKnyzhka::InsertAtTheBeginning(Ekzamen& value) {
	InsertBefore(value, 0);
}

void ZalikovaKnyzhka::Sorting() { //метод для сортування масиву
	Ekzamen tmp;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (array[i].get_otsinka() > array[j].get_otsinka()) {
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}

void ZalikovaKnyzhka::OutputKnyzhka() {
	for (int i = 0; i < n; i++)
	{
		cout << "- - - - - - - - - -" << endl;
		cout << array[i] << endl;
		cout << "- - - - - - - - - -" << endl;
	}
}