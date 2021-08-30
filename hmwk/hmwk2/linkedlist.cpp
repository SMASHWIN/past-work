#include "linkedlist.h"
#include <iostream>
using namespace std;

DoubleLinkedList::DoubleLinkedList(){
	head = NULL;
	tail = NULL;
	
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& rhs){
	node* src = rhs.head;
	if (src = NULL){
		head = NULL;
		tail = NULL;
	}
	else{
		head = new node(src->data, src->next, src->prev);
		tail = head;
		src = src->next;
		while (src != NULL){
			insert(src->data);
			tail = tail->next;
			src = src->next;
		}
	}
}

DoubleLinkedList::~DoubleLinkedList(){
	node* curr = head;
	node* free;
	while(curr != NULL){
		free = curr;
		curr = curr->next;
		free->next = NULL;
		free->prev = NULL;
		delete free;
	}
}

bool DoubleLinkedList::insert(int x){
	node* temp = head;
	while (temp != NULL){
		if (temp->data == x){
			return false;
		}	
		temp = temp->next;
	}
	if (head == NULL){
		head = new node(x,NULL,NULL);
		tail = head;
		return true;
	}
	node* newNode = new node(x,head, NULL);
	head = newNode;
	head->next->prev = newNode;
	return true;
}	

void DoubleLinkedList::remove(int x){
	node* temp = head;
	if (temp->data == x){
		head = head->next;
		head->prev = head;
		delete temp->prev;
		delete temp->next;
	}
	temp = temp->next;
	while (temp != NULL){
		if (temp->data == x){
			node* pre = temp->prev;
			if (temp->next == NULL) tail = pre;
			pre->next = temp->next;
			temp->next->prev = pre;
			delete temp->prev;
			delete temp->next;
		}
		temp = temp->next;
	}
	return;
}

const DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList& rhs){
	if (this == &rhs) return *this;
	node* src = head;
	node* forward = src;
	while (src != NULL){
		forward = src->next;
		delete src;
		src = foward;
	}
	if (rhs.head == NULL){
		head = NULL;
		tail = NULL;
	}
	else{
		src = rhs.head;
		while (src != NULL){
			this->insert(src->data);
			src = src->next;
		}
		
	}
	
	return *this;
	
}
