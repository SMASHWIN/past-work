#include "statistician.h"
#include <iostream>
using namespace std;

int main(){
	Statistician myStat;

	myStat.next_number(1.1);
	myStat.next_number(-2.4);
	myStat.next_number(0.8);
	myStat.print();
	
	Statistician s;
	s.next_number(5.0);
	s.next_number(10.0);
	s.next_number(-3.0);
	s.next_number(0.0);
	s.print();
	
	Statistician add = myStat + s;
	add.print();
	Statistician s2 = Statistician(s);
	Statistician s3 = s;
	s2.print();
	s3.print();
	s.print();
	myStat.erase();
	myStat.print();
	
	
		
	return 0;
	
}
