// YAMP-LABA1_chetnIndex.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*Создать циклический двунаправленный список из целых чисел. Определить произведение чисел на четных местах и вставить элемент со значением, равным вычисленному произведению в конец списка.*/

#include <iostream>
#include "windows.h"

using namespace std;

struct list
{
	int data;
	int index = 0;
	list* next;
	list* pred;
};

void inputList(list* head)
{
	list* x1 = NULL, * x2 = NULL;
	int k = -1; //тк head пустой - чтоб не учитывать
	head->data = 0;
	head->index = k;
	head->next = NULL;
	int y;
	while (cin >> y)
	{
		x1 = new list;
		k++;
		x1->index = k;
		x1->data = y;
		if (head->next == NULL) // (*), если ссылка у элемента head на след элемент пустая
		{ //связываем head с текущим и текущий с главным
			head->next = x1;
			x1->pred = head;
		}
		else
		{
			x2->next = x1;
			x1->pred = x2;
		}
		x2 = x1; //запоминаем текущий(x1), как предыдущий(x2)
	}
	x1->next = head;
	head->pred = x1;
}

void outList(list* head)
{
	list* x = NULL;
	x = head->next;
	while (x != head)
	{
		cout << x->data << endl;
		x = x->next;
	}
}

void ProizvChetN(list* head)
{
	list* x = NULL;
	list* x1 = NULL;
	int a = 1;
	x = head->next;
	while (x != head)
	{

		if (x->index % 2 == 0)
			a *= x->data;
		x = x->next;
	}
	x1 = new list;
	x1->data = a;
	x = head->pred;
	x->next = x1;
	x1->pred = x;
	x1->next = head;
	head->pred = x1;
}

void DelList(list* head)
{
	list* x = head->next;
	list* x1 = NULL;
	while (x != head)
	{
		x1 = x;
		x = x->next;
		delete x1;
	}
	delete head;
}

int main()
{
	list* head;
	head = new list;

	inputList(head);
	ProizvChetN(head);
	outList(head);
	DelList(head);
	return 0;
}