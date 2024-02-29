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
	cout << "Имя файла и укажите формат: "; cin >> g;
	ofstream file1(g, ios::app);
	cout << "Введите данные "; cin >> num;
	file1 << num;
	cout << "Записано" << endl;
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

	cout << "Введите данные, которые хотите найти: ";
	cin >> find;

	int pos = s.find(find); 

	if (pos == -1)
		cout << "Не найдены" << endl;
	else
		cout << "Найдено на позиции " << pos + 1 << endl;
	system("pause");
}

void DeleteData()
{
	ofstream file1(g, ios_base::trunc);
	cout << "Данные удалены" << endl;
	system("pause");
}

void DeleteFile()
{
	remove(g);
	cout << "Файл удален" << endl;
	system("pause");
}

void menu()
{
	setlocale(LC_ALL, "ru");
	cout << "Выбор задания: " << endl;
	cout << "1. Создание файла и записаь данных " << endl;
	cout << "2. Чтение файла " << endl;
	cout << "3. Удаление содержимого " << endl;
	cout << "4. Удаление файла " << endl;
	cout << "5. Найти позицию" << endl;
	cout << "6. Завершить" << endl;
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