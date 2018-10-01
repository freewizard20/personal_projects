#include <iostream>
#include <vector>

using namespace std; 


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	void inorder(vector<int>* same, TreeNode* root) {
		if (root == NULL) {
			same->push_back(-999998);
			return;
		}
		inorder(same, root->left);
		same->push_back(root->val);
		inorder(same, root->right);
	}
	bool isSameTree(TreeNode* p, TreeNode* q) {
		vector<int> same1;
		vector<int> same2;
		inorder(&same1, p);
		inorder(&same2, q);

		if (same1 == same2) return true;
		else return false;
	}
};

int main() {
	Solution sl;
	TreeNode root(1);
	TreeNode root2(1);
	TreeNode ch(1);
	TreeNode ch2(1);
	root.right = &ch;
	root.left = &ch2;
	cout << sl.isSameTree(&root, &root2);
	while(1){}
}
