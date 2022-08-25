// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "windows.h"

struct List
{
	int data;
	List* Next;
};

List* CreateSpisok(List* head, int* Digits) //заполнение списка, инициализация списка
{
	List* x1 = NULL;
	head->Next = NULL;
	head->data = Digits[0];
	for (int i = 1; i < 5; i++)
	{
		x1 = new List;
		x1->data = Digits[i];
		x1->Next = head;
		head = x1;
	}
	return head;
}

void PrintSpisok(List* head) //выводим список
{
	List* x = head;
	while (x != NULL)
	{
		std::cout << x->data << " ";
		x = x->Next;
	}
}

List* DelBegin(List* head) // удаляем первый элемент
{
	List* x = head;
	head = head->Next;
	delete x;
	return head;
}

void Delptr(List* head, int ptr)//удаляем выбранный из множества элемент
{
	List* x = NULL;
	x = head;
	while (x->Next->data != ptr)
	{
		x = x->Next;
	}
	List* p = new List;
	p = x->Next;
	x->Next = x->Next->Next;
	delete p;
}

void DelEnd(List* head) //удаляем последний элемент
{
	List* x = head;
	while (x->Next->Next != NULL)
	{
		x = x->Next;
	}
	delete x->Next;
	x->Next = NULL;
}

List* DelSpisok(List* head) //удаляем весь список
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

List* InsertBegin(List* head, int insert) //вставить введенное число в начало
{
	List* x1 = new List;
	x1->data = insert;
	x1->Next = head;
	head = x1; //на первый теперь как и обычно указывает head, а не x1
	return head;
}

void InsertPeredElement(List* head, int ptr/*который указываем из массива*/, int insert)//вставить введенное число перед ptr(число, которое выбрали из множества)
{
	List* x1 = head;
	while (x1->Next->data != ptr)
	{
		x1 = x1->Next;
	}
	List* x2 = new List;
	x2->data = insert;
	x2->Next = x1->Next;
	x1->Next = x2;
}

void InsertPosleElement(List* head, int ptr, int insert)//вставить введенное число после ptr
{
	List* x1 = head;
	while (x1->data != ptr)
	{
		x1 = x1->Next;
	}
	List* x2 = new List;
	x2->data = insert;
	x2->Next = x1->Next;
	x1->Next = x2;
}

void EndInsertElement(List* head, int insert) //вставить элемент последним
{
	List* x2 = head;
	while (x2->Next != NULL)
	{
		x2 = x2->Next;
	}
	List* x1 = new List;
	x1->data = insert;
	x2->Next = x1;
	x1->Next = NULL;
}

int main()
{
	setlocale(0, "");

	List* head;
	head = new List;

	int Digits[5] = { 1,7,5,3,9 }; //множество чисел, которым заполняется список (в дальнейшем из этого списка выбирается число и сохраняется в переменной ptr)

	std::cout << "Список :" << std::endl;
	head=CreateSpisok(head, Digits); //создаем список из множества и инициализируем
	PrintSpisok(head); //выводим получившийся список

	int insert; //хранит число, которое нужно будет вставить
	std::cout << std::endl << "Введите число, которое нужно вставить в список (начало, конец, за, после) : " << std::endl;
	std::cin >> insert;
	std::cout << "Вы ввели : " << insert;

	int ptr; //элемент, до которого и после которого нужно вставить введенное число
	std::cout << std::endl << "Выберите элемент из списка, возле которого вы хотите вставить ваше число {";
	for (int i = 0; i < 5; i++)
	{
		std::cout << Digits[i] << ", ";
	}
	std::cout << "} : ";
	std::cin >> ptr;
	std::cout << "вы выбрали : " << ptr << std::endl;

	head = InsertBegin(head, insert);//вставляем в начало
	InsertPeredElement(head, ptr, insert);//вставляем введенное число перед выбранным элементом
	InsertPosleElement(head, ptr, insert);//вставляем введенное число после выбранного элемента
	EndInsertElement(head, insert);//вставляем в конец

	std::cout << "Добавление элементов : " << std::endl;
	PrintSpisok(head); //печатаем список с добавленными элементами

	std::cout << std::endl << "Удаление в начале, в конце и выбранного элемента (из массива) : " << std::endl;
	head = DelBegin(head); //удаляем вначале элемент
	Delptr(head, ptr);//удаляем выбранный элемент
	DelEnd(head);//удаляем элемент в конце

	PrintSpisok(head);//печатаем список с удаленными элементами

	DelSpisok(head);//удаляем список полностью
	return 0;
}