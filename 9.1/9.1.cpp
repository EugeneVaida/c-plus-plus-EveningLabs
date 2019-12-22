// 9.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <time.h>
#include <string>

using namespace std;

const int example_size = 10;
const int tree_keys[example_size] = { 95, 26, 94, 80, 47, 59, 23, 57, 21, 82 };
const string tree_messages[example_size] = { "Aloft", "American Friends", "My Boss's Daughter",
											"Flight of Dragons, The", "Omega Man, The", "Backfire", "Apostle, The",
											"Dancing in the Rain", "Right at Your Door", "Pandorum" };

struct Node {
	int key;
	string message;
	Node* left = NULL;
	Node* right = NULL;

public:
	void print_node() {
		if (left) left->print_node();
		cout << "{ " << key << ": " << message << " }" << endl;
		if (right) right->print_node();
	}

	void free() {
		if (left) {
			left->free();
			delete (left);
		}
		if (right) {
			right->free();
			delete (right);
		}
	}
};

struct Tree {
	Node* root = NULL;
private:
	Node* get_insert_node(Node* deleted_node) {
		Node* insert_node;
		if (deleted_node->left) {
			insert_node = deleted_node->left;
			insert_node->get_max()->right = deleted_node->right;
		}
		else {
			insert_node = deleted_node->right;
		}
		return insert_node;
	}

public:
	void insert(int key, string message) {
		Node* created = new Node;
		created->key = key;
		created->message = message;
		created->left = NULL;
		created->right = NULL;
		Node* pointer = root;
		if (!pointer) {
			root = created;
			return;
		}
		while (pointer) {
			if (pointer->key < key) {
				if (pointer->right) {
					pointer = pointer->right;
				}
				else {
					pointer->right = created;
					break;
				}
			}
			else if (pointer->key > key) {
				if (pointer->left) {
					pointer = pointer->left;
				}
				else {
					pointer->left = created;
					break;
				}
			}
			else {
				break;
			}
		}
	};
	
	void print() {
		root->print_node();
	}

	void free() {
		root->free();
		delete (root);
	}
};

int tree_count_with_one_child(const Node* tr);

int main() {
	Tree tree;
	for (int i = 0; i < example_size; ++i) {
		tree.insert(tree_keys[i], tree_messages[i]);
	}
	tree.print();

	cout << endl;

	int i = tree_count_with_one_child(tree.root);

	std::cout << i;


	tree.free();
	return 0;
}

int tree_count_with_one_child(const Node* tr)
{
	int kol = 0;
	if (!tr) return 0;
	if ((tr->left == NULL) ^ (tr->right == NULL))
		kol = 1;
	return kol + tree_count_with_one_child(tr->left) + tree_count_with_one_child(tr->right);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
