#include "statistician.h"
#include <cassert>
#include <cfloat>
#include <iostream>
using namespace std;

Statistician::Statistician(){
	length = 0;
	sum = 0;
	min_value = DBL_MAX;
	max_value = -DBL_MAX;
}

void Statistician::next_number(double n){
	lastNum = n;
	length++;
	sum += n;
	if (n < min_value) min_value = n;
	if (n > max_value) max_value = n; 
}

void Statistician::erase(){
	length = 0;
	sum = 0;
	min_value = DBL_MAX;
	max_value = -DBL_MAX;
}

//this is equivalent to a destructor

Statistician::Statistician(Statistician const& s){
	length = s.length;
	lastNum = s.lastNum;
	sum = s.sum;
	min_value = s.min_value;
	max_value = s.max_value;
}

Statistician& Statistician::operator= (Statistician const& s) {
	length = s.get_length();
	lastNum = s.get_lastNum();
	sum = s.get_sum();
	min_value = s.get_min();
	max_value = s.get_max();
	
}

Statistician Statistician::operator+ (Statistician& s){
	Statistician res;
	res.set_length(length + s.get_length());
	res.set_lastNum(s.get_lastNum());
	res.set_sum(get_sum() + s.get_sum());
	res.set_min(min(get_min(), s.get_min()));
	res.set_max(max(get_max(), s.get_max()));
	return res;
}

int Statistician::get_length() const{
	return length;
}

double Statistician::get_lastNum() const{ 
	assert(length > 0);
	return lastNum;
}

double Statistician::get_sum() const{
	return sum;
}

double Statistician::get_min() const{
	assert(length > 0);
	return min_value;
}

double Statistician::get_max() const{
	assert(length > 0);
	return max_value;
}

void Statistician::set_length(double length){
	this->length = length;
}

void Statistician::set_lastNum(double lastNum){
	this->lastNum = lastNum;
}

void Statistician::set_sum (double sum){
	this->sum = sum;
}

void Statistician::set_min(double min){
	this->min_value = min;
}

void Statistician::set_max(double max){
	this->max_value = max;
}

double Statistician::mean() const{
	assert(length > 0);
	return sum/length;
}

void Statistician::print() const{
	cout << "last element: " << get_lastNum() << endl;
	cout << "sum: " << get_sum() << endl;
	cout << "length: " << get_length() << endl;
	cout << "min: " << get_min() << " max: " << get_max() << endl;
	cout << "mean: " << mean() << endl;
}
