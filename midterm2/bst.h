#include <iostream>
using namespace std;

struct Node {
	Node* parent;
	Node* left;
	Node* right;
	int data;
};
class BST{
	private:
		Node* root;
	public:
		int sum();
		int min();
		int add(Node* root);
}
