#include <iostream>
using namespace std;

struct Tree 
{
	int info;
	Tree* l, * r;
};

Tree* tree1 = NULL;

void push(int a, Tree** t) 
{
	if ((*t) == NULL) 
	{
		(*t) = new Tree;
		(*t)->info = a;
		(*t)->l = (*t)->r = NULL;
		return;
	}
	if (a > (*t)->info)
		push(a, &(*t)->r);
	else
		push(a, &(*t)->l);
}

void print(Tree* t, int u) 
{
	if (t == NULL) return;
	else
	{
		print(t->r, ++u);
		for (int i = 0; i < u; ++i)
			cout << "|";
		cout << t->info << endl;
		u--;
	}
	print(t->l, ++u);


}
int traverse(Tree* t)
{
	int n = 0;
	if (t != NULL) 
	{
		n += traverse(t->l);
		n += t->info;
		n += traverse(t->r);
	}
	return n;
}
void del(Tree** t)
{
	if (t != nullptr)
	{
		if ((*t)->l)del(&(*t)->l);
		if ((*t)->r)del(&(*t)->r);
		delete* t;
	*t = nullptr;
    }
}
void check(Tree* t)
{
	if (t == NULL)
	{
	    cout << "Äåðåâà íåò" << endl;
	}
	else
	{
		return;
	}
}
int main() 
{
	setlocale(0, "");
	int Amount, newNumber, ans;
	cout << "Введите количество элементов:\t";
	cin >> Amount;
	cout << "\nВводите Числа:\n";
	for (int i = 0; i < Amount; ++i) 
	{
		cin >> newNumber;
		push(newNumber, &tree1);
	}
	cout << "\nДерево:\n";
	print(tree1, 0);
	cout << endl;
	ans = traverse(tree1);
	cout << "Сумма всех вершин дерева: " << ans << endl;
	del(&tree1);
	cout << endl;
	check(tree1);
}