#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <forward_list>
#include <vector>
#include <deque>
using namespace std;

enum position {
	on,
	off,
	sleep,
};

enum colors {
	red,
	orange,
	yellow,
	green,
	cyan,
	blue,
	violet,
};

enum planets {
	Mercury,
	Venus,
	Earth,
	Mars,
	Jupiter,
	Saturn,
	Uranusand,
	Neptune,
};

enum days {
	monday,
	tuesday,
	wednesday,
	thursday,
	friday,
	saturday,
	sunday,
};

void One()
{
start:
	cout << "Введите номер состояния: ";
	int sample;
	cin >> sample;
	position tag = static_cast<position>(sample);

	if (tag == on)
		cout << "Ваш PC в состоянии ВКЛ";
	if (tag == off)
		cout << "Ваш PC в состоянии ВЫКЛ";
	if (tag == sleep)
		cout << "Ваш PC в состоянии СПЯЩИЙ РЕЖИМ";
}


void Two()
{
	cout << "Выберите номер цвета: ";
	int rainbow;
	cin >> rainbow;
	colors tag = static_cast<colors>(rainbow);

	if (tag == red)
		cout << "Красный";
	if (tag == orange)
		cout << "Оранжевый";
	if (tag == yellow)
		cout << "Жёлтый";
	if (tag == green)
		cout << "Зелёный";
	if (tag == cyan)
		cout << "Голубой";
	if (tag == blue)
		cout << "Синий";
	if (tag == violet)
		cout << "Фиолетовый";
}


void Three()
{
	cout << "Выберите номер планеты Солнечной системы: ";
	int cosmos;
	cin >> cosmos;
	planets tag = static_cast<planets>(cosmos);

	if (tag == Mercury)
		cout << "Меркурий";
	if (tag == Venus)
		cout << "Венера";
	if (tag == Earth)
		cout << "Земля";
	if (tag == Mars)
		cout << "Марс";
	if (tag == Jupiter)
		cout << "Юпитер";
	if (tag == Saturn)
		cout << "Сатурн";
	if (tag == Uranusand)
		cout << "Уран";
	if (tag == Neptune)
		cout << "Нептун";
}

void Four()
{
	cout << "Выберите день недели: ";
	int week;
	cin >> week;
	days tag = static_cast<days>(week);

	if (tag == monday)
		cout << "Понедельник";
	if (tag == tuesday)
		cout << "Вторник";
	if (tag == wednesday)
		cout << "Среда";
	if (tag == thursday)
		cout << "Четверг";
	if (tag == friday)
		cout << "Пятница";
	if (tag == saturday)
		cout << "Суббота";
	if (tag == sunday)
		cout << "Воскресенье";
}

void Seven() {
	vector<int> vect;
	int value, count;
	cout << "Введите кол-во элементов: "; cin >> count;
	for (int i = 0; i < count; i++)
	{
		value = rand() % 10;
		vect.push_back(value);
	}

	for (int n : vect)
	{
		cout << n << "\t";
	}

	cout << endl;

	int max = vect[0];
	for (int i = 0; i < count; i++)

	{
		if (max < vect[i])
			max = vect[i];
	}

	cout << "Макс элемент = " << max << endl;
}

void Eight()
{
	deque<int> deq;
	int value, count;
	cout << "Введите кол-во элементов: "; cin >> count;
	for (int i = 0; i < count; i++)
	{
		value = rand() % 10;
		deq.push_back(value);
	}

	for (int n : deq)
	{
		cout << n << "\t";
	}
	cout << endl;

	int min = deq[0];
	for (int i = 0; i < count; i++)
	{
		if (min > deq[i])
			min = deq[i];
	}

	cout << "Мин элемент = " << min << endl;

	deq.push_front(min);

	for (int n : deq)
	{
			cout << n << "\t";
	}
	cout << endl;
}

void Nine() {
	int const N = 5;
	int arr[N] = {};

	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 10;
		cout << arr[i] << "\t";
	}

	for (int n : arr)
	{
		cout << n << "\t";
	}

	cout << endl;

	int min = arr[0];
	for (int i = 0; i < N; i++)
	{
		if (min > arr[i])
			min = arr[i];
	}

	cout << "Мин элемент = " << min << endl;

	int maxn = arr[0];
	for (int i = 0; i < N; i++)
	{
		if (maxn < arr[i])
			maxn = arr[i];
	}

	cout << "Макс элемент = " << maxn << endl;


}


void Eleven() {
	int x;
	list<int> newlist;
	int value, count;
	cout << "Введите кол-во элементов: "; cin >> count;
	for (int i = 0; i < count; i++)
	{
		value = rand() % 10;
		newlist.push_back(value);
	}
	for (int n : newlist)
	{
		cout << n << "\t";
	}
	cout << "\nУдаляем и добавляем:\n"; cin >> x;

	newlist.remove(x);
	newlist.push_front(x);

	for (int n : newlist)
	{
		cout << n << "\t";
	}
}

void Twelve() {
		vector<int> newlist;
		int main, count;
		cout << "Введите кол-во элементов: "; cin >> count;
		for (int i = 0; i < count; i++)
		{
			main = rand() % 10;
			newlist.push_back(main);
		}

		for (int n : newlist)
		{
			cout << n << "\t";
		}

		newlist.clear();

		int value;
		cout << "Введите кол-во элементов: "; cin >> value;
		cout << "\nДобавляем:\n";
		for (int i = 0; i < value; i++)
		{
			main = rand() % 10;
			newlist.push_back(main);
		}

		for (int n : newlist)
		{
			cout << n << "\t";
		}
	}


int main()
{
	setlocale(LC_CTYPE, "ru");
	int point;
	cout << "Выберите номер задания: ";
	cin >> point;
	switch (point)
	{
	case 1:
		One();
		break;
	case 2:
		Two();
		break;
	case 3:
		Three();
		break;
	case 4:
		Four();
		break;
	case 7:
		Seven();
		break;
	case 8:
		Eight();
		break;
	case 9:
		Nine();
		break;
	case 11:
		Eleven();
		break;
	case 12:
		Twelve();
		break;
	default:
		cout << "Неверное значение!";
		break;
	}
}

