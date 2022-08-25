// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

struct Otrezok
{
	int x;
	int y;
};

	Otrezok* CreateArr(int n, Otrezok* arr)
	{
		cout << "Введите " << n << " штук отрезков: " << endl;
		for (int i = 0; i < n; i++)//ввод
		{
			cin >> arr[i].x >> arr[i].y;
		}
		return arr;
	}

	Otrezok* OutputOtrezok(int n, Otrezok* arr)
	{
		cout << "Ваши отрезки:" << endl;
		for (int i = 0; i < n; i++)//вывод
		{
			cout << "L[I] = " << arr[i].x << ", R[I] = " << arr[i].y << endl;
		}
		return arr;
	}

	void Validation(int n, Otrezok* arr)
	{
		//проверка на правильный ввод отрезков
		int temp;
		for (int i = 0; i < n; i++)
			if (arr[i].x > arr[i].y)
			{
				temp = arr[i].x;
				arr[i].x = arr[i].y;
				arr[i].y = temp;
			}
	}

	void SortHoara(Otrezok* arr, int first, int last)
	{
		/*
		Оценка сложности алгоритма Хоара:
		Сложность алгоритма зависит от входных данных и в лучшем случае будет равняться O(n×2log2n).
		В худшем случае O(n^2). Существует также среднее значение, это O(n×log2n)
		*/
		//сортировка Хоара
		int mid;
		Otrezok count;
		int f = first, l = last;
		mid = arr[(f + l) / 2].x; //вычисление опорного элемента
		do
		{
			while (arr[f].x < mid) f++;
			while (arr[l].x > mid) l--;
			if (f <= l) //перестановка элементов
			{
				count = arr[f];
				arr[f] = arr[l];
				arr[l] = count;
				f++;
				l--;
			};
		} while (f < l);
		if (first < l) SortHoara(arr, first, l);
		if (f < last) SortHoara(arr, f, last);
	};

	void OutputSort(int n, Otrezok* arr)
	{
		//выводим сортировку
		cout << "Отсортированный массив:" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "L[I] = " << arr[i].x << ", R[I] = " << arr[i].y << endl;
		}
	};

	void MainZadacha(int n, Otrezok* arr)
	{
		//сама задача
		Otrezok c = arr[0];//запоминаем координаты первого отрезка
		int s = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i].y >= c.y)
			{
				if (arr[i].x > c.y)//если x лежит правее y по Ох
				{
					s = s + c.y - c.x;
					c = arr[i];
				}
				if (arr[i].x <= c.y) c.y = arr[i].y;//если х левее и лежит на y
			}
		}
		s = s + c.y - c.x;
		cout << "Сумма = " << s << endl;
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
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Задача." << endl;
	cout << "Введите количество закрашенных отрезков:" << endl;
	int n;
	cin >> n;

	Otrezok* arr = new Otrezok [n];
	CreateArr(n, arr);
	OutputOtrezok(n, arr);
	Validation(n, arr);//проверка на правильность ввода
	SortHoara(arr, 0, n-1);//n-1 тк выходит за границу массива
	OutputSort(n, arr);
	MainZadacha(n, arr);
	return 0;
}