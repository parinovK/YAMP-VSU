// YAMP_laba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*
Реализовать следующее: с клавиатуры вводится строка. Каждый символ заносится в узел списка. По заданному списку
должен быть построен другой список, в котором элементы будут расположены в обратном порядке, т.е. первый элемент исходного
списка в новом должен быть последним, второй - предпоследним...
*/

#include <iostream>
#include <string>

using namespace std;

struct List
{
	char data;
	List* Next;
};

List* CreateList(List* head, string str)
{
	List* x1 = NULL;
	head = NULL;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		x1 = new List;
		x1->data = str[i];
		x1->Next = head;
		head = x1;
	}
	return head;
}

List* CreateList2(List* head, List* head1)
{
	List* x1 = NULL;
	List* x = head;
	head1 = NULL;
	while (x != NULL)
	{
		x1 = new List;
		x1->data = x->data;
		x1->Next = head1;
		head1 = x1;
		x = x->Next;
	}
	return head1;
}

void OutputList(List* head)
{
	List* x = head;
	while (x != NULL)
	{
		cout << x->data << " ";
		x = x->Next;
	}
}

List* deleteList(List* head)
{
	List* x = head;
	while (head != NULL)
	{
		x = head;
		head = head->Next;
		delete x;
	}
	return head;
}

int main()
{
	setlocale(0, "");

	string str;
	cout << "Введите строку : ";
	getline(cin, str);

	List* head = new List;
	List* head1 = new List;

	head = CreateList(head, str);
	cout << "Список из строки : " << endl;
	OutputList(head);
	head1 = CreateList2(head, head1);
	cout << endl << "Обратный список : " << endl;
	OutputList(head1);
	head = deleteList(head);
	head1 = deleteList(head1);
}
