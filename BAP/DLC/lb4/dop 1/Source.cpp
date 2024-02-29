#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

struct Student {
	string name;
	int maths;
	int physics;
	int english;
	int oap;
	int lg;
};

void exams(Student* students, int SIZE) {

	int numStudents = 0;
	for (int i = 0; i < SIZE; ++i) {

		if ((students[i].maths == 5 || students[i].maths == 4) &&
			(students[i].physics == 5 || students[i].physics == 4) &&
			(students[i].english == 5 || students[i].english == 4) &&
			(students[i].oap == 5 || students[i].oap == 4) &&
			(students[i].lg == 5 || students[i].lg == 4))
		{
			cout << i << ") �������: " << students[i].name << " ���� �������� �� 4 ��� 5" << endl;
			numStudents++;
		}
		else cout << i << ") �������: " << students[i].name << " �� ���� �������� �� 4 ��� 5" << endl;
	}
	cout << "���������� ���������, ������� ������� �� 4 ��� 5, �� ���� ��������� " << ((double)numStudents / (double)SIZE) * 100 << " % " << endl;
}

void displayInfo(Student* students, int SIZE) {
	for (int i = 0; i < SIZE; ++i) {
		cout << "��� ��������: " << students[i].name << endl;
		cout << "����������: " << students[i].maths << endl;
		cout << "������: " << students[i].physics << endl;
		cout << "����������: " << students[i].english << endl;
		cout << "���: " << students[i].oap << endl;
		cout << "��: " << students[i].lg << endl;
		cout << "///////////////////////////////////////" << endl;
	}
}

void  ifileStud(Student* students, int SIZE) {
	ifstream fin("studentsInfo.txt");
	if (!fin.is_open()) {
		cout << "�� ������ ������� ���� ��� ������ " << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < SIZE; ++i) {
		fin >> students[i].maths;
		fin >> students[i].physics;
		fin >> students[i].english;
		fin >> students[i].oap;
		fin >> students[i].lg;
		fin >> students[i].name;
	}
	cout << "\n�������� ���������� �� ����� studentsInfo.txt\n";
}

int main()
{
	setlocale(LC_CTYPE, "ru");
	const int SIZE = 7;
	Student students[SIZE];
	short choose;
	do {
		cout << "\n��������, ��� �������:\n1 � ���������, ������� ��������� ������������ ����� ��������;\n2 � ������� � ������� ���������� � ��������;\n3 � ������� ���������� �� �����;\n4 � ����� �� ���������.\n";
		cin >> choose;
		switch (choose)
		{
		case 1: exams(students, SIZE); break;
		case 2: displayInfo(students, SIZE); break;
		case 3: ifileStud(students, SIZE); break;
		case 4: main(); break;
		}
	} while (choose != 4);
}
