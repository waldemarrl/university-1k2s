#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	char str[20];
	int dl;
	Stack* St = new Stack; //��������� ������ ��� �����
	St->head = NULL;       //������������� ������� �������� 
	while (strlen(str) % 2 != 0) {
		cout << "������ � ������ ����������� ��������" << endl;
		cin >> str;
	}
	dl = strlen(str);
	for (int i = (dl / 2); i < dl; i++) {
		push(str[i], St);
	}
	for (int i = 0; i < (dl / 2); i++) {
		push(str[i], St);
	}
	show(St);
}