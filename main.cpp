#include <iostream>
#include<string>
#include<fstream>
#include<windows.h>
using namespace std;
void DataEntry(Data* (&d), int& n)
{
	FIO fio;
	Predmet predmet;

	cout << " Введите размер массива(количество объктов, которые хотите ввести): ";
	cin >> n;

	d = new Data[n];//памятья для данных

	for (int i = 0; i < n; i++) {
		cout << "Введите ФИО(снач. фамилию->имя->отчество, затем возраст учащегося и в его класс)" << endl;
		cin >> fio.familia >> fio.imya >> fio.otch >> fio.age >> fio.group;

		cout << "Введите предметы(сначала предмет затем оценку) -(max 2 предмета) ";
		cin >> predmet.phys >> predmet.gradep >> predmet.mat >> predmet.gradem;
		d[i].DataEntry(fio, predmet);

		cout << "_________________________________________\n";
	}
}

void DataReading(Data* (&d), int& n, string filename) //загрузка данных для файла
{
	ifstream reading(filename);

	if (reading) {
		FIO fio;
		Predmet predmet;

		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++) {
			reading >> fio.familia >> fio.imya >> fio.otch >> fio.age >> fio.group;

			reading >> predmet.phys >> predmet.gradep >> predmet.mat >> predmet.gradem;


			d[i].DataEntry(fio, predmet);
		}

		cout << "Данные успешно считаны" << endl;
	}
	else
		cout << "Ошибка при чтении" << endl;

	reading.close();
}

void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "Äàííûå ¹" << i + 1 << endl;

		d[i].Print();
		cout << "_________________________________________\n";
	}
}

void DataChange(Data* d, int n)
{
	FIO fio;
	Predmet predmet;
	int _n;

	cout << "Введите номер элемента для изменения (от 1 до " << n << "): ";
	cin >> _n;
	_n = _n - 1;

	if (_n >= 0 and _n < n) {
		ccout << "Введите ФИО(снач. фамилию->имя->отчество, затем возраст учащегося и в его класс)" << endl;
		cin >> fio.familia >> fio.imya >> fio.otch >> fio.age >> fio.group;

		cout << "Введите предметы(сначала предмет затем оценку) -(max 2 предмета) ";
		cin >> predmet.phys >> predmet.gradep >> predmet.mat >> predmet.gradem;
		d[_n].DataEntry(fio, predmet);
	}
	else
		cout << "Таких данных нет" << endl;
}

void Copy(Data* d_n, Data* d_o, int n)
{
	for (int i = 0; i < n; i++)
		d_n[i] = d_o[i];
}

void AddData(Data* (&d), int& n)
{
	FIO fio;
	Predmet predmet;
	Data* buf = new Data[n];
	int size = n, new_size = ++n;

	Copy(buf, d, size);

	d = new Data[new_size];

	Copy(d, buf, size);

	cout << "Введите ФИО(снач. фамилию->имя->отчество, затем возраст учащегося и в его класс)" << endl;
	cin >> fio.familia >> fio.imya >> fio.otch >> fio.age >> fio.group;

	cout << "Введите предметы(сначала предмет затем оценку) -(max 2 предмета) ";
	cin >> predmet.phys >> predmet.gradep >> predmet.mat >> predmet.gradem;

	d[size].DataEntry(fio, predmet);

	cout << "Данные обновлены!" << endl;

	delete[] buf;
}

void DeleteData(Data* (&d), int& n)
{
	int _n;
	Data* buf = new Data[n];

	cout << "Введите номер элемента для изменения (от 1 до " << n << "): ";
	cin >> _n;
	_n--;

	if (_n >= 0 and _n < n) {
		Copy(buf, d, n);
		int q = 0;
		n--;

		d = new Data[n];

		for (int i = 0; i <= n; i++) {
			if (i != n) {
				d[q] = buf[i];
				q++;
			}
		}

		cout << "Данные удалены" << endl;
	}
	else
		cout << "Номер введен неправильно" << endl;

	delete[] buf;
}
struct FIO {
	string familia, imya, otch, age, group;
};
struct Predmet {
	string mat, phys, gradem, gradep;
};
class data
{
private:
	FIO fio;
	Predmet predmet;
public:
	Data(); //создание пустого объекта
	Data(FIO fio_, Predmet predmet_); // объект с параметрами
	void Print();
	void DataEntry(FIO fio_, Predmet predmet_);
	// вывод полей из класса
	FIO GetFio() { return fio };
	Predmet GetPredmet() { return predmet };
	~Data
		//перезагрузка оператора
		Data& operator = (Data d_o);
	int _stateMenu;

	void Menu() {
		cout << "Выберите действие: " << endl
			<< "(0) Выход из программы" << endl
			<< "(1) Ввод данных" << endl
			<< "(2) Вывод данных" << endl
			<< "(3) Изменение данных" << endl
			<< "(4) Добавление данных" << endl
			<< "(5) Удаление данных" << endl
			<< "Ваш выбор: ";
		cin >> _stateMenu;
	}

	void main()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		Menu();
		int _actions;
		string filename;

		int _size = 0;
		Data* d = new Data[_size];

		while (_stateMenu != 0)
		{
			switch (_stateMenu)
			{
			case 1:
				system("cls");
				cout << "Введите путь к файлу: ";
				cin >> filename;
				DataReading(d, _size, filename);
			}
			system("pause");
			system("cls");
			Menu();
			break;

        case 2:
			system("cls");

			if (_size != 0)
				Print(d, _size);
			else
				cout << "Данные пусты" << endl;

			system("pause");
			system("cls");
			Menu();
			break;

		case 3:
			system("cls");

			if (_size != 0)
				DataChange(d, _size);
			else
				cout << "Данные пусты" << endl;

			system("pause");
			system("cls");
			Menu();
			break;

		case 4:
			system("cls");

			if (_size != 0)
				AddData(d, _size);
			else
				cout << "Данные пусты" << endl;

			system("pause");
			system("cls");
			Menu();
			break;

		case 5:
			system("cls");

			if (_size != 0)
				DeleteData(d, _size);
			else
				cout << "Данные пусты" << endl;

			system("pause");
			system("cls");
			Menu();
			break;

		}
	}

}