#include <iostream>
using namespace std;

struct Node{
	int val;
	Node* next;
	Node(): val(0), next(nullptr) {}
	Node(int x): val(x), next(nullptr) {}
	Node(int x, Node* next): val(x), next(next) {}
};
/*
When using this function, set the original node equal to the result of this function,
resulting in the original node (in another scope) having the correct node removed
*/
Node* removeNthFromLast(Node* head, int n, int length){
	Node* temp = head;
	if (n == length){
		head = head->next;
		return head;
	}
	for (int i = 1; i < length - n; i++){
		temp = temp->next;
	}
	temp->next = temp->next->next;
	temp = head;
	return temp;
	
}
int length(Node* n){
	Node* temp = n;
	int result = 0;
	while(temp != NULL){
		result++;
		temp = temp->next;
	}
	return result;
}

int main(){

	Node* n = new Node(1, new Node(2, new Node(3, new Node(4,new Node(5)))));
	n = removeNthFromLast(n, 5, length(n));
	n = removeNthFromLast(n,1,length(n));
}
