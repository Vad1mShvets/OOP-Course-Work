#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include "ZalikovaKnyzhka.h"
#include <fstream>;

void Underline() {
	cout << "- - - - - - - - - - - - -" << endl;
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choise, perevirka, kontainer;

	int countEkzams = 0;
	cout << "Введіть кількість екзаменів: ";
	cin >> countEkzams;
	ZalikovaKnyzhka array(countEkzams);
	cout << endl;

	do {
		system("cls");
		cout << "Меню: " << endl;
		cout << "1 - Повна перевірка класів (викладач, студент, екзамен)" << endl;
		cout << "2 - Демонстрація роботи поліморфічного классу" << endl;
		cout << "3 - Пізнє зв'язування" << endl;
		cout << "4 - Глибоке копіювання" << endl;
		cout << "5 - Робота з контейнером 'Залікова книжка'" << endl;
		cout << "...\n0 - Вихід з программи" << endl;
		cout << endl;
		cin >> choise;
		switch (choise)
		{
		case 1: {
			do {
				system("cls");
				cout << "- Повна перевірка класів -" << endl;
				cout << "1 - Перевірка классу Vykladach" << endl;
				cout << "2 - Перевірка классу Student" << endl;
				cout << "3 - Перевірка классу Ekzamen" << endl;
				cout << "..." << "\n0 - Повернутися до головного меню" << endl;
				cout << endl;
				cin >> perevirka;
				switch (perevirka)
				{
				case 1: {
					system("cls");
					cout << "Тестування всьго классу Vykladach: " << endl;

					Vykladach v1("Шевченко", "професор"); //создание экземпляра класса конструктором с параметрами
					Vykladach v2; //создание экземпляра класса стандартным конструктором

					Underline();
					cout << "Створення екземпляру класу конструктором з параметрами" << endl;
					cout << "   !Виведення працює через метод классу" << endl;
					v1.OutputVykladach();
					Underline();

					cout << "Створення екземпляру класу конструктором за замовчуванням" << endl;
					v2.OutputVykladach();
					Underline();

					cout << "|Перевірка гетерів|" << endl;
					cout << "Прізвище викладача 1: " << v1.get_prizvyshe_vykl() << endl;
					cout << "Посада викладача 1: " << v1.get_posada() << endl;
					Underline();

					cout << "|Перевірка сетерів|" << endl;
					cout << "Заміна прізвища викладача 1 на будь-яке введене: ";
					string prizv;
					cin >> prizv;
					v1.set_prizvyshe_vykl(prizv);
					cout << "Заміна посади викладача 1 на 'доцент': " << endl;
					v1.set_posada("доцент");
					cout << "\n  Оновленна інформація студента1" << endl;
					v1.OutputVykladach();
					Underline();

					cout << "|Перевірка перевантажених операцій|" << endl;
					cout << "  Oператор присвоювання: v2 = v1" << endl;
					v2 = v1;
					cout << "\nВиведення 1-го та 2-го викладача перевантаженим оператором виводу: " << endl;
					cout << v1;
					cout << v2;
					cout << "\nСтворення 3-го викладача та заповнення його полів перевантаженим оператором вводу: " << endl;
					Vykladach v3;
					cin >> v3;
					Underline();

					cout << "\nСтворимо студента 4 та перевіремо метод для вводу його полів" << endl;
					Vykladach v4;
					v4.InputVykladach();
					Underline();

					cout << "\nВиведення 1-го, 2-го, 3-го та 4-го викладачів: " << endl << v1 << endl
						<< v2 << endl << v3 << endl << v4 << endl;

					system("pause");
					break;
				}

				case 2: {
					system("cls");
					cout << "Тестування всьго классу Student: " << endl;

					Student st1("КНТ-20-2", "Швець"); //создание экземпляра класса конструктором с параметрами
					Student st2; //создание экземпляра класса стандартным конструктором

					Underline();
					cout << "Створення екземпляру класу конструктором з параметрами" << endl;
					cout << "   !Виведення працює через метод классу" << endl;
					st1.OutputStudent();
					Underline();

					cout << "Створення екземпляру класу конструктором за замовчуванням" << endl;
					st2.OutputStudent();
					Underline();

					cout << "|Перевірка гетерів|" << endl;
					cout << "Прізвище студента 1: " << st1.get_prizvyshe_st() << endl;
					cout << "Група студента 1: " << st1.get_gruppa() << endl;
					Underline();

					cout << "|Перевірка сетерів|" << endl;
					cout << "Заміна прізвища студента 1 на будь-яке введене: ";
					string prizv;
					cin >> prizv;
					st1.set_prizvyshe_st(prizv);
					cout << "Заміна групи студента 1 на 'КНТ-20-3': " << endl;
					st1.set_gruppa("КНТ-20-3");
					cout << "\n  Оновленна інформація студента1" << endl;
					st1.OutputStudent();
					Underline();

					cout << "|Перевірка перевантажених операцій|" << endl;
					cout << "  Oператор присвоювання: st2 = st1" << endl;
					st2 = st1;
					cout << "\nВиведення 1-го та 2-го студента перевантаженим оператором виводу: " << endl;
					cout << st1;
					cout << st2;
					cout << "\nСтворення 3-го студента та заповнення його полів перевантаженим оператором вводу: " << endl;
					Student st3;
					cin >> st3;
					Underline();

					cout << "\nСтворимо студента 4 та перевіремо метод для вводу його полів" << endl;
					Student st4;
					st4.InputStudent();
					Underline();

					cout << "\nВиведення 1-го, 2-го, 3-го та 4-го студентів: " << endl << st1 << endl << st2 << endl << st3 << endl << st4 << endl;

					system("pause");
					break;
				}
				case 3: {
					cout << "Тестування всьго классу Ekzamen: " << endl;

					//создание экземпляра класса конструктором с параметрами
					Ekzamen ekz1("Труфанов", "КНТ-20-5", "Ізмаїлов", "професор", "МатАн", 50, "01.06.2021", 69);
					Ekzamen ekz2; //создание экземпляра класса стандартным конструктором
					cout << "Створення екземпляру класу конструктором з параметрами" << endl;
					cout << "   !Виведення працює через метод классу" << endl;
					ekz1.Output();
					cout << endl;
					ekz2.Output();
					Underline();

					cout << "|Перевірка гетерів на класі, створеному конструктором за замовчуванням|" << endl;
					cout << "Прізвище студента: " << ekz2.get_prizvyshe_st() << endl;
					cout << "Група: " << ekz2.get_gruppa() << endl;
					cout << "Прізвище викладача: " << ekz2.get_prizvyshe_vykl() << endl;
					cout << "Посада: " << ekz2.get_posada() << endl;
					cout << "Назва предмету: " << ekz2.get_nazva() << endl;
					cout << "Кулькість годин: " << ekz2.get_kilkistGod() << endl;
					cout << "Дата проведення: " << ekz2.get_dataProv() << endl;
					cout << "Оцінка: " << ekz2.get_otsinka() << endl;
					Underline();

					cout << "|Перевірка сетерів на класі, створеному конструктором за замовчуванням|" << endl;
					cout << "Заміна прізвища студента на будь-яке введене: ";
					string prizv;
					cin >> prizv;
					ekz2.set_prizvyshe_st(prizv);
					cout << "Заміна дати проведення на '21.06.2021': " << endl;
					ekz2.set_dataProv("21.06.2021");
					cout << "Заміна назви предмету на будь-яку введену: ";
					string nazva;
					cin >> nazva;
					ekz2.set_nazva(nazva);
					cout << "Заміна оцінки за екзамен на 78: " << endl;
					ekz2.set_otsinka(78);
					cout << "\n  Оновленна інформація екзамену" << endl;
					ekz2.Output();
					Underline();

					cout << "|Перевірка перевантажених операцій|" << endl;
					cout << "  Oператор присвоювання: ekz3 = ekz2" << endl;
					Ekzamen ekz3;
					ekz3 = ekz2;
					cout << "\nВиведення 2-го та 3-го екзаменів перевантаженим оператором виводу: " << endl;
					cout << ekz2;
					cout << ekz3;
					cout << "\nСтворення 4-го екзамену та заповнення його полів перевантаженим оператором вводу: " << endl;
					Ekzamen ekz4;
					cin >> ekz4;
					Underline();

					cout << "\nЗамінемо дані 2-го екзамену за допомогою методу вводу" << endl;
					ekz2.Input();
					Underline();

					cout << "\nВиведення 1-го, 2-го, 3-го та 4-го екхаменів: " << endl << ekz1 << endl << ekz2 << endl << ekz3 << endl << ekz4 << endl;

					system("pause");
					break;
				}
				case 0: {
					continue;
				}
				default: {
					cout << "Неіснуючий пункт меню!" << endl;
					system("pause");
					break;
				}

				}
			} while (perevirka != 0);
		case 0: {
			break;
		}
		default: {
			cout << "Неіснуючий пункт меню! " << endl;
			system("pause");
			break;
		}
		}
		case 2: {

			system("cls");

			cout << "Тестування поліморфічного кластера:" << endl;
			cout << "\nСтворюємо студента с прізвищем Шевченко" << endl;
			Student st;
			st.set_prizvyshe_st("Шевченко");
			Underline();
			st.OutputKlaster();
			Underline();

			cout << "Створюємо екзамен з параметрами конструктора за замовчуванням" << endl;
			Ekzamen ekz;
			Underline();
			ekz.OutputKlaster();

			Underline();
			cout << "\n  Створюємо посилання на клас студенту і виводимо його поля.\n   Потім присвоюємо посиланню клас екзамен і ще раз виводимо його поля.\n" << endl;

			Student* stud = &st;
			Underline();
			stud->OutputKlaster();
			stud = &ekz;
			Underline();
			stud->OutputKlaster();

			cout << endl;

			system("pause");
			break;
		}
		case 3: {
			Ekzamen* e = new Ekzamen();
			Student* s;
			e->Input();
			s = e;

			Underline();

			s->OutputKlaster();

			system("pause");
			break;
		}
		case 4: {
			Vykladach vykladach1;



			system("pause");
			break;
		}
		case 5: {
			do
			{
				system("cls");
				cout << "Робота з контейнером 'Залікова книжка'" << endl;

				cout << "1 - Заповнити залікову книжку" << endl;
				cout << "2 - Редагувати інформацію про екзамен" << endl;
				cout << "3 - Вивести інформацію про всі екзамени" << endl;
				cout << "4 - Вивести екзамени, за які НЕ було отримано мінімальний бал (60)" << endl;
				cout << "5 - Сортувати екзамени за оцінками" << endl;
				cout << "...\n0 - Повернутися до головного меню" << endl;

				cin >> kontainer;
				switch (kontainer)
				{

				case 1: {
					cout << "Створити екзамен у залікову книжку: " << endl;

					for (int i = 0; i < countEkzams; i++)
					{
						cout << "\nЕкзамен №" << i + 1 << endl;
						cin >> array[i];
					}

					system("pause");
					break;
				}
				case 2: {
					cout << "Редагувати інформацію про екзамен: " << endl;

					cout << "\n Редагувати екзамент №";
					int edit;
					cin >> edit;

					array[edit].Input();

					system("pause");
					break;
				}
				case 3: {

					cout << "Вивести інформацію про всі екзамени: " << endl;

					for (int i = 0; i < countEkzams; i++)
					{
						cout << "\nЕкзамен №" << i << endl;
						cout << array[i];
					}

					system("pause");
					break;
				}
				case 4: {

					cout << "Вивести всі екзамени, за які не було отримано мінімальний бал (60): " << endl;

					for (int i = 0; i < countEkzams; i++)
					{
						if (array[i].get_otsinka() < 60)
						{
							cout << "\nЕкзамен №" << i << endl;
							cout << array[i];
						}
					}

					system("pause");
					break;
				}
				case 5: {
					cout << "Сортувати екзамени за оцінками: " << endl;

					array.Sorting();

					for (int i = 0; i < countEkzams; i++)
					{
						cout << "\nЕкзамен №" << i << endl;
						cout << array[i];
					}

					system("pause");
					break;
				}
				case 0: {
					break;
				}
				default: {
					cout << "Неіснуючий пункт меню!" << endl;
					system("pause");
					continue;
				}
				}
			} while (kontainer != 0);
		}
		}

	} while (choise != 0);

	cin.get();
	return 0;
}