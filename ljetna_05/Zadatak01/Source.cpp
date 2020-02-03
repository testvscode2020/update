#include <iostream>
#include "btree.h"

using namespace std;

/*
Implementirajte binarno stablo brojeva. 
Potom izgradite savršeno stablo koje inorder algoritmom ispisuje:
1, 2, 3, 4, 5, 6, 7.
Skicirajte redoslijed obilaska stabla za preorder i postorder algoritme.
Implementirajte metode inorder, preorder i postorder, pozovite ih 
i provjerite da li ste točno skicirali obilaske.
Implementirajte destruktror i objasnite.
*/


int main()
{

	btree tree(4);
	tree.insert_left(tree.root(), 2);
	tree.insert_right(tree.root(), 6);

	node *_2 = tree.get_left_child(tree.root());
	tree.insert_left(_2, 1);
	tree.insert_right(_2, 3);

	node *_6 = tree.get_right_child(tree.root());
	tree.insert_left(_6, 5);
	tree.insert_right(_6, 7);

	cout << "inorder:" << endl;
	tree.inorder(tree.root());

	cout << "preorder:" << endl;
	tree.preorder(tree.root());

	cout << "postorder:" << endl;
	tree.postorder(tree.root());

	return 0;
}