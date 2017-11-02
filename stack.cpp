#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include <iostream>
using namespace std;

void inizialization_stack(stack *S)
{
	S->top = NULL;						// адрес вершины = NULL (нет ещё вершины)
	S->size = 0;						// количество элементов = 0
}

void push(stack *S)                    // функция для добавления элемента в стек
{
	unsigned int count = 0;
	cout << "Сколько элементов вы хотите ввести? ";
	cin >> count;
	cout << "Введите элементы через пробел: \n";
	while (count)
	{
		int value;                         // "число" для ввода в стек
		cin >> value;					   // ввод переменной
		node *value_pointer = new node;    // выделяется память 
		value_pointer->data = value;       // получение введенного числа
		value_pointer->prev = S->top;      // текущая и предыдущая ячейки
		S->top = value_pointer;            // получение нового адреса для вершины 
		S->size++;
		count--;
	}
}

int pop(stack *S)                      // функция для удаления ячейки из стека
{
	int temp = 0;                      // временная переменная для хранения старой вершины
	node *value_pointer;				// указатель на структуру, которую удалим
	value_pointer = S->top;            // вершина - это адрес и мы приравнивает ее указателю
	temp = S->top->data;               // топ - адрес вершины, итем значение вершины и это значение хранится в темп
	S->top = value_pointer->prev;      // "нижний элемент" станет вершиной
	delete value_pointer;              // освобождение памяти
	S->size--;
	return temp;                       // возвращаем значение старой вершины
}

void output(stack *S)                  // функция для вывода стека
{
	node* pointer = S->top;             // взятие адреса вершины, чтобы вывести её, потом стек
	while (pointer != NULL)			   // последний элемент указывает на NULL или, если элементов нет, на NULL указывает сам стек
	{
		cout << pointer->data << endl; // выводим текущ. элемент стека
		pointer = pointer->prev;	   // переходим к следующ. элементу стека
	}
}
