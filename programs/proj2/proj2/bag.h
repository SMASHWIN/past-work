#ifndef _BAG_H
#define _BAG_H

#include <string>
using namespace std;

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



#define LIMIT 10000 

// This is the class that will store
// a word and its count
class Word{
  std::string word;
  int count;
  // DO NOT REMOVE THE ABOVE MEMBER VARIABLES

  // ADD NEW MEMBER VARIABLES HERE IF NEEDED
public:
  Word() {word = ""; count = -1;}  // default constructor to keep compiler happy; DO NOT DELETE
  Word(std::string name); // constructor
	string getWord() const;
	int getCount() const;
	void setCount();
  
  // ADD NEW MEMBER FUNCTIONS HERE AS NEEDED

};

class Bag{
  // Below is an array of Word objects.
  // You must store new objects or modify existing objects in this array.
  Word container[LIMIT];
  int size;


  // ADD NEW MEMBER VARIABLES HERE IF NEEDED
  
public:
  Bag(){
			size = 0; 
  }
  // the below function is used to print the contents of
  // container array (declared at line 40)  in the format <WORD::COUNT>
  void print_words() const;
	bool contains(const string& key);
	void add(const std::string& name);

  // ADD NEW MEMBER FUNCTIONS HERE AS NEEDED


};




#endif
