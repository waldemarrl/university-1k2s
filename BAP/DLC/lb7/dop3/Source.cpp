#include <iostream>
#include "stack.h"
using namespace std;

void push(char x, Stack* St)   
{
	Stack* e = new Stack;   
	e->data = x;             
	e->next = St->head;   
	St->head = e;         
}
int pop(Stack* St)  
{
	if (St->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;               
	}
	else
	{
		Stack* e = St->head;   
		char a = St->head->data;   
		St->head = St->head->next; 
		delete e;                        
		return a;                       
	}
}
void show(Stack* St)    
{
	Stack* e = St->head;    
	char a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;         
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}