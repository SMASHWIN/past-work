#include "bst.h"
#include <iostream>
using namespace std;

int BST::add(Node* root){
	if (root == NULL) return 0;
	return root->data + add(root->left) + add(root->right);
}
int BST::sum(){
	return add(root);
}

int BST::min(){
	Node* temp = root;
	while (temp->left != NULL) temp = temp->left;
	return temp->data;
}

