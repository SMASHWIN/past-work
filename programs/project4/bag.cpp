#include "bag.h"
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

Bag::~Bag(){
	dnode<Word>* curr = container;
	dnode<Word>* next;
	while(curr != NULL){
		next = curr->next;
		curr = NULL;
		delete curr;
		curr = next;
	}
}
// Implement the print_words function
void Bag::print_words() const {
	dnode<Word>* temp = container;
        while(temp != NULL){
		cout << temp->getData().getWord() << endl;
        	temp = temp->getNext();
	}
}

bool Bag::contains(const string& key){
	dnode<Word>* temp = container;
        while(temp != NULL){
                if(key.compare(temp->getData().getWord() ) == 0) return true;
        	temp = temp->getNext();
	}

        return false;
}
void Bag::insertLast(dnode<Word>* word){
	dnode<Word>* temp = container;
	while(temp->next != NULL) temp = temp->next;
	temp->next = word;
	word->prev = temp;
}
void Bag::add(const string& key, string s){
        if (!contains(key)){
		
		Word newWord = Word(key);
		newWord.addFile(s);
		if (container == NULL){
                	container = new dnode<Word>(newWord);
		}
		else{
			
			dnode<Word>* insert = new dnode<Word>(newWord);
			insertLast(insert);
		}
		
		size++;
		
        }
        else{
		dnode<Word>* temp = container;
		while(temp != NULL){

			temp = temp->next;
		}
		temp = container;
                for (int i = 0; i < size; i++){
                        if(key.compare(temp->getData().getWord()) ==0){
				int flag = 0;
				for (int j = 0; j < temp->getData().getSize(); j++){
					if (s.compare(temp->getData().getFile(j)->getData().getName()) == 0){
						temp->getData().getFile(j)->getData().setCount();
						temp->getData().setCount();
						flag++;
						break;
					}
				}
				if (!flag){
					temp->getData().addFile(s);
				}
				break;
			}
			temp = temp->next;
                }
        }
        return;
}

Word Bag::findWord(const string& input){
	dnode<Word>* temp = container;
	while(temp != NULL){
		if (input.compare(temp->getData().getWord()) == 0) return temp->getData();
		temp = temp->getNext();
	}
	Word w = Word();
	return w;
}

dnode<Word>* Bag::findWord(int index){
	dnode<Word>* temp = container; 
	for (int i = index; index > 0; index--) temp = temp->getNext();
	return temp;
}

dnode<Word>* Bag::findWordString(const string& input){
	dnode<Word>* temp = container;
	while(temp != NULL){
		if (temp->getData().getWord() == input) return temp;
		temp = temp->next;
	}
	return NULL;
}

int Bag::getSize(){
	return size;
}
