// YAMP_individ3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// В текстовом документе первая строка - количество строк с L,R координатами.

#include <iostream>

using namespace std;

class Otrezok
{
public:
	Otrezok(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Конструктор сработал!" << endl;
	}

	void Zapolnenie()
	{
		/*
		--------------------------------
		| Заполнение массива отрезками |
		--------------------------------
		*/
		cout << "Введите количество отрезков: ";
		int n;
		cin >> n;
		Otrezok *arr = new Otrezok[n];
		cout << "Введите " << n << " штук отрезков вида L[I] R[I]:" << endl;
		for (int i = 0; i < n; i++)
			cin >> arr[i].x >> arr[i].y;
		cout << "Ваши отрезки:" << endl;
		for (int i = 0; i < n; i++)
		cout << "L[I]: " << arr[i].x << ", R[I]: " << arr[i].y << endl;
		/*
		-------------------------------
		|	     Сортировка           |
		-------------------------------
		*/
		int j;
		for (int i = 0; i < n; i++)
			if (arr[i].x > arr[i].y)
			{
				j = arr[i].x;
				arr[i].x = arr[i].y;
				arr[i].y = j;
			}
		// -------------------------------------------------------------
		Otrezok temp;
		for (int i = 1;  i < n - 1; i++)
			for (j = i + 1; j < n; j++)
				if (arr[i].x > arr[j].x)
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
		// -----------------------------------------
		// Сама задача (проверка вхождений)
		//------------------------------------------
		temp = arr[0];
		int s = 0;
		for (int i = 2; i < n; i++)
			{
				if (arr[i].y >= temp.y)
				{
					if (arr[i].x > temp.y)
					{
						s = s + temp.y - temp.x;
						temp = arr[i];
					}
					if (arr[i].x <= temp.y)
						temp.y = arr[i].y;
				}
			}
		s = s + temp.y - temp.x;
		cout << "Сумма отрезков: " << s << endl;
	}
	~Otrezok()
	{
		cout << "Деструктор сработал! ";
	}
private:
	int x;
	int y;
};

int main()
{
	setlocale(0, "");
	//условие
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| Условие задачи:                                                                                              |" << endl;
	cout << "| На прямой окрасили N отрезков.                                                                               |";
	cout << endl << "| Известны координата L[I] левого конца отрезка и координата R[I] правого конца I-ого отрезка для I=1,..,N.    |";
	cout << endl << "| Найти сумму длин всех окрашенных частей прямой.                                                              |" << endl;
	cout << "| Примечание. Число N столь велико, что на выполнение N*N даже простейших операций не хватит времени.          |" << endl;
	cout << "| МОДИФИКАЦИЯ. На окрудности окрасили N дуг.                                                                   |";
	cout << endl << "| Известны угловая координата L[I] начала и R[I] конца I-ой дуги (от начала к концу двигались, закрашивая дугу,|" << endl << "| против часовой стрелки).                                                                                     |";
	cout << endl << "| Какая доля окружности окрашена?                                                                              |" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;

	//задача
	cout << "Задача." << endl;

	Otrezok A;
	A.Zapolnenie();

	return 0;
}