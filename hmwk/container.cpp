#include "container.h"
#include <iostream>
using namespace std;

container::container(){
	head = NULL;
	tail = NULL;
}

container::~container(){
	node*curr = head;
	while (curr != NULL){
		head = curr->next;
		delete curr;
		curr = head;
	}
}

container::container(const container& c){
	node* src = c.head;
	if(src = nullptr){
		head = nullptr;
		tail = nullptr;
	}
	else{
		head = new node(src->key, src->next);
		tail = head;
		src = src->next;
		while (src != NULL){
			add(src->key);
			tail = tail->next;
			src = src->next;
		}
	}	
}

container& container::operator= (const container& c){
	if (this == &c) return *this;
	node* src = head;
	node* forward = src;
	while(src != NULL){
		forward = src->next;
		delete src;
		src = forward;
	}
	if (c.head == NULL){
		head = NULL;
		tail = NULL;
	}
	else{

		src = c.head;
		while(src != NULL){
			this->add(src->key);
			src = src->next;
		}
	}
	return *this;
}
