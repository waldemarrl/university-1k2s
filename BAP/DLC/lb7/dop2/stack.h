#pragma once
struct Stack
{
	char data;            
	Stack* head;   
	Stack* next;   
};
void show(Stack* St);        
int pop(Stack* St);         
void push(char x, Stack* St);