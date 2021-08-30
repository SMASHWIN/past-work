#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}

};

//Problem 3

int maxDepth(TreeNode* root){
	if (root->left == NULL && root->right == NULL) return 1;
	if (root->left == NULL){
		return 1 + maxDepth(root->right);
	}
	if (root->right == NULL){
		return 1 + maxDepth(root->left);
	}
	return 1 + max(maxDepth(root->right), maxDepth(root->left));
}

int countNodes(TreeNode* root){
	if (root == NULL) return 0;
	return 1 + countNodes(root->left) + countNodes(root->right);
}

//Problem 4

bool isSameTree(TreeNode* p, TreeNode* q){
	if (p == NULL && q == NULL) return true;
	if (p == NULL || q == NULL) return false;
	if (p->val == q->val) return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	return false;
}

//Problem 5


TreeNode* invertTree(TreeNode* root){
	TreeNode* result;
	if (root->left == NULL && root->right == NULL) return root;
	if (root->left == NULL) result = new TreeNode(root->val, invertTree(root->right), nullptr);
	else if (root->right == NULL) result = new TreeNode(root->val, nullptr, invertTree(root->left));
 
	else result = new TreeNode(root->val, invertTree(root->right), invertTree(root->left));
	return result;
}

int main(){

	TreeNode* test = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
	cout << "max depth: " << maxDepth(test) << endl;
	cout << " num nodes: " << countNodes(test) << endl;
	TreeNode* test2 = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
	bool flag = isSameTree(test, test2);
	cout << flag << endl;
	test = invertTree(test);
	TreeNode* test3 = new TreeNode(3, new TreeNode(20, new TreeNode(7), new TreeNode(15)), new TreeNode(9));
	cout << isSameTree(test, test3) << endl;
	test = invertTree(test);
	cout << isSameTree(test, test2) << endl;
	return 0;
}
