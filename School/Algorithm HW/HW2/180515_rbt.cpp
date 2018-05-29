#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

struct node {
	// 0 for black, 1 for red
	int color;
	int value;
	int rank;
	node * parent;
	node * left;
	node * right;
	node(int v, int r, int c) : color(c), value(v), rank(r), parent(NULL), left(NULL), right(NULL) {}
};

class rbt2 {
public:
	rbt2() {
		vector<int> tmp(1000, 0);
		data = tmp;
	}
	int insert(int x);
	int remove(int x);
	int select(int x);
	int rank(int x);
private:
	vector<int>  data;
};

int rbt2::insert(int x) {
	if (data[x] == 0) {
		data[x] = 1;
		return x;
	}
	else {
		return 0;
	}
	return 0;
}

int rbt2::remove(int x) {
	if (data[x] == 1) {
		data[x] = 0;
		return x;
	}
	else {
		return 0;
	}
	return 0;
}

int rbt2::select(int x) {
	int count = 0;
	for (int i = 0; i < 1000; i++) {
		if (data[i] == 1) count++;
		if (count == x) return i;
	}
	return 0;
}

int rbt2::rank(int x) {
	if (data[x] == 0) {
		return 0;
	}
	else {
		int count = 0;
		for (int i = 0; i <= x; i++) {
			if (data[x] == 1) count++;
		}
		return count;
	}
	return 0;
}

class rbt {
public:
	rbt() {
		nil = new node(-9999, -9999, 0);
		nil->parent = NULL;
		nil->left = nil;
		nil->right = nil;
		root = nil;
	}
	int insert(int x);
	int remove(int x);
	int select(int x);
	int rank(int x);
	// tester functions
	bool isbst2() {
		vector<int> test;
		isbstr(root, &test);
		if (test.size() <= 1) {
			return 1;
		}
		for (int i = 1; i < test.size(); i++) {
			if (test[i] < test[i - 1]) {
				return 0;
			}
		}
		if (computeBlackHeight(root) == -1) {
			return 0;
		}
		return 1;
	}
	bool isbst() {
		vector<int> test;
		isbstr(root, &test);
		if (test.size() <= 1) {
			cout << "MATCHED" << endl;
			return 1;
		}
		for (int i = 1; i < test.size(); i++) {
			if (test[i] < test[i - 1]) {
				cout << "INVALID BST" << endl;
				return 0;
			}
		}
		if (computeBlackHeight(root) == -1) {
			cout << "INVALID RB" << endl;
			return 0;
		}
		cout << "MATCHED" << endl;
		return 1;
	}
	void print() {
		postorder(root);
	}
private:
	node * tree_successor(node * x);
	node * tree_minimum(node * x);
	int computeBlackHeight(node* currNode) {
		// For an empty subtree the answer is obvious
		if (currNode == nil)
			return 0;
		// Computes the height for the left and right child recursively
		int leftHeight = computeBlackHeight(currNode->left);
		int rightHeight = computeBlackHeight(currNode->right);
		int add = currNode->color == 0 ? 1 : 0;
		// The current subtree is not a red black tree if and only if
		// one or more of current node's children is a root of an invalid tree
		// or they contain different number of black nodes on a path to a null node.
		if (leftHeight == -1 || rightHeight == -1 || leftHeight != rightHeight)
			return -1;
		else
			return leftHeight + add;
	}
	void transplant(node * to, node * from) {
		if (to->parent == nil) root = from;
		else if (to == to->parent->left) to->parent->left = from;
		else to->parent->right = from;
		from->parent = to->parent;
	}
	// recursive helpers
	void isbstr(node * x, vector<int> * data) {
		if (x == nil) return;
		isbstr(x->left, data);
		data->push_back(x->value);
		isbstr(x->right, data);
	}
	void postorder(node* p, int indent = 0)
	{
		if (p != nil) {
			if (p->right) {
				postorder(p->right, indent + 4);
			}
			if (indent) {
				for (int i = 0; i < indent; i++) {
					cout << ' ';
				}
			}
			if (p->right != nil) std::cout << " /\n";
			if (indent) {
				for (int i = 0; i < indent; i++) {
					cout << ' ';
				}
			}
			cout << "" << p->value << "/" << p->rank;
			if (p->color == 0) cout << "/B" << "\n ";
			else cout << "/R" << endl;
			if (p->left != nil) {
				for (int i = 0; i < indent; i++) {
					cout << ' ';
				}
				cout << "s\n";
				postorder(p->left, indent + 4);
			}
		}
	}
	int rerank(node * x);
	void rotateleft(node * x);
	void rotateright(node * x);
	node * grandparent(node * root);
	node * sibling(node * root);
	node * uncle(node * root);
	int selecth(node * root, int x);
	void idelete(node * runner);
	void idelete2(node * here);
	void idelete3(node * x);
	void swap(node * node1, node* node2);
	void dreconstruct(node * x);
	void dreconstruct2(node * x, node * par, bool isleft);
	void reconstruct(node * root);
	node * search(int x);
	node * root;
	node * nil;
};

void rbt::reconstruct(node * root) {
	if (root == nil) return;
	if (root == this->root && this->root->color == 1) {
		this->root->color = 0;
		return;
	}
	if (root->color == 0) return;
	// restruct rb tree when parent & I are red(grandparent existence guaranteed because
	// parent is red, and root is always black
	if (root->parent->color == 1) {
		if (uncle(root) != nil && uncle(root)->color == 1) {
			// when uncle is also red and existant, change their colors
			root->parent->color = 0;
			uncle(root)->color = 0;
			grandparent(root)->color = 1;
			reconstruct(grandparent(root));
		}
		else {
			// prepare them for rotation if needed
			if (root == grandparent(root)->left->right) {
				rotateleft(root->parent);
				root = root->left;
			}
			else if (grandparent(root)->right->left == root) {
				rotateright(root->parent);
				root = root->right;
			}
			// rotate
			root->parent->color = 0;
			grandparent(root)->color = 1;
			if (root == root->parent->left) rotateright(grandparent(root));
			else rotateleft(grandparent(root));
		}
	}
}

int rbt::insert(int x) {
	// check if tree has value
	node * runner = search(x);
	if (runner != nil) return 0;
	// if not present, add ranks and new node
	if (root == nil) {
		root = new node(x, 1, 0);
		root->parent = nil;
		root->left = nil;
		root->right = nil;
		return x;
	}
	else {
		node * parent = root;
		runner = root;
		while (runner != nil) {
			if (runner->value>x) {
				runner->rank++;
				parent = runner;
				runner = runner->left;
			}
			else {
				runner->rank++;
				parent = runner;
				runner = runner->right;
			}
		}
		// add new node
		if (parent->value>x) {
			parent->left = new node(x, 1, 1);
			parent->left->parent = parent;
			parent->left->left = nil;
			parent->left->right = nil;
			runner = parent->left;
		}
		else {
			parent->right = new node(x, 1, 1);
			parent->right->parent = parent;
			parent->right->left = nil;
			parent->right->right = nil;
			runner = parent->right;
		}
	}

	// parent existence guaranteed
	reconstruct(runner);
	rerank(this->root);
	return x;
}

int rbt::rerank(node * x) {
	if (x == nil) return 0;
	int curr = 0;
	curr += rerank(x->left);
	curr += rerank(x->right);
	x->rank = curr + 1;
	return curr + 1;
}

// from CLRS 3rd ed, pp 292
node* rbt::tree_minimum(node* x)
{
	while (x->left!=nil)
	{
		x = x->left;
	}
	return x;
}

node* rbt::tree_successor(node* x)
{
	if (x->right!=nil)
	{
		return tree_minimum(x->right);
	}
	auto y = x->parent;
	while ((y->parent!=nil) && (x == y->right))
	{
		x = y;
		y = y->parent;
	}
	return y;
}

void rbt::idelete2(node * here) {
	node * y;
	if (here->left == nil || here->right == nil) {
		y = here;
	}
	else {
		y = tree_successor(here);
	}

	node * x;
	if (y->left != nil) {
		x = y->left;
	}
	else {
		x = y->right;
	}
	if (x != nil) {
		x->parent = y->parent;
	}
	node * xParent = y->parent;

	bool yIsLeft = false;
	if (y->parent == nil) {
		root = x;
	}
	else if (y == y->parent->left) {
		y->parent->left = x;
		yIsLeft = true;
	}
	else {
		y->parent->right = x;
		yIsLeft = false;
	}

	if (y != here) {
		here->value = y->value;
	}

	nil->parent = nil;
	nil->left = nil;
	nil->right = nil;

 	if (root!=nil && y->color==0) {
		//print();
		//cout << x->value << " " << y->value << " " << xParent->value << " " << yIsLeft << endl;
		//cout << root->value << endl;
		dreconstruct2(x,xParent, yIsLeft);
	}
}

// recolor when needed
void rbt::dreconstruct2(node * x, node * par, bool isleft) {
	//cout << "dre2" << endl;
	// parent existing case, if root just color root black and end
	// root coloring at end
	while (x!=root && x->color == 0) {
		//cout << "in loop " << x->value << endl;
		node * w;
		if (isleft) {
			//cout << "isleft" << endl;
			w = par->right;
			// case 2-4 to case 1
			if (w->color == 1) {
				//cout << "fixing case 2-4 to 1" << endl;
				w->color = 0;
				par->color = 1;
				rotateleft(par);
				w = par->right;
			}
			// case 2-1
			if (w->left->color == 0 && w->right->color == 0) {
				//cout << "fixing case 2-1" << endl;
				w->color = 1;
				x = par;
				par = par->parent;
				isleft = (x==par->left);
			}
			else {
				//cout << "non recursive fix" << endl;
				// case *3
				if (w->right->color == 0) {
					//cout << "fixing case 3" << endl;
					w->left->color = 0;
					w->color = 1;
					rotateright(w);
					w = par->right;
				}
				// case 1-1
				w->color = par->color;
				par->color = 0;
				if(!(w->left->color==0&&w->right->color==0)){
					// case *-2
					//cout << "fixing case *-2" << endl;
					w->right->color = 0;
					rotateleft(par);
				}
				x = this->root;
			}
		}
		else {
			//cout << "isright" << endl;
			w = par->left;
			// case 2-4 to case 1
			if (w->color == 1) {
				//cout << "fixing case 2-4 to 1" << endl;
				w->color = 0;
				par->color = 1;
				rotateright(par);
				w = par->left;
			}
			// case 2-1
			if (w->right->color == 0 && w->left->color == 0) {
				//cout << "fixing case 2-1" << endl;
				w->color = 1;
				x = par;
				par = par->parent;
				isleft = (x==par->left);
			}
			else {
				//cout << "non recursive fix" << endl;
				// case *3
				if (w->left->color == 0) {
					//cout << "fixing case 3" << endl;
					w->right->color = 0;
					w->color = 1;
					rotateleft(w);
					w = par->left;
				}
				// case 1-1
				w->color = par->color;
				par->color = 0;
				if(!(w->left->color==0&&w->right->color==0)){
					// case *-2
					//cout << "fixing case *-2" << endl;
					w->left->color = 0;
					rotateright(par);
				}
				x = this->root;
			}
		}
		nil->color = 0;
	}
	if(x!=nil) x->color = 0;
	//cout << "dre result" << endl;
	//print();
	//isbst();
}

// delete rbt simillar to bst
void rbt::idelete(node * runner) {
	node * y = runner;
	node * x;
	int oc = runner->color;
	if (runner->left == nil) {
		x = runner->right;
		transplant(runner, runner->right);
	}
	else if (runner->right == nil) {
		x = runner->left;
		transplant(runner, runner->left);
	}
	else {
		// get minimum element from right subtree
		y = runner->right;
		while (y->left != nil) {
			y = y->left;
		}
		oc = y->color;
		x = y->right;
		if (y->parent == runner) x->parent = y;
		else {
			transplant(y, y->right);
			y->right = runner->right;
			y->right->parent = y;
		}
		transplant(runner, y);
		y->left = runner->left;
		y->left->parent = y;
		y->color = runner->color;
	}
	if(x==nil) cout << "fucked" << endl;
	if (root!=nil && oc == 0) dreconstruct(x);
}

// recolor when needed
void rbt::dreconstruct(node * x) {
	cout << "dre2" << endl;
	while (x->parent != nil && x->color == 0) {
		cout << "in loop " << x->value << endl;
		node * par = x->parent;
		node * w;
		if (x == x->parent->left) {
			cout << "left" << endl;
			w = x->parent->right;
			if (w->color == 1) {
				cout << "lf" << endl;
				w->color = 0;
				x->parent->color = 1;
				rotateleft(x->parent);
				w = par->right;
			}
			if (w->left->color == 0 && w->right->color == 0) {
				cout << "ls" << endl;
				w->color = 1;
				x = par;
			}
			else {
				cout << "rt" << endl;
				if (w->right->color == 0) {
					w->left->color = 0;
					w->color = 1;
					rotateright(w);
					w = par->right;
				}
				w->color = par->color;
				par->color = 0;
				w->right->color = 0;
				if(w->right!=nil) w->right->color=0;
				rotateleft(par);
				x = this->root;
			}
		}
		else {
			cout << "right" << endl;
			w = x->parent->left;
			if (w->color == 1) {
				cout << "rf" << endl;
				w->color = 0;
				x->parent->color = 1;
				rotateright(x->parent);
				w = par->left;
			}
			if (w->right->color == 0 && w->left->color == 0) {
				cout << "rs" << endl;
				w->color = 1;
				x = x->parent;
			}
			else {
				cout << "rt" << endl;
				if (w->left->color == 0) {
					w->right->color = 0;
					w->color = 1;
					rotateleft(w);
					w = par->left;
				}
				w->color = x->parent->color;
				x->parent->color = 0;
				w->left->color = 0;
				if(w->left!=nil) w->left->color = 0;
				rotateright(par);
				x = this->root;
			}
		}
	}
	if(x!=nil) x->color = 0;
}

void rbt:: swap(node * node1, node * node2){
	node * tmpp = node1->parent;
	node * tmpl = node1->left;
	node * tmpr = node1->right;
	node1->parent=node2->parent;
	node1->left=node2->left;
	node1->right=node2->right;
	node2->parent=tmpp;
	node2->left=tmpl;
	node2->right=tmpr;
}

void rbt::idelete3(node * runner){
	if(runner==nil) return;
	// check which state runner is in
	if(runner->color==1&&runner->left==nil&&runner->right==nil){
		if(runner==root){
			root=nil;
		}else if(runner->parent->left==runner){
			runner->parent->left = nil;
		}else{
			runner->parent->left = nil;
		}
		return;
	}else if(runner->left!=nil&&runner->right!=nil){
		node * next = tree_successor(runner);
		
	}
}

int rbt::remove(int x) {
	//cout << "remove " << x << endl;
	node * runner = search(x);
	if (runner == nil) return 0;
	idelete2(runner);
	rerank(root);
	return x;
}
// rotate functions
void rbt::rotateleft(node * x) {
	node * y = x->right;
	x->right = y->left;
	if (y->left != nil) {
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nil) {
		this->root = y;
	}
	else if (x->parent->left == x) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

void rbt::rotateright(node * x) {
	node *y = x->left;
	x->left = y->right;
	if (y->right != nil) {
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nil) {
		this->root = y;
	}
	else if (x->parent->left == x) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}
	y->right = x;
	x->parent = y;
}

// helper functions to make code readable
node * rbt::grandparent(node * root) {
	if (root == nil) return nil;
	if (root->parent == nil) return nil;
	else return root->parent->parent;
}

node * rbt::sibling(node * root) {
	if (root == nil) return nil;
	if (root->parent == nil) return nil;
	if (root->parent->left == root) return root->parent->right;
	else return root->parent->left;
}

node * rbt::uncle(node * root) {
	if (root == nil) return nil;
	if (grandparent(root) == nil) return nil;
	else return sibling(root->parent);
}

// search for value x
node * rbt::search(int x) {
	if (root == nil) {
		return nil;
	}
	else {
		node * runner = root;
		while (runner != nil) {
			if (runner->value == x) return runner;
			else if (runner->value>x) {
				runner = runner->left;
			}
			else {
				runner = runner->right;
			}
		}
	}
	return nil;
}

// recursive helper function for searching x
int rbt::selecth(node * root, int x) {
	if (root == nil) return 0;
	int curr = root->left == nil ? 0 : root->left->rank;
	if (curr == x) return root->value;
	else if (curr<x) return selecth(root->left, x);
	else return selecth(root->right, x - (curr + 1));
}

int rbt::select(int x) {
	if (root == nil) return 0;
	if (root->rank<x) return 0;
	return selecth(root, x - 1);
}

int rbt::rank(int x) {
	// look for value x
	node * here = search(x);
	if (here == nil) return 0;
	// add up ranks to get total rank from found element
	int ret = here->left == nil ? 0 : here->left->rank + 1;
	while (here != nil) {
		if (here == here->parent->right) {
			ret += here->parent->left == nil ? 0 : here->parent->left->rank + 1;
		}
		here = here->parent;
	}
	return ret;
}

void tester() {
	srand(time(NULL));
	rbt test;
	rbt2 test2;

	// input test
		for (int i = 0; i < 10000; i++) {
		if(i%1000==0){
			cout << "input at " << i << endl;
		}
		int y = rand() % 1000;
		if (test.insert(y) != test2.insert(y)) {
			cout << "insert error at : " << i << endl;
			test.print();
			while(1){}
			return;
		}
		if (!test.isbst2()) {
			test.print();
			cout << "rb violated at " << i << endl;
			while(1){}
		}

	}

	cout << "input validated" << endl;

	//io test
	cout << "io test" << endl;
	for (int i = 0; i < 10000; i++) {
		if(i%1000==0){
			cout << "io at " << i << endl;
		}
		int y = rand() % 1000;
		if (test.insert(y) != test2.insert(y)) {
			cout << "insert error at : " << i << endl;
			test.print();
			while(1){}
			return;
		}
		if (!test.isbst2()) {
			test.print();
			cout << "r1b violated at " << i << endl;
			while (1) {}
		}
		y = rand() % 1000;
		if (test.insert(y) != test2.insert(y)) {
			cout << "insert error at : " << i << endl;
			test.print();
			while(1){}
			return;
		}
		if (!test.isbst2()) {
			test.print();
			cout << "r2b violated at " << i << endl;
			while (1) {}
		}
		y = rand() % 1000;
		if (test.remove(y) != test2.remove(y)) {
			cout << "remove error at : " << i << endl;
			test.print();
			while(1){}
			return;
		}
		if (!test.isbst2()) {
			test.print();
			cout << "rb violated at " << i << endl;
			while(1){}
		}

	}
	cout << "io validated" << endl;

	// all instructions test
	cout << "random instructions test" << endl;
	for (int i = 0; i < 10000; i++) {
		if(i%1000==0) cout << "inst at " << i << endl;
		int x = rand() % 4;
		int y = rand() % 1000;
		switch (x) {
		case 0:
			if (test.insert(y) != test2.insert(y)) {
				cout << "insert error at : " << i << endl;
				test.print();
				return;
			}
			break;
		case 1:
			if (test.remove(y) != test2.remove(y)) {
				cout << "delete error at : " << i << endl;
				test.print();
				return;
			}
			break;
		case 2:
			if (test.select(y) != test.select(y)) {
				cout << "select error at : " << i << endl;
				test.print();
				return;
			}
			break;
		case 3:
			if (test.rank(y) != test.rank(y)) {
				cout << "rank error at : " << i << endl;
				test.print();
				return;
			}
			break;
		}
		if (!test.isbst2()) {
			test.print();
			test.isbst();
			cout << "at " << i << endl;
			return;
		}
	}
	cout << "randinst terminated successfully" << endl;
}

int tester2(){
	cout << "simple task generator" << endl;
	rbt test;
	while(1){
		char c;
		int x;
		cin >> c >> x;
		switch(c){
			case 'Q':
				return 0;
			case 'I':
				cout << test.insert(x) << endl;
				test.print();
				break;
			case 'R':
				cout << test.rank(x) << endl;
				test.print();
				break;
			case 'D':
				cout << test.remove(x) << endl;
				test.print();
				break;
			case 'S':
				cout << test.select(x) << endl;
				test.print();
				break;
			default:
				cout << "I, D, R, S, Q" << endl;
				break;	
		}
		test.isbst();
	}
	return 0;
}

int tester3(){
	rbt test;
	test.insert(100);
	test.insert(150);
	test.insert(50);
	test.insert(200);
	test.remove(150);
	test.remove(50);
	test.print();
	tester();
	return 0;
}

int main(int argc, char **argv) {
	//tester();
	
	vector<pair<char, int> > inst;
	// checker for valid arguments
	if (argc != 2) {
		cout << "[ERROR] invalid arguments : give one file name!" << endl;
		return 0;
	}
	// read file to memory
	ifstream openfile(argv[1]);

	while (openfile && !openfile.eof()) {
		char tmp1;
		int tmp2;
		openfile >> tmp1 >> tmp2;
		//if(openfile.eof()) break;
		inst.push_back(pair<char, int>(tmp1, tmp2));
	}

	// do instructions and output file
	rbt book;
	ofstream out("out.txt");
	for (int i = 0; i < inst.size(); i++) {
		char x = inst[i].first;
		switch (x) {
		case 'I':
			out << book.insert(inst[i].second) << endl;
			break;
		case 'R':
			out << book.rank(inst[i].second) << endl;
			break;
		case 'S':
			out << book.select(inst[i].second) << endl;
			break;
		case 'D':
			out << book.remove(inst[i].second) << endl;
			break;
		default:
			cout << "invalid input found" << endl;
			return 0;
			break;
		}
	}
	out.close();
	return 0;
}
