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

// implementation of word constructor; you may modify this if required
Word::Word(std::string name){
  word = name;
  count = 1;
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


// Implement the print_words function
void Bag::print_words() const {
	for (int i = 0; i < size; i++){
		cout << container[i].getWord() << "::" << container[i].getCount() << endl;
	}
}

bool Bag::contains(const string& key){
	for (int i = 0; i < size; i++){
		if(key.compare(container[i].getWord() ) == 0) return true;
	}
	return false;
}

void Bag::add(const string& key){
	if (!contains(key)){
		container[size] = Word(key);
		size++;
	}
	else{
		for (int i = 0; i < size; i++){
			if(key.compare(container[i].getWord()) ==0) container[i].setCount();
		}
	}
	return;
}

// Implement any other memeber functions you may have
// added to the class definitions
