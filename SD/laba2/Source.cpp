#include <iostream>
#include <iomanip>

#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

struct EM
{
	string name;
	string work;
	string address;
	string phonenum;
};

struct WK
{
	string name;
	string work;
	string address;
	string phonenum;
};

struct Deal
{
	string num;
	string worker;
	string employer;
};

int _stateMenu;
const int N = 1000;

void Writedown_E(EM employer[])
{
	setlocale(LC_ALL, "ru");
	int num;
	do
	{
		cout << "Введите номер работадателя: "; cin >> num;
	} 
	while (num < 1 || num > N);
	fflush(stdin);
		cout << "\tВакансия №" << num << endl;
		cout << "Введите ФИО работадателя:\n";
		cin >> employer[num].name;
		cout << "Введите тип работы:\n";
		cin >> employer[num].work;
		cout << "Введите адрес:\n";
		cin >> employer[num].address;
		cout << "Введите телефон:\n";
		cin >> employer[num].phonenum;
		cout << "\n\n";
		cout << "Записано" << endl;
		system("pause");
}

void Writedown_W(WK worker[])
{
	setlocale(LC_ALL, "ru");
	int num2;
	do
	{
		cout << "Введите номер работника: "; cin >> num2;
	}
	while (num2 < 1 || num2 > N);
	fflush(stdin);
		cout << "\tВакансия №" << num2 << endl;
		cout << "Введите ФИО работадателя:\n";
		cin >> worker[num2].name;
		cout << "Введите тип работы:\n";
		cin >> worker[num2].work;
		cout << "Введите адрес:\n";
		cin >> worker[num2].address;
		cout << "Введите телефон:\n";
		cin >> worker[num2].phonenum;
		cout << "\n\n";
		system("pause");
}

void Output_E(EM employer[])
{
	int empl;
	cout << "Введите номер работадателя, которого вы хотите вывести:\n";
	cin >> empl;
	int i = empl;
	cout << "\tРаботадатель №" << empl << '\n';
	cout << "ФИО: " << employer[i].name << '\n';
	cout << "Тип  работы: " << employer[i].work << '\n';
	cout << "Адрес: " << employer[i].address << '\n';
	cout << "Телефон: " << employer[i].phonenum << "\n\n\n";
	system("pause");
}

void Output_W(WK worker[])
{
	int work;
	cout << "Введите номер работника, которого вы хотите вывести:\n";
	cin >> work;
	int i = work;
	cout << "\tПортфолио №" << work << '\n';
	cout << "ФИО : " << worker[i].name << '\n';
	cout << "Тип работы: " << worker[i].work << '\n';
	cout << "Адрес: " << worker[i].address << '\n';
	cout << "Телефон: " << worker[i].phonenum << "\n\n\n";
	system("pause");
}

void Output_D(Deal number[])
{
	int deal;
	cout << "Введите номер сделки: ";
	cin >> deal;
	int i = deal;
	cout << "Номер сделки: " << number[i].num << '\n';
	cout << "Работадатель номер: " << number[i].employer << '\n';
	cout << "Работник номер: " << number[i].worker << '\n';
	system("pause");
}

void File_E(EM employer[])
{
	int num;
	cout << "Введите номер работадателя: "; cin >> num;
	ofstream file1("emlpoyer.txt", ios::app);
	     file1 << "\tВакансия №" << num;
	     file1 << "\nВведите ФИО работадателя:";
	     file1 << employer[num].name;
	     file1 << "\nВведите тип работы:";
	     file1 << employer[num].work;
	     file1 << "\nВведите адрес:";
	     file1 << employer[num].address;
	     file1 << "\nВведите телефон:";
	     file1 << employer[num].phonenum << "\n\n";
		 cout << "Записано" << endl;
		 system("pause");
}

void File_W(WK worker[])
{
	int num2;
	cout << "Введите номер работника: "; cin >> num2;
	ofstream file2("worker.txt");
		file2 << "\tВакансия №" << num2 << '\n';
		file2 << "\nВведите ФИО работадателя:";
		file2 << worker[num2].name;
		file2 << "\nВведите тип работы:";
		file2 << worker[num2].work;
		file2 << "\nВведите адрес:";
		file2 << worker[num2].address;
		file2 << "\nВведите телефон";
		file2 << worker[num2].phonenum << "\n\n";
		cout << "Записано" << endl;
		system("pause");
}

void search(EM employer[], WK worker[], Deal number[])
{
	int deal;
	int g;
	cout << "Сколько вы хотите просмотреть вакансий? "; cin >> g;
	ofstream file3("doc.txt", ios::app);
	for (int i = 1; i < g; i++)
	{
		for (int j = 1; j < g; j++)
		{
			if (employer[i].work == worker[j].work)
				if (employer[i].address == worker[j].address)
				{
					cout << "Вакансия" << i << " и портфолио номер " << j << " совпадают." << endl;
					cout << "Введите номер сделки"; cin >> deal;
					number[deal].num;
					number[i].employer;
					number[j].worker;
					file3 << "Сделка № " << deal << endl;
					file3 << "Работадатель № " << i << " и работник № " << j << endl;
					cout << "Сделка записана в документ" << endl;
					goto go;
				}
			else
			cout << "Нет совпадений" << endl;
		}
	}
go:
	cout << "Нет совпадений" << endl;
	system("pause");
}

void deleteE(EM employer[])
{
	int numCin;
	cout << "Введите порядковый номер работадателя, информацию о котором Вы хотите удалить:\n";
	cin >> numCin;
	cout << '\n';
	int i = numCin;
	employer[i].name = ' ';
	employer[i].work = ' ';
	employer[i].address = ' ';
	employer[i].phonenum = ' ';
	cout << '\n';
}

void deleteW(WK worker[])
{
	int numCin;
	cout << "Введите порядковый номер работника, информацию о котором Вы хотите удалить:\n";
	cin >> numCin;
	cout << '\n';
	int i = numCin;
	worker[i].name = ' ';
	worker[i].work = ' ';
	worker[i].address = ' ';
	worker[i].phonenum = ' ';
	cout << '\n';
}

void menu()
{
	setlocale(LC_ALL, "ru");
	EM employer[N];
	WK worker[N];
	Deal number[N];
	int count;
	cout << "1. Записать работадателя " << endl;
	cout << "2. Записать работника " << endl;
	cout << "3. Найти соикателей и записать документ " << endl;
	cout << "4. Просмотерть вакансии " << endl;
	cout << "5. Просмотреть заявки работников " << endl;
	cout << "6. Просмотреть сделки " << endl;
	cout << "7. Записать работадателя в файл " << endl;
	cout << "8. Записать работника в файл " << endl;
	cout << "9. Удалить данные работодателя " << endl;
	cout << "10. Удалить данные работника" << endl;
	cout << "11. Выход из программы " << endl;
	do {
		cin >> count;
		switch (count)
		{
		case 1: Writedown_E(employer); break;
		case 2: Writedown_W(worker); break;
		case 3: search(employer, worker, number);  break;
		case 4: Output_E(employer); break;
		case 5: Output_W(worker); break;
		case 6: Output_D(number); break;
		case 7: File_E(employer);  break;
		case 8: File_W(worker);  break;
		case 9: deleteE(employer); break;
		case 10: deleteW(worker); break;
		case 11: break;
		}
	} while (count != 11);
}

int main()
{
	setlocale(LC_ALL, "ru");
	menu();
}


