﻿#include <iostream>
using namespace std;

int tabs = 0; //для отступов

//структура ветки
struct Branch
{
	int Data; // поле данных
	Branch* LeftB; // указатели на соседние ветки
	Branch* RightB;
};
//функция внесения данных
void Add(int aData, Branch*& aBranch)
{
	if (!aBranch) // если ветки не существует, то создание и заполнение данными
	{
		aBranch = new Branch;
		aBranch->Data = aData;
		aBranch->LeftB = 0;
		aBranch->RightB = 0;
		return;
	}
	else // иначе сверяем
		if (aBranch->Data > aData)
		{
			Add(aData, aBranch->LeftB);
		}
		else
		{
			Add(aData, aBranch->RightB);
		};
}
//функция вывода
void print(Branch* aBranch)
{
	if (!aBranch) return; //если ветки нет, тогда выходим
	tabs += 5; //увеличиваем счетчик для отсупов
	print(aBranch->LeftB); //ветка и подветки слева
	for (int i = 0; i < tabs; i++) cout << " "; //отступы
	cout << aBranch->Data << endl; //данные ветки
	print(aBranch->RightB); // справа
	tabs -= 5;
	return;
}

int main()
{
	setlocale(LC_ALL, "rus");
	Branch* Root = 0;
	int N; //количество элементов
	int el;
	int k;

	cout << "Введите количство элементов дерева: ";
	cin >> N;
	cout << endl;

	for (int i = 0; i < N; i++)
	{
		Add(rand() % 100, Root);
	}

	cout << "Вывод бинарного дерева: " << endl;
	print(Root);
	cout << endl;
	return 0;
}