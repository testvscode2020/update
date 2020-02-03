#include <iostream>
#include "btree.h"

using namespace std;

/*
Napišite program koji implementira prikazano 
stablo pomoću klase btree (u prilogu):
*/

int main() {
	btree tree("a");
	tree.insert_left(tree.root(), "b");
	tree.insert_right(tree.root(), "c");

	node* c = tree.get_right_child(tree.root());
	tree.insert_right(c, "d");

	node* d = tree.get_right_child(c);
	tree.insert_left(d, "e");
	tree.insert_right(d, "f");

	node* e = tree.get_left_child(d);
	tree.insert_left(e, "g");
	tree.insert_right(e, "h");

	node* f = tree.get_right_child(d);
	tree.insert_right(f, "i");

	cout << "inorder:" << endl;
	tree.inorder(tree.root());
	cout << "preorder:" << endl;
	tree.preorder(tree.root());
	cout << "postorder:" << endl;
	tree.postorder(tree.root());

	return 0;
}