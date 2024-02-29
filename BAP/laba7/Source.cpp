#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

struct stack {
	int data;
	stack* head;
	stack* next;
};

struct stack1
{
	int data1;
	stack1* head;
	stack1* next;
};

struct stack2
{
	int data2;
	stack2* head;
	stack2* next;
};

void AddElF(int elem, stack* st);
void AddElS(int elem, stack1* st1);
void AddElT(int elem, stack2* st2);
int N;

void input(stack* st, stack1* st1, stack2* st2)
{
	setlocale(LC_ALL, "ru");
	int newEl, Element;

	stack1* st11 = new stack1;
	st11->head = NULL;

	stack2* st22 = new stack2;
	st22->head = NULL;

	cout << "Сколько вы  хотитие добавить элементов в стек = "; cin >> N;
	cout << endl;

	for (int i = 0; i < N; i++)
	{
		cout << "Стек 2" << endl;
		cout << "Значение > "; cin >> newEl;
		AddElS(newEl, st11);
		cout << "\n";

		cout << "Стек 3" << endl;
		cout << "Значение > "; cin >> newEl;
		AddElT(newEl, st22);
		cout << "\n";
	}
}

void AddElF(int elem, stack* st)
{
	stack* NewEl = new stack;
	NewEl->data = elem;
	NewEl->next = st->head;
	st->head = NewEl;
}

void AddElS(int elem, stack1* st1)
{
	stack1* NewEl = new stack1;
	NewEl->data1 = elem;
	NewEl->next = st1->head;
	st1->head = NewEl;
}

void AddElT(int elem, stack2* st2)
{
	stack2* NewEl = new stack2;
	NewEl->data2 = elem;
	NewEl->next = st2->head;
	st2->head = NewEl;
}

void GetEl(stack* st, stack1* st1, stack2* st2)
{
	int Element, Element1, Element2, arr[20], i = 0, x= 0, k= 0;

	stack* sthead = st->head;
	stack1* sthead1 = st1->head;
	stack2* sthead2 = st2->head;


		Element1 = st->data;
		arr[x] = Element1;
		x++;

		Element2 = st->data;
		arr[k] = Element2;
		k++;

	for (int j = 0; j < x; j++)
	{
		for (int j = 0; j < k; j++)
		{
			arr[k] == arr[x];
			arr[i] = arr[k];
			Element = arr[i];
			Element = st->data;
			
		}
	}
	
		Element = sthead->data;
		cout << Element << " ";
		sthead = sthead->next;
	
	cout << "\n";
}

void PrintStack(stack1* st1)
{
	stack1* sthead = st1->head;
	int elData;
	if (sthead == NULL)
		cout << "Стек пуст";
	while (sthead != NULL)
	{
		elData = sthead->data1;
		cout << elData << " ";
		sthead = sthead->next;
	}
	cout << "\n";
}


int main()
{
	setlocale(LC_ALL, "ru");
	stack* st = new stack;
	st->head = NULL;

	stack1* st1 = new stack1;
	st1->head = NULL;

	stack2* st2 = new stack2;
	st2->head = NULL;

	input(st, st1, st2);
	PrintStack(st1);
	GetEl(st, st1, st2);
}