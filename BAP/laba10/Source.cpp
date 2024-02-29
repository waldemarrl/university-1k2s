#include <iostream>
#include <tchar.h>
#include <fstream>
using namespace std;

double sumCos(float x, int l)
{
	if (l == x)
		return sqrt(1 + (x + l));
	else
		return sumCos(x + 1, l) * sqrt(1 + (l + x));
}
int C(int m, int n)
{
	if (m == 0 || m == n || n == 0)
		return 1;
	else
		return C(m, n - 1) + C(m - 1, n - 1);
}
ofstream file1("file.txt");
int arr[256];
int A;
void ch(int k) {
	int i, j, t, p;
	for (i = 0; i < A - k; i++)
	{
		if (k < A - 2)
			ch(k + 1);
		else {
			for (p = 0; p < A; p++)
				file1 << arr[p];
			file1 << endl;
		}
		t = arr[k];
		for (j = k + 1; j < A; j++)
			arr[j - 1] = arr[j];
		arr[j - 1] = t;
	}

}


const int z = 5;
int a[z];


void perm(int k) {
	int q, j, t, p;
	for (q = 0; q < z - k; q++) {
		if (k < z - 2)
			perm(k + 1);
		else {
			for (p = 0; p < z; p++)
				cout << " " << a[p];
			cout << endl;
		}
		t = a[k];
		for (j = k + 1; j < z; j++)
			a[j - 1] = a[j];
		a[j - 1] = t;
	}
}

int counter = 0;

int posled(int v, int counter, int r)
{
	while (counter != 26)
	{
		cout << v << " ";
		return posled(v + r, counter + 1, r);
	}

}

int ct = 1;

int find(int ct, int v, int position, int r)
{
	while (ct != 26)
	{
		if (position == ct)
		{
			cout << std::endl;
			cout << "����� �� ������� n=" << v << std::endl;
		}
		return find(ct + 1, v + r, position, r);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "ru");
	int choice;
	for (;;)
	{
		cout << "�������� �������:" << endl;
		cout << "1 - 1 �������� �������" << endl;
		cout << "2 - 2 �������� �������" << endl;
		cout << "3 - 1 ��� �������" << endl;
		cout << "4 - 2 ��� �������" << endl;
		cout << "5 - 3 ��� �������" << endl;
		cout << "6 - �����" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			float x;
			x = 1;
			int l;
			cout << "Enter l: ";
			cin >> l;
			cout << "����� = " << sumCos(x, l) << endl;
			break;
		case 2:
			double m, n;
			cout << "������� m:";
			cin >> m;
			cout << endl;
			cout << "������� n:";
			cin >> n;
			cout << endl;
			cout << "�����=" << C(m, n) << endl;
		case 3:
			cout << "������� �����:";
			cin >> A;
			cout << endl;
			int i;
			for (i = 0; i < A; i++)
				arr[i] = i + 1;
			ch(0);
			file1.close();
			cout << "������ �������� � ����." << endl;
			break;
		case 4:
			int q;
			for (q = 0; q < z; q++)
				a[q] = q + 1;
			perm(0);
			break;
		case 5:
			int position, v, r;
			cout << "������� ��������� �������� ������������������:";
			cin >> v;
			cout << endl;
			cout << "������� ����� �� ������� ����� ���������� ������������������:";
			cin >> r;
			cout << endl;
			cout << "������� n:";
			cin >> position;
			cout << endl;
			cout << "������������������:";
			posled(v, counter, r);
			find(ct, v, position, r);
			break;
		case 6:
			return 0;
			break;
		}
	}
}