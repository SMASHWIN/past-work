#ifndef _FILE_H
#define _FILE_H
#include <string>
#include <cstring>
#include "dnode.h"
using namespace std;

class File{
private:
	string name;
	int count;

public:
	File() {name = ""; count = 0;}
	File(std::string filename, int i);
	void setCount();
	string getName() const;
	int getCount() const;


};

#endif
