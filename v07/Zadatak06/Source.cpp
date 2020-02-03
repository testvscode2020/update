#include <iostream>
#include "btree.h"

using namespace std;

/*
* Ispišite kako bi izgledao ispis čvorova ako stablo obiđemo BFS
algoritmom. Proširite klasu btree i implementirajte takav obilazak
tako da potpis metode bude:
void bfs(node* current);
Obilazak započnite ovako:
tree.bfs(tree.root());
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

	tree.bfs(tree.root());

	return 0;
}