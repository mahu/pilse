#include<iostream>
#include"point3d2.hpp"

point3d::point3d(void):x_(0),y_(0),z_(0){}

point3d::point3d(double x, double y, double z):
x_(x),
y_(y),
z_(z)
{}

point3d::point3d(point3d const& p):
x_(p.x_),
y_(p.y_),
z_(p.z_)
{}

point3d::~point3d()
{}

double point3d::x() const 
{
	return x_;
}

double point3d::y() const
{
	return y_;
}

double point3d::z() const
{
	return z_;
}


void point3d:: print_point(void)const
{
	std::cout<<"["<<x_<<","<<y_<<","<<z_<<"]"<<std::endl;
}

double& point3d::operator[](int s)
{
	switch(s)
	{
		case 0: return x_;
		case 1: return y_;
		case 2: return z_;
		default : std::cout<<"Kein Wert mit Index "<< s <<" in Point3d gefunden!"<<std::endl;
	}
}
