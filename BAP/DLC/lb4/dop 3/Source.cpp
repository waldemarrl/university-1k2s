#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

struct Camp {
	string CampName;
	string CampPlace;
	string CampType;
	int voucher;
};

bool comp1(Camp lhs, Camp rhs)
{
	return lhs.CampName < rhs.CampName;
}

bool comp(Camp lhs, Camp rhs)
{
	return lhs.CampType < rhs.CampType;
}

void showInfo(Camp* lagger, int SIZE) {
	sort(lagger, lagger + SIZE, comp);
	int index1 = 0;
	int index2 = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (lagger[i].CampType == lagger[i + 1].CampType)
		{
			index1 = i;
			break;
		}
	}

	for (int i = SIZE; i > 0; i--)
	{
		if (lagger[i].CampType == lagger[i - 1].CampType)
		{
			index2 = i;
			break;
		}
	}

	sort(lagger + index1, lagger + index2 + 1, comp1);


	for (int i = 0; i < SIZE; ++i) {
		cout << "�������� ������: " << lagger[i].CampName << "\t";
		cout << "����� ������: " << lagger[i].CampPlace << "\t";
		cout << "������� �������: " << lagger[i].CampType << "\t\t";
		cout << "���������� �������: " << lagger[i].voucher << "\t" << endl;
		cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	}

}

void ifileCamp(Camp* lagger, int SIZE)
{

	ifstream fin("lagggerInfo.txt");

	if (!fin.is_open()) {
		cout << "�� ������ ������� ���� ��� ������ " << endl;
		exit(EXIT_FAILURE);
	}

	vector<string> fileinfo;
	string line, word;
	stringstream x;
	for (int i = 0; i < SIZE; ++i) {
		fin >> lagger[i].voucher;
		getline(fin, line);
		x << line;
		while (x >> word)
		{
			fileinfo.push_back(word);
		}
		for (int k = 0; k < fileinfo.size(); k++)
		{
			if (k == 0) { lagger[i].CampName = fileinfo[k]; }
			if (k == 1) { lagger[i].CampPlace = fileinfo[k]; }
			if (k == 2) { lagger[i].CampType = fileinfo[k]; }
		}
		x.clear();
		line.clear();
		word.clear();
		fileinfo.clear();
	}
	cout << "\n���������� ������� �� ����� lagggerInfo.txt\n\n";
}


int main()
{

	setlocale(LC_CTYPE, "ru");
	const int SIZE = 5;
	Camp lager[SIZE];
	short choose;
	do {
		cout << "��������, ��� �������:\n1 � ������� ���������� �� �����;\n2 � ������� � ������� ���������� � �������;\n3 � �����\n";
		cin >> choose;
		switch (choose)
		{
		case 1: ifileCamp(lager, SIZE); break;
		case 2: showInfo(lager, SIZE); break;
		case 3: exit(0); break;
		}
	} while (choose != 3);
}
