#ifndef _WORD_H
#define _WORD_H
#include "file.h"
#include <string>
#include <cstring>
using namespace std;

class Word{
  string word;
  int count;
  dnode<File>* files;
  int size;
  // DO NOT REMOVE THE ABOVE MEMBER VARIABLES

  // ADD NEW MEMBER VARIABLES HERE IF NEEDED
public:
  Word()  {word = ""; files = NULL; count = -1;}  // default constructor to keep compiler happy; DO NOT DELETE
  Word(std::string name); // constructor
  ~Word();
  string getWord() const;
  int getCount() const;
  void setCount();
  int getSize();
  void addFile(string filename);
  dnode<File>* getFile(int index);
  
  // ADD NEW MEMBER FUNCTIONS HERE AS NEEDED

};
#endif
