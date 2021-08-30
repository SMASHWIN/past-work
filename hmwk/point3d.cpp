#include "point3d.h"
#include <cmath>
#include <iostream>
using namespace std;

Point3d::Point3d(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
}

Point3d::Point3d(const Point3d& p){
	
}
void Point3d::setX(double x){
	this->x = x;
}

void Point3d::setY(double y){
	this->y = y;
}

void Point3d::setZ(double z){
	this->z = z;
}


double Point3d::getX() const{
	return x;
}

double Point3d::getY() const{
	return y;
}

double Point3d::getZ() const {
	return z;
}





