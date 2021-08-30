#include "point3d.h"
#include <iostream>
using namespace std;

int main(){
	Point3d example(5, -10, 15);
	cout << "x" << example.getX() << "y" << example.getY() << "z" << example.getZ() << endl;
	Point3d p(-3, -12, 12);
	cout << "distance: " << distance(example, p) << " " << distance (p, example) << endl;
	example.setX(2);
	example.setY(2);
	example.setZ(2);
	p.shift(2, -10);
	p.shift(1, 14);
	p.shift(0,5);
	bool b = (p == example);
	cout << b << endl;
	cout << p.getX() << p.getY() << p.getZ() << endl;

}
