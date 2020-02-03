#ifndef _BINARNO_STABLO_H_
#define _BINARNO_STABLO_H_

#include <string>
#include <queue>
using namespace std;

struct node {
	string element;
	node* left_child;
	node* right_child;
};

class btree {
private:
	node* root_node;
	node* create_new_node(string element);
	void destroy(node* current);
	void bfs(queue<node*>& q);
public:
	btree(string element);
	~btree();
	void insert_left(node* parent, string element);
	void insert_right(node* parent, string element);
	node* root();
	node* get_left_child(node* parent);
	node* get_right_child(node* parent);
	void inorder(node* current);
	void preorder(node* current);
	void postorder(node* current);
	void bfs(node* current);
};

#endif