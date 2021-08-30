#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
using namespace std;
class rational
{
public:
	rational(int n = 0, int d = 1);
	rational operator+(const rational& other);
	rational operator*(const rational& other);
	rational operator/(const rational& other);

	bool operator==(const rational& other);
	bool operator<(const rational& other);
		

private:
	int num;
	int denom;

};
#endif
