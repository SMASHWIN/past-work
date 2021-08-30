#include <iostream>
using namespace std;

class Node  
{  
    public: 
    	int data;  
    	Node* next;
	Node(int data = 0, Node* next = nullptr);  
};
// Question 3 part (1)


Node* merge(Node* h1, Node* h2){
	Node* temp = h1;
	Node*head = new Node(temp->data);
	Node*temp2 = head;
	Node* temp3 = head;
	temp = temp->next;
	while (temp != NULL){
		temp = temp->next;
		temp2->next = new Node(temp->data);
		temp2 = temp2->next;
	}
	temp = h2;
	Node* prev;
	while (temp != NULL){
		int data = temp->data;
		while(data > temp3->data && temp3 != NULL){
			prev = temp3;
			temp3 = temp3->next;
		}
		if (head->data == temp3->data){
			head = newNode(data, head);
		}
		else{
			prev->next = new Node(data, temp3);
		}
		temp3 = head;
		temp = temp->next;
	}
	return head;
}

//Question 3 part (2)
Node* merge(Node* h1, Node* h2)  
{  
    Node* result = NULL;  
      
    if (h1 == NULL)  
        return(h2);  
    else if (h2 == NULL)  
        return(h1);  
      
    if (h1->data <= h2->data)  
    {  
        result = h1;  
        result->next = merge(h1->next, h2);  
    }  
    else
    {  
        result = h2;  
        result->next = merge(h1, h2->next);  
    }  
    return(result);  
}

  
