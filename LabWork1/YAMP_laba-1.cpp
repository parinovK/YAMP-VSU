// YAMP_laba-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*Создать циклический двунаправленный список из целых чисел. Определить произведение чётных значений элементов списка и вставить элемент со значением, равным вычисленному произведению в конец списка.*/

#include <iostream>
#include "windows.h"

using namespace std;

struct list
{
	int data;
	list* next;
	list* pred;
};

void inputList(list* head)
{
	list* x1=NULL, * x2=NULL; //запоминать нужный адрес ячейки
	head->data = 0;
	head->next = NULL; //ссылка на след элемент пустая (ни на что не указывает, нужно для условия(*))
	int y;
	while (cin >> y)
	{
		x1 = new list; // объявляется новый элемент списка(нынешний, сейчас который), текущий
		x1->data = y;
		if (head->next == NULL) // (*), если нет следующего элемента (если ссылка у элемента head на след элемент пустая )
		{ //связываем head с текущим и текущий с главным
			head->next = x1;
			x1->pred = head; 
		}
		else
		{
			x2->next = x1; //связываем элементы списка, второму(предыдущему) присваем первый(нынешний), а первому присваем второе
			x1->pred = x2;
		}
		x2 = x1; //запоминаем текущий(x1), как предыдущий(x2)
	}
	x1->next = head; //для цикла, самый последний элемент списка присваивает главный элемент head
	head->pred = x1;
}

void outList(list* head)
{
	list* x = NULL;
	x = head->next; //x = следующий элемент после head
	while (x != head) //пока x не равен первому элементу
	{
		cout << x->data << endl; // выводит элемент находящийся в списке
		x = x->next; // x переходит на следующий элемент
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

		if ((x->data % 2 == 0) && (x->data != 0))
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
	head = new list; //создает динамическую переменную структурного типа list
	inputList(head);
	ProizvChetN(head);
	outList(head);
	DelList(head);
	return 0;
}