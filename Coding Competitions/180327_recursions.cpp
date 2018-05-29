#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class node {
public:
	int data;
	node * left;
	node * right;
	node() {
		data = 0;
		left = NULL;
		right = NULL;
	}
};

pair<int, bool> isbalancedrec(node * root) {
	if (root == NULL) {
		return pair<int, bool>(0, true);
	}
	pair<int, bool> left = isbalancedrec(root->left);
	pair<int, bool> right = isbalancedrec(root->right);
	int maxdepth = max(left.first, right.first)+1;
	bool ret;
	int dif = left.first - right.first;
	if ((dif>=-1&&dif<=1) && left.second == true && right.second == true) {
		ret = true;
	}
	else {
		ret = false;
	}
	return pair<int, bool>(maxdepth, ret);
}

bool isbalanced(node * root) {
	return isbalancedrec(root).second;
}

int main() {
	node root;
	root.left = new node;
	root.right = new node;
	root.left->left = new node;
	root.left->left->left = new node;
	root.right->right = new node;
	root.right->left = new node;
	//root.left->right = new node;
	cout << isbalanced(&root) << endl;
	while (1) {}
	return 0;
}

int returnsum(int n) {
	if (n == 10) {
		return 2;
	}
	int sam = returnsum(n + 1);
	sam = sam * 2;
	return sam;
}

int recursivecount(int n) {
	cout << "akk!" << endl;
	if (n == 10) {
		return 0;
	}
	int ret = recursivecount(n + 1);
	ret++;
	return ret;
}

int main1() {
	cout << recursivecount(0) << endl;
	while(1){}
	return 0;
}
