#pragma once // защита от двойного подключения заголовочных файлов
#include <stddef.h>
class Tree {
	struct Node {
		int item;
		Node *left;
		Node *right;

		Node(int i, Node *s = NULL, Node *b = NULL) {
			item = i;
			left = s;
			right = b;
		}
	};

	Node *root; // указатель на корневой элемент

public:
	Tree() {
		root = NULL; // конструктор
	}
	~Tree() {
		DeleteSubtree(root); // деструктор
	}
	//int GetHeight() { // определение высоты
	//	return GetHeight(root);
	//}
	//int GetNodesOnLevel(int level) { // количество узлов
	//	return GetNodesOnLevel(root, level);
	//}
	void Add(const int &elem) { // добавление элемента
		Add(root, elem);
	}

private:
	void Add(Node* &node, const int &elem);
	void DeleteSubtree(Node *node);/*
								   int GetHeight(Node *node);
								   int GetNodesOnLevel(Node *node, int level);*/
};
