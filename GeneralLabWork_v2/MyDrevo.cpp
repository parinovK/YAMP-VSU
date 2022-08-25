// MyDrevo.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Общая - дерево.

#include <iostream>
#include <ctime>

using namespace std;

struct Drevo
{
	int data; //данные
	Drevo* Left;//указатель на левую часть
	Drevo* Right; //указатель на правую часть
};

Drevo* Ins(Drevo* head, int dat);

Drevo* InitDrevo(Drevo* head)
{
	int dat, n;
	cout << "Введите количество элементов: " << endl;
	cin >> n;
	cout << "Введите последовательность чисел: " << endl;
	cin >> dat;
	head = new Drevo;
	head->data = dat;
	head->Left = NULL;
	head->Right = NULL;
	for (int i = 1; i < 5; i++)
	{
		cin >> dat;
		head = Ins(head, dat);
	}
	return head;
}

Drevo* Ins(Drevo* head, int dat)
{
	if (dat < head->data)
	{
		if (head->Left == NULL)
		{
			Drevo* NewL = new Drevo;
			NewL->data = dat;
			NewL->Left = NULL;
			NewL->Right = NULL;
			head->Left = NewL;
		}
		else
			Ins(head->Left, dat);
	}
	else
		if (dat > head->data)
		{
			if (head->Right == NULL)
			{
				Drevo* NewL = new Drevo;
				NewL->data = dat;
				NewL->Left = NULL;
				NewL->Right = NULL;
				head->Right = NewL;
			}
			else
				Ins(head->Right, dat);
		}
	return head;
}

void OutLine(Drevo* head)
{
	if (head != NULL)
	{
		cout << head->data << " ";
		OutLine(head->Left);
		OutLine(head->Right);
	}
}

void OutSimmetr(Drevo* head)
{
	if (head != NULL)
	{
		OutSimmetr(head->Left);
		cout << head->data << " ";
		OutSimmetr(head->Right);
	}
}

void OutObr(Drevo* head)
{
	if (head != NULL)
	{
		OutObr(head->Left);
		OutObr(head->Right);
		cout << head->data << " ";
	}
}

Drevo* SearchKey(Drevo *head, int key)
{
	if (key == head->data) return head;
	else
		if (key < head->data)
		{
			if (head->Left != NULL)
			{
				return SearchKey(head->Left, key);
			}
			else return NULL;
		}
		else
		{
			if (head->Right)
			{
				return SearchKey(head->Right, key);
			}
			else return NULL;
		}
}

//Поиск для удаления
Drevo* SearchKey(Drevo* head, int key, Drevo** Pred)
{
	if (key == head->data) return head;
	else
		if (key < head->data)
		{
			if (head->Left != NULL)
			{
				*Pred = head;
				return SearchKey(head->Left, key, Pred);
			}
			else return NULL;
		}
		else
		{
			if (head->Right)
			{
				*Pred = head;
				return SearchKey(head->Right, key, Pred);
			}
			else return NULL;
		}
}



//удаление выбранного листа
void NoChildren(Drevo*& Pred, Drevo*& Tek);
void OneParentR(Drevo*& Pred, Drevo*& Tek, Drevo*& head);

void RebuildDrevo(Drevo* head, int key, Drevo* Pred)
{
	Pred = head;
	Drevo* Tek = head->Right;
	while (Tek->Left != NULL)
	{
		Pred = Tek;
		Tek = Tek->Left;
	}
	swap(head->data, Tek->data);

	if ((Tek->Left == NULL) && (Tek->Right == NULL))
	{
		NoChildren(Pred, Tek);
	}
	else
		if ((Tek->Left == NULL) && (Tek->Right != NULL))
		{
			OneParentR(Pred, Tek, head);
		}
}

void NoChildren(Drevo*& Pred, Drevo*& Tek)
{
	if (Pred != NULL)
	{
		if (Pred->Left == Tek) Pred->Left = NULL;
		else
			if (Pred->Right == Tek) Pred->Right = NULL;
	}
	delete Tek;
}

void OneParentL(Drevo*& Pred, Drevo*& Tek, Drevo*& head)
{
	if (Pred != NULL)
	{
		if (Pred->Left == Tek) Pred->Left = Tek->Left;
		else
			if (Pred->Right == Tek) Pred->Right = Tek->Left;
	}
	if (head == Tek) head = Tek->Left;
	delete Tek;
}

void OneParentR(Drevo*& Pred, Drevo*& Tek, Drevo*& head)
{
	if (Pred != NULL)
	{
		if (Pred->Left == Tek) Pred->Left = Tek->Right;
		else
			if (Pred->Right == Tek) Pred->Right = Tek->Right;
	}
	if (head == Tek) head = Tek->Right;
	delete Tek;
}

Drevo* DelNode(Drevo* head, int key, Drevo* Pred1)
{
	Drevo* Pred = Pred1;
	Drevo* Tek = NULL;
	Tek = SearchKey(head, key, &Pred);
	if ((Tek->Left == NULL) && (Tek->Right == NULL))
	{
		NoChildren(Pred, Tek);
	}
	else
		if ((Tek->Left != NULL) && (Tek->Right == NULL))
		{
			OneParentL(Pred, Tek, head);
		}
		else
			if ((Tek->Left == NULL) && (Tek->Right != NULL))
			{
				OneParentR(Pred, Tek, head);
			}
			else
				if ((Tek->Left != NULL) && (Tek->Right != NULL))
				{
					RebuildDrevo(Tek, key, Pred);
				}
	return head;
}

//удаление всего дерева
Drevo* DeleteTree(Drevo* head)
{
	if (head != NULL)
	{
		head->Left = DeleteTree(head->Left);
		head->Right = DeleteTree(head->Right);
		delete head;
	}
	head = NULL;
	return head;
}


int main()
{
	setlocale(0, "");
	srand(time(NULL));

	Drevo* head = NULL;

	head = InitDrevo(head);//Инициализация Дерева

	cout << endl << "Введите еще один элемент и он будет добавлен в дерево: ";
	int new_data; //значение для нового листа
	cin >> new_data;
	Ins(head, new_data);//вставка нового листа

	//Три вывода
	cout << endl << ">>>>>>>>>>Способы обхода>>>>>>>>>>" << endl;
	cout << "Прямой: ";
	OutLine(head);
	cout << endl << "Симметричный: ";
	OutSimmetr(head);
	cout << endl << "Обратный: ";
	OutObr(head);
	
	//Поиск введенного элемента
	cout << endl << endl << "Введите значение, которое хотите найти: ";
	int key;
	cin >> key;
	if (SearchKey(head, key) == NULL)
		cout << "Элемент с таким значением не найден!";
	else
		cout << "Элемент с таким значением найден!";

	//Удаление выбранного листа
	cout << endl << "Какой лист вы хотите удалить? ";
	cin >> key;
	head = DelNode(head, key, NULL);
	cout << "Прямой обход: ";
	OutLine(head);
	//Удаление всего дерева
	head = DeleteTree(head);

	return 0;
}