#include "stdafx.h"
#include <iostream>
using namespace std;
/*
struct card {
	char *shape;
	int number;
} cards[] = {
	"space", 1,
	"heart", 1,
	"diamond", 1,
	"clobber", 2
};

int main() {
	cout << cards[1].shape << endl;
	cards[1].shape = "hello";
	cout << cards[1].shape+2 << endl; // llo
	
}

*/

struct node {
	int value;
	node *leftnode;
	node *rightnode;
	node *parent;
};

class tree {
public:
	tree(int asd);
	~tree();
	void addtree(int i, node * nd);
	void printtree(node * nd);
	node * getroot();
	node * root;
private:
	
};

tree::tree(int asd) {
	node sam = { asd,NULL,NULL,NULL };
	root = &sam;
	/*root->value = asd;
	root->leftnode = NULL;
	root->rightnode = NULL;
	root->parent = NULL;*/
	cout << "making tree.." << endl;
}

tree::~tree() {
	cout << "deleting tree.." << endl;
}

node * tree::getroot() {
	return root;
}

void tree::addtree(int i, node* nd) {
	cout << nd->value << endl;
	node newnode = { i,NULL,NULL,nd };
	if (nd->leftnode == NULL) {
		nd->leftnode = &newnode;
	}
	else if (nd->rightnode == NULL) {
		nd->rightnode = &newnode;
	}
	else {
		cout << "full node - no leaf to add" << endl;
	}
}

void tree::printtree(node*nd) {
	if (nd->leftnode != NULL) {
		cout << "left" << endl;
		printtree(nd->leftnode);
	}
	else if (nd->rightnode != NULL) {
		cout << "right" << endl;
		printtree(nd->rightnode);
	}
	cout << nd->value << endl;
	return;
}
/*
int main() {
	cout << "yeah!" << endl;
	tree mytree(32);
	cout <<  mytree.getroot()->value << endl;
	node* ns;
	ns = mytree.getroot();
	node nsd = { 9999 ,NULL,NULL,NULL};
	mytree.printtree(&nsd);
	mytree.addtree(22,&nsd);
	//mytree.addtree(23, mytree.root);
	//mytree.printtree(mytree.getroot());
}
*/


struct mynode {
	int a;
	int b;
};

int main() {
	mynode sam = { 32,24 };
	cout << sam.a << sam.b;
	char * ch = "Hello World";
	//strcpy(ch, "Hello World");
	//cout << *ch << endl;
	
	cout << ch << endl;
}
