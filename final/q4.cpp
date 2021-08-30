#include <iostream>
using namespace std;

// Part (A)

double myPow(double x, int n){
	if (n == 1) return x;
	if (n % 2 == 0) return myPow(x, n/2) * myPow(x, n/2);	
	return myPow(x,n/2) * myPow(x,n/2)*x;
}

// Part(B)

struct Node{

	int data;
	Node* next;
	Node* prev;
};

Node* Reverse(Node* node){
	if (node == NULL){
		return NULL;
	}
	Node* temp = node->next;
	node->next = node->prev;
	node->prev = temp;
	if (node->prev == NULL) return node;

	return Reverse(node->prev);
	
}

int main(){

	int x = 5;
	int n = 8;
	cout << "5 to the 8th power " << myPow(5,8) << endl;
}
