#include "rational.h"
#include <assert.h>
#include <stdlib.h>

rational::rational(int n, int d){
	num = n;
	assert(d != 0);
	denom = d;
}

rational rational::operator+(const rational& other){
	return rational(num*other.denom + denom*other.num, denom*other.denom);
}

rational rational::operator*(const rational& other){
	return rational(num*other.num, denom*other.denom);
}

rational rational::operator/(const rational& other){
	assert(other.num != 0);
	return rational(num * other.denom, other.num * denom);
}

bool rational::operator==(const rational& other){
	if (num * other.denom == other.num*denom) return true;
	return false;
}

bool rational::operator<(const rational& other){
	bool neg = false;
	bool other_neg = false;
	if ((num < 0 && denom > 0) || (num > 0 && denom < 0)){
		neg = true;
	}
	if ((other.num < 0 && other.denom > 0) || (other.num > 0 && other.denom < 0)){
		other_neg = true;
	}
	if (neg){
		if (!other.neg) return true;
		return ((abs(num) * abs(other.denom)) > (abs(denom) * abs(other.num)));
	}
	else {
		if (other.neg) return false;
		return ((num * other.denom) < (denom * other.num));

	}
}	
