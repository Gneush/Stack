#pragma once
#include "gen_tree.h"

void Tree::DeleteSubtree(Node *node) {
	if (node) {
		DeleteSubtree(node->left);
		DeleteSubtree(node->right);
		delete node;
	}
}

void Tree::Add(Node* &node, const int &item) {
	if (node == NULL) {
		node = new Node(item);
	}
	else if (item < node->item) {
		Add(node->left, item);
	}
	else {
		Add(node->right, item);
	}
}
