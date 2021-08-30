#ifndef _BAG_H
#define _BAG_H

#include <string>
#include "word.h"
using namespace std;

#define LIMIT 1000


class Bag{
  // Below is an array of Word objects.
  // You must store new objects or modify existing objects in this array.
  
private:
  dnode<Word>* container;
  int size;


  // ADD NEW MEMBER VARIABLES HERE IF NEEDED

public:
  Bag(){
                        size = 0;
			container = NULL;
  }
  ~Bag();
  // the below function is used to print the contents of
  // container array (declared at line 40)  in the format <WORD::COUNT>
  void print_words() const;
  bool contains(const string& key);
  void insertLast(dnode<Word>* word);
  void add(const string& key, string s);
  Word findWord(const string& input);
  dnode<Word>* findWord(int index);
  dnode<Word>* findWordString(const string& input);
  int getSize();

  // ADD NEW MEMBER FUNCTIONS HERE AS NEEDED


};

#endif
