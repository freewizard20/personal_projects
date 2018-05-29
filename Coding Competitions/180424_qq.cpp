#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

vector<int> findqq(vector<int> & data) {
	struct node {
		node * right;
		node * left;
		int value;
		int rank;
		node(int v) : value(v), rank(1), right(NULL), left(NULL) {}
	};
	// initiate first few
	vector<int> ret(data.size(), 0);
	node root(data.back());
	// go through array and calculate
	for (int i = data.size() - 2; i >= 0; i--) {
		int count = 0;
		node * runner = &root;
		while (runner != NULL) {
			if (data[i] <= runner->value) {
				// go left
				count += runner->rank - (runner->left == NULL ? 0 : runner->left->rank);
				runner->rank++;
				if (runner->left == NULL) {
					runner->left = new node(data[i]);
					break;
				}
				runner = runner->left;
			}
			else {
				// go right
				runner->rank++;
				if (runner->right == NULL) {
					runner->right = new node(data[i]);
					break;
				}
				runner = runner->right;
			}
		}
		ret[i] = count;
	}
	return ret;
}

int main() {
	while(1){}
	return 0;
}
