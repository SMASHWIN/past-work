#ifndef POINT3D_H
#define POINT3D_H

class Point3d{
	public:
	Point3d(double x, double y, double z);
	Point3d(const Point3d& p);	

	void setX(double x);
	void setY(double y);
	void setZ(double z);

	
	double getX() const;
	double getY() const;
	double getZ() const;

	
	private:
	double x;
	double y;
	double z;
};

#endif
