// YAMP_KR.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Создать линейный однонаправленный список из целых чисел. Удалить из списка первый элемент со значением 10.

#include <iostream>

using namespace std;

struct List
{
	int data;
	List* Next;
};

void CreateList(List *head, int *Digits)
{
	List* x1 = NULL, * x2 = NULL;
	head->Next = NULL;
	head->data = Digits[0];

	for (int i = 1; i < 5; i++)
	{
		x1 = new List;
		x1->data = Digits[i];

		if (head->Next == NULL)
		{
			head->Next = x1;
		}
		else
		{
			x2->Next = x1;
		}
		x2 = x1;
	}
	x1->Next = NULL;
}

void OutputList(List* head)
{
	List* x = head;
	while (x != NULL)
	{
		cout << x->data << endl;
		x = x->Next;
	}
}

List* DeleteElementTen(List* head)
{
	List* x = head;
	List* tmp = NULL;
	while (x != NULL)
	{
		if (x->data == 10)
		{
			if (x == head)
			{
				head = head->Next;
				delete x;
				x = head;
			}
			else
			{
				tmp->Next = x->Next;
				delete x;
				x = tmp->Next;
			}
		}
		else
		{
			tmp = x;
			x = x->Next;
		}
	}
	return head;
}

List* DelList(List* head)
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

	List* head;
	head = new List;

	int Digits[5] = { 10,5,6,10,2 };

	CreateList(head, Digits);
	cout << "Созданный список : " << endl;
	OutputList(head);
	cout << endl << "Список без 10-ки : " << endl;
	head = DeleteElementTen(head);
	OutputList(head);
	DelList(head);
}