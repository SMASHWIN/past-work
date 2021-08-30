#include "file.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

File::File(string filename, int i){
	name = filename;
	count = i; 
}

void File::setCount(){
	count++;
}

string File::getName() const{
	return name;
}

int File::getCount() const{
	return count;
}
