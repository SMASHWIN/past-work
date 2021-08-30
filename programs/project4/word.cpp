#include "word.h"
#include<iostream>
#include<cstring>
#include<string>

// YOU CAN INCLUDE OTHER HEADER FILES HERE IF NEEDED
// DO NOT ADD THE FOLLOWING HEADERS:
// 1. <vector>, 2. <queue>, 3. <deque>, 4. <stack>,
// 5. <map>, 6. <algorithm>, 7. <set>, 8. <utility>
// In summary do not use any built-in data structures
// other than arrays. Also, do not use any built-in
// algorithms related to sorting and searching

// you are allowed to use the header files: <cstring>, <string>
// you can use the string manipulation functions
// provided by those header files if needed

using namespace std;

// implementation of word constructor; you may modify this if required
Word::Word(std::string name){
  word = name;
  count = 0;
  files = NULL;
  size = 0;
}
Word::~Word(){
	dnode<File>* curr = files;
	dnode<File>* next;
	while(curr != NULL){
		next = curr->next;
		curr = NULL;
		delete curr;
		curr = next;
	}
}

string Word::getWord() const{
        return word;
}

int Word::getCount() const{
        return count;
}

void Word::setCount(){
        count++;
}

int Word::getSize(){
	return size;
}


void Word::addFile(string filename){
	dnode<File>*temp = files;
	File f = File(filename, 1);
	if (temp == NULL){
		files = new dnode<File>(f,NULL,NULL);
	} 
	else{
		while(temp->next != NULL){
			if (temp->getData().getName().compare(filename) < 0) temp = temp->next;
			else{
				temp = temp->prev;
				break;
			}
		}

		dnode<File>* insert = new dnode<File>(f);
		insert->insertNode(temp, temp->next);
		temp->next = insert;
		
		if(insert->next != NULL){
			dnode<File>*temp2 = insert->next; 
			temp2->prev = insert;
		}
	}
	temp = files;
	int i = 0;
	while(temp != NULL && i < 10){
		temp = temp->next;
		i++;
	}
	size++;
	count++;

}

dnode<File>* Word::getFile(int index){
	dnode<File>* temp = files;
	for(int i = 0; i < index; i++){
		temp = temp->next;
	}
	if (temp == NULL) cout << "NULL" << endl;
	
	return temp;
}
