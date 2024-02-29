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
		cout << "������� ����� ������������: "; cin >> num;
	} 
	while (num < 1 || num > N);
	fflush(stdin);
		cout << "\t�������� �" << num << endl;
		cout << "������� ��� ������������:\n";
		cin >> employer[num].name;
		cout << "������� ��� ������:\n";
		cin >> employer[num].work;
		cout << "������� �����:\n";
		cin >> employer[num].address;
		cout << "������� �������:\n";
		cin >> employer[num].phonenum;
		cout << "\n\n";
		cout << "��������" << endl;
		system("pause");
}

void Writedown_W(WK worker[])
{
	setlocale(LC_ALL, "ru");
	int num2;
	do
	{
		cout << "������� ����� ���������: "; cin >> num2;
	}
	while (num2 < 1 || num2 > N);
	fflush(stdin);
		cout << "\t�������� �" << num2 << endl;
		cout << "������� ��� ������������:\n";
		cin >> worker[num2].name;
		cout << "������� ��� ������:\n";
		cin >> worker[num2].work;
		cout << "������� �����:\n";
		cin >> worker[num2].address;
		cout << "������� �������:\n";
		cin >> worker[num2].phonenum;
		cout << "\n\n";
		system("pause");
}

void Output_E(EM employer[])
{
	int empl;
	cout << "������� ����� ������������, �������� �� ������ �������:\n";
	cin >> empl;
	int i = empl;
	cout << "\t������������ �" << empl << '\n';
	cout << "���: " << employer[i].name << '\n';
	cout << "���  ������: " << employer[i].work << '\n';
	cout << "�����: " << employer[i].address << '\n';
	cout << "�������: " << employer[i].phonenum << "\n\n\n";
	system("pause");
}

void Output_W(WK worker[])
{
	int work;
	cout << "������� ����� ���������, �������� �� ������ �������:\n";
	cin >> work;
	int i = work;
	cout << "\t��������� �" << work << '\n';
	cout << "��� : " << worker[i].name << '\n';
	cout << "��� ������: " << worker[i].work << '\n';
	cout << "�����: " << worker[i].address << '\n';
	cout << "�������: " << worker[i].phonenum << "\n\n\n";
	system("pause");
}

void Output_D(Deal number[])
{
	int deal;
	cout << "������� ����� ������: ";
	cin >> deal;
	int i = deal;
	cout << "����� ������: " << number[i].num << '\n';
	cout << "������������ �����: " << number[i].employer << '\n';
	cout << "�������� �����: " << number[i].worker << '\n';
	system("pause");
}

void File_E(EM employer[])
{
	int num;
	cout << "������� ����� ������������: "; cin >> num;
	ofstream file1("emlpoyer.txt", ios::app);
	     file1 << "\t�������� �" << num;
	     file1 << "\n������� ��� ������������:";
	     file1 << employer[num].name;
	     file1 << "\n������� ��� ������:";
	     file1 << employer[num].work;
	     file1 << "\n������� �����:";
	     file1 << employer[num].address;
	     file1 << "\n������� �������:";
	     file1 << employer[num].phonenum << "\n\n";
		 cout << "��������" << endl;
		 system("pause");
}

void File_W(WK worker[])
{
	int num2;
	cout << "������� ����� ���������: "; cin >> num2;
	ofstream file2("worker.txt");
		file2 << "\t�������� �" << num2 << '\n';
		file2 << "\n������� ��� ������������:";
		file2 << worker[num2].name;
		file2 << "\n������� ��� ������:";
		file2 << worker[num2].work;
		file2 << "\n������� �����:";
		file2 << worker[num2].address;
		file2 << "\n������� �������";
		file2 << worker[num2].phonenum << "\n\n";
		cout << "��������" << endl;
		system("pause");
}

void search(EM employer[], WK worker[], Deal number[])
{
	int deal;
	int g;
	cout << "������� �� ������ ����������� ��������? "; cin >> g;
	ofstream file3("doc.txt", ios::app);
	for (int i = 1; i < g; i++)
	{
		for (int j = 1; j < g; j++)
		{
			if (employer[i].work == worker[j].work)
				if (employer[i].address == worker[j].address)
				{
					cout << "��������" << i << " � ��������� ����� " << j << " ���������." << endl;
					cout << "������� ����� ������"; cin >> deal;
					number[deal].num;
					number[i].employer;
					number[j].worker;
					file3 << "������ � " << deal << endl;
					file3 << "������������ � " << i << " � �������� � " << j << endl;
					cout << "������ �������� � ��������" << endl;
					goto go;
				}
			else
			cout << "��� ����������" << endl;
		}
	}
go:
	cout << "��� ����������" << endl;
	system("pause");
}

void deleteE(EM employer[])
{
	int numCin;
	cout << "������� ���������� ����� ������������, ���������� � ������� �� ������ �������:\n";
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
	cout << "������� ���������� ����� ���������, ���������� � ������� �� ������ �������:\n";
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
	cout << "1. �������� ������������ " << endl;
	cout << "2. �������� ��������� " << endl;
	cout << "3. ����� ���������� � �������� �������� " << endl;
	cout << "4. ����������� �������� " << endl;
	cout << "5. ����������� ������ ���������� " << endl;
	cout << "6. ����������� ������ " << endl;
	cout << "7. �������� ������������ � ���� " << endl;
	cout << "8. �������� ��������� � ���� " << endl;
	cout << "9. ������� ������ ������������ " << endl;
	cout << "10. ������� ������ ���������" << endl;
	cout << "11. ����� �� ��������� " << endl;
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


