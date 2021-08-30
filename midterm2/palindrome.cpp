#include <iostream>
#include <stack>
using namespace std;

struct Node{
	Node(char c){
		data = c;
		next = NULL;
	}
	char data;
	Node* next;
};

bool isPalindrome(Node* head){
	Node* temp = head;
	stack<char> Stack;
	int length;
	while(temp != NULL){
		if ((temp->data >= 'a' && temp->data <= 'z') || (temp->data >= 'A' && temp->data <= 'Z')){
			length++;
			
		}
		temp = temp->next;
	}
	temp = head;
	if (length % 2 == 0){
		for (int i = 0; i < length/2;){
			if ((temp->data >= 'a' && temp->data <= 'z') || (temp->data >= 'A' && temp->data <= 'Z')){
				Stack.push(temp->data);
				i++;
			}
			temp = temp->next;
		}
		for (int j = length/2; j < length;){
			if ((temp->data >= 'a' && temp->data <= 'z') || (temp->data >= 'A' && temp->data <= 'Z')){
				char c = Stack.top();
				Stack.pop();
				if(temp->data != c) return false;
				j++;
			}
			temp = temp->next;
		}	
	}
	else{
		for (int i = 0; i < length/2;){
			if ((temp->data >= 'a' && temp->data <= 'z') || (temp->data >= 'A' && temp->data <= 'Z')){
				Stack.push(temp->data);
				i++;
			}
			temp = temp->next;
		}
		int j = length/2 + 1;
		while (!((temp->data >= 'a' && temp->data <= 'z') || (temp->data >= 'A' && temp->data <= 'Z'))){
			temp = temp->next;
		}
		temp = temp->next;
		while(j < length){
			if ((temp->data >= 'a' && temp->data <= 'z') || (temp->data >= 'A' && temp->data <= 'Z')){
				char c = Stack.top();
				Stack.pop();
				if (temp->data != c) return false;
				j++;
			}
			temp = temp->next;
		}


	}
	return true;
}

#you iterate through the linked list exactly twice, so the complexity is 2n, or O(n)







int main(){
	Node*head = new Node('t');
	Node* temp = head;
	temp->next = new Node('a');
	temp = temp->next;
	temp->next = new Node('c');
	temp = temp->next;
	temp->next = new Node(' ');
	temp = temp->next;
	temp->next = new Node(' ');
	temp = temp->next;
	temp->next = new Node('c');
	temp = temp->next;
	temp->next = new Node('a');
	temp = temp->next;
	temp->next = new Node('t');
	temp = temp->next;
	temp->next = new Node('s');
	cout << isPalindrome(head) << endl;
	return 0;
}
