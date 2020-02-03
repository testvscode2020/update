#include <iostream>
#include "btree.h"

using namespace std;

/*
Implementirajte binarno stablo brojeva, koristeći postojeću implementaciju, 
izgrađenu prethodnim primjerima. Koliko je promjena potrebno učiniti?
Nacrtajte savršeno stablo koje postorder algoritmom ispisuje brojeve 
1, 2, 3, 4, 5, 6, 7.
Kreirajte i ispišite stablo postorder algoritmom.
*/

int main() {
	btree tree(7);
	tree.insert_left(tree.root(), 3);
	tree.insert_right(tree.root(), 6);

	node* _3 = tree.get_left_child(tree.root());
	tree.insert_left(_3, 1);
	tree.insert_right(_3, 2);

	node* _6 = tree.get_right_child(tree.root());
	tree.insert_left(_6, 4);
	tree.insert_right(_6, 5);

	tree.postorder(tree.root());

	return 0;
}