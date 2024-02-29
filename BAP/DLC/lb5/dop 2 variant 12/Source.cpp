#include <iostream>
#include<fstream>
#include <iomanip>
using namespace std;
# define str_len 256
# define size 100
using namespace std;
void enter_new();
void out();
void search();
union fornotebook
{
	char str[40];
	int limb;
};
struct notebook
{
	fornotebook name;
	fornotebook surname;
	fornotebook middleName;
	fornotebook date;
	fornotebook addres;
	fornotebook phone;
	fornotebook place_of_work;
	fornotebook position;
};
notebook people_in_notebook[size];
int current_size = 0; int choice;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "�������:" << endl;
	cout << "1-��� ����� ������" << endl;
	cout << "2-��� ������ ������" << endl;
	cout << "3-��� ������ ����������" << endl;
	cout << "4-��� ������" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1: enter_new(); break;
		case 2: out(); break;
		case 3: search(); break;
		}
	} while (choice != 4);
}
void enter_new()
{
	cout << "���� ����������" << endl;
	if (current_size < size)
	{
		cout << "������ ����� ";
		cout << current_size + 1;
		cout << endl << "�������" << endl;
		cin >> people_in_notebook[current_size].surname.str;
		cout << "���" << endl;
		cin >> people_in_notebook[current_size].name.str;
		cout << "��������" << endl;
		cin >> people_in_notebook[current_size].middleName.str;
		cout << "���� ��������: " << endl;
		cin >> people_in_notebook[current_size].date.str;
		cout << "�����:" << endl;
		cin >> people_in_notebook[current_size].addres.str;
		cout << "����� ��������:" << endl;
		cin >> people_in_notebook[current_size].phone.limb;
		cout << "����� ������:" << endl;
		cin >> people_in_notebook[current_size].place_of_work.str;
		cout << "���������:" << endl;
		cin >> people_in_notebook[current_size].position.str;
		current_size++;


	}
	else
		cout << "������� ������������ ���-�� �����";
	cout << "��� ������?" << endl;
	cin >> choice;
}
void out()
{
	int sw, n;
	cout << "1-����� 1 ������" << endl;
	cout << "2-����� ���� �����" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "����� ��������� ������: " << endl;
		cin >> n;
		cout << endl;
		cout << "�������" << endl;
		cout << people_in_notebook[n - 1].surname.str;
		cout << endl;
		cout << "���" << endl;
		cout << people_in_notebook[n - 1].name.str;
		cout << endl;
		cout << "��������" << endl;
		cout << people_in_notebook[n - 1].middleName.str;
		cout << endl;
		cout << "���� ��������: " << endl;
		cout << people_in_notebook[n - 1].date.str;
		cout << "�����:" << endl;
		cout << people_in_notebook[n - 1].addres.str;
		cout << endl;
		cout << "����� ��������:" << endl;
		cout << people_in_notebook[n - 1].phone.limb;
		cout << endl;
		cout << "����� ������:" << endl;
		cout << people_in_notebook[n - 1].place_of_work.str;
		cout << endl;
		cout << "���������:" << endl;
		cout << people_in_notebook[n - 1].position.str;
		cout << endl;

	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << "�������" << endl;
			cout << people_in_notebook[i].surname.str;
			cout << endl;
			cout << "���" << endl;
			cout << people_in_notebook[i].name.str;
			cout << endl;
			cout << "��������" << endl;
			cout << people_in_notebook[i].middleName.str;
			cout << endl;
			cout << "���� ��������: " << endl;
			cout << people_in_notebook[i].date.str;
			cout << "�����:" << endl;
			cout << people_in_notebook[i].addres.str;
			cout << endl;
			cout << "����� ��������:" << endl;
			cout << people_in_notebook[i].phone.limb;
			cout << endl;
			cout << "����� ������:" << endl;
			cout << people_in_notebook[i].place_of_work.str;
			cout << endl;
			cout << "���������:" << endl;
			cout << people_in_notebook[i].position.str;
			cout << endl;
		}
	}
	cout << "��� ������?" << endl;
	cin >> choice;
}
void search()
{
	char name[16];
	cout << "������� �������:" << "\n";
	cin >> name;
	for (int z = 0; z < current_size; z++)
	{
		if (strcmp(name, people_in_notebook[z].surname.str) == 0)
		{
			cout << "�������" << endl;
			cout << people_in_notebook[z].surname.str;
			cout << endl;
			cout << "���" << endl;
			cout << people_in_notebook[z].name.str;
			cout << endl;
			cout << "��������" << endl;
			cout << people_in_notebook[z].middleName.str;
			cout << endl;
			cout << "���� ��������: " << endl;
			cout << people_in_notebook[z].date.str;
			cout << "�����:" << endl;
			cout << people_in_notebook[z].addres.str;
			cout << endl;
			cout << "����� ��������:" << endl;
			cout << people_in_notebook[z].phone.limb;
			cout << endl;
			cout << "����� ������:" << endl;
			cout << people_in_notebook[z].place_of_work.str;
			cout << endl;
			cout << "���������:" << endl;
			cout << people_in_notebook[z].position.str;
			cout << endl;

		}
	}
	cout << "��� ������?" << endl;
	cin >> choice;
}