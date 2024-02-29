#include <iostream>
#include<fstream>
# define size 100
using namespace std;
void enter_new();
void out();
void search();
union forSklad
{
	char str[20];
	int limb;
};
struct Sklad
{
	forSklad name_of_product;
	forSklad cell;
	forSklad many;
	forSklad per;
};
Sklad productOnSclad[size];
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
		cout << endl << "������������ ������" << endl;
		cin >> productOnSclad[current_size].name_of_product.str;
		cout << "����" << endl;
		cin >> productOnSclad[current_size].cell.limb;
		cout << "����������" << endl;
		cin >> productOnSclad[current_size].many.limb;
		cout << "���������� ��������" << endl;
		cin >> productOnSclad[current_size].per.limb;
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
		cout << endl << "������������ ������:" << endl;
		cout << productOnSclad[n - 1].name_of_product.str << endl;
		cout << "����:" << endl;
		cout << productOnSclad[n - 1].cell.limb << endl;
		cout << "����������:" << endl;
		cout << productOnSclad[n - 1].many.limb << endl;
		cout << "���������� ��������:" << endl;
		cout << productOnSclad[n - 1].per.limb << "%" << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << endl << "������������ ������:" << endl;
			cout << productOnSclad[i].name_of_product.str << endl;
			cout << "����:" << endl;
			cout << productOnSclad[i].cell.limb << endl;
			cout << "����������:" << endl;
			cout << productOnSclad[i].many.limb << endl;
			cout << "���������� ��������:" << endl;
			cout << productOnSclad[i].per.limb << "%" << endl;

		}
	}
	cout << "��� ������?" << endl;
	cin >> choice;
}
void search()
{
	char name[16];
	cout << "������� ������������ ������:" << "\n";
	cin >> name;
	for (int z = 0; z < current_size; z++)
	{
		if (strcmp(name, productOnSclad[z].name_of_product.str) == 0)
		{
			cout << endl << "������������ ������:" << endl;
			cout << productOnSclad[z].name_of_product.str << endl;
			cout << "����:" << endl;
			cout << productOnSclad[z].cell.limb << endl;
			cout << "����������:" << endl;
			cout << productOnSclad[z].many.limb << endl;
			cout << "���������� ��������:" << endl;
			cout << productOnSclad[z].per.limb << "%" << endl;

		}
	}
	cout << "��� ������?" << endl;
	cin >> choice;
}