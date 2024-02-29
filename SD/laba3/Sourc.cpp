#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

char g[256];

void CreateFile()
{
	char num[256];
	cout << "��� ����� � ������� ������: "; cin >> g;
	ofstream file1(g, ios::app);
	cout << "������� ������ "; cin >> num;
	file1 << num;
	cout << "��������" << endl;
	system("pause");
}

void File()
{
	string strInf;
	ifstream file1(g);

		getline(file1, strInf);
		cout << strInf << '\n';
	
	system("pause");
}

void Search()
{
	ifstream file(g); 
	string s, find;
	char c;

	while (!file.eof()) {  
		file.get(c);
		s.push_back(c);
	}

	file.close(); 

	cout << "������� ������, ������� ������ �����: ";
	cin >> find;

	int pos = s.find(find); 

	if (pos == -1)
		cout << "�� �������" << endl;
	else
		cout << "������� �� ������� " << pos + 1 << endl;
	system("pause");
}

void DeleteData()
{
	ofstream file1(g, ios_base::trunc);
	cout << "������ �������" << endl;
	system("pause");
}

void DeleteFile()
{
	remove(g);
	cout << "���� ������" << endl;
	system("pause");
}

void menu()
{
	setlocale(LC_ALL, "ru");
	cout << "����� �������: " << endl;
	cout << "1. �������� ����� � ������� ������ " << endl;
	cout << "2. ������ ����� " << endl;
	cout << "3. �������� ����������� " << endl;
	cout << "4. �������� ����� " << endl;
	cout << "5. ����� �������" << endl;
	cout << "6. ���������" << endl;
	int count;
		cin >> count;
		switch (count)
		{
		case 1: system("cls"),CreateFile(), system("cls"), menu();
		case 2: system("cls"),File(), system("cls"), menu();
		case 3: system("cls"),DeleteData() , system("cls"), menu();
		case 4: system("cls"),DeleteFile() , system("cls"), menu();
		case 5: system("cls"), Search(), system("cls"), menu();
		case 6: break;
		}

}

int main()
{
	setlocale(LC_ALL, "ru");
	menu();
}