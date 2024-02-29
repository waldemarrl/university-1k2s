#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;


	struct BankClients
	{
		string name;
		string accType;
		string accNumber;
		string sum;
		string date;
	};

	const short N = 20;

	void input(BankClients clients[])
	{
		int num;
		do {
			cout << "������� ���������� �������� ����� (�� ����� " << N << "): ";
			cin >> num;
		} while (num < 1 || num > N);
		fflush(stdin);
		for (int i = 0; i < num; i++)
		{
			cout << "\t������ �" << i + 1 << endl;
			cout << "������� ��� �������:\n";
			cin >> clients[i].name;
			cout << "������� ��� �����:\n";
			cin >> clients[i].accType;
			cout << "������� ����� �����:\n";
			cin >> clients[i].accNumber;
			cout << "������� ����� �� �����:\n";
			cin >> clients[i].sum;
			cout << "������� ���� ���������� ���������:\n";
			cin >> clients[i].date;
			cout << "\n\n";
		}
	}

	void output(BankClients clients[])
	{
		int ClientNum;
		cout << "������� ����� �������, �������� �� ������ �������:\n";
		cin >> ClientNum;
		int i = ClientNum - 1;
		cout << "\t������ �" << ClientNum << '\n';
		cout << "��� �������: " << clients[i].name << '\n';
		cout << "��� �����: " << clients[i].accType << '\n';
		cout << "����� �����: " << clients[i].accNumber << '\n';
		cout << "����� �� �����: " << clients[i].sum << '\n';
		cout << "���� ���������� ���������: " << clients[i].date << "\n\n\n";
	}

	void deleteClient(BankClients clients[])
	{
		int numCin;
		cout << "������� ���������� ����� �������, ���������� � ������� �� ������ �������:\n";
		cin >> numCin;
		cout << '\n';
		int i = numCin - 1;
		clients[i].name = ' ';
		clients[i].accType = ' ';
		clients[i].accNumber = ' ';
		clients[i].sum = ' ';
		clients[i].date = ' ';
		cout << '\n';
	}

	void search(BankClients clients[])
	{
		string numSearch;
		cout << "������� ����� ����� �������� �������:\n";
		cin >> numSearch;
		for (int i = 0; i < N; i++)
		{
			if (numSearch == clients[i].accNumber)
			{
				cout << "������ �" << i + 1 << ": ���� �" << clients[i].accNumber << '\n';
			}
		}
		cout << "\n\n";
	}

	void ofile(BankClients clients[])
	{
		string buf;
		int num;
		do {
			cout << "������� ���������� �������� ����� (�� ����� " << N << "): ";
			cin >> num;
		} while (num < 1 || num > N);
		fflush(stdin);
		ofstream file1("information.txt");
		for (int i = 0; i < num; i++)
		{
			cout << "\t������ �" << i + 1 << '\n';
			file1 << "\t������ �" << i + 1 << '\n';
			cout << "������� ��� �������:\n";
			file1 << "��� �������: ";
			cin >> clients[i].name;
			file1 << clients[i].name;
			cout << "������� ��� �����:\n";
			file1 << "\n��� �����: ";
			cin >> clients[i].accType;
			file1 << clients[i].accType;
			cout << "������� ����� �����:\n";
			file1 << "\n����� �����: ";
			cin >> clients[i].accNumber;
			file1 << clients[i].accNumber;
			cout << "������� ����� �� �����:\n";
			file1 << "\n����� �� �����: ";
			cin >> clients[i].sum;
			file1 << clients[i].sum;
			cout << "������� ���� ���������� ���������:\n";
			file1 << "\n���� ���������� ���������: ";
			cin >> clients[i].date;
			file1 << clients[i].date << "\n\n";
		}
		cout << "\n\n";
	}

	void ifile(BankClients clients[])
	{
		string strInf;
		ifstream file1("information.txt");
		while (file1)
		{
			getline(file1, strInf);
			cout << strInf << '\n';
		}
	}

	int main()
	{
		setlocale(LC_ALL, "ru");
		short choose;
		BankClients clients[N];
		do {
			cout << "��������, ��� �������:\n1 � ���� ��������� ��������� � ����������;\n2 � ����� ��������� �������� � ���������� ����;"
				"\n3 � �������� �������� ����������������� ����������; \n4 � ����� ����������; \n5 � ������ ���������� � ����; \n6 � ������ ������ �� �����; \n7 � ����� �� ���������.\n";
			cin >> choose;
			switch (choose)
			{
			case 1: input(clients); break;
			case 2: output(clients); break;
			case 3: deleteClient(clients); break;
			case 4: search(clients); break;
			case 5: ofile(clients); break;
			case 6: ifile(clients); break;
			case 7: main(); break;
			}
		} while (choose != 7);
	}
