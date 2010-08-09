#include"shape.hpp"
#include"sphere.hpp"
#include"point3d.hpp"
#include"color.hpp"
#include<string>
#include<iostream>
#include<cmath>

sphere::sphere(void):
	shape(), 	
	m_(point3d()),
	r_(1)
{
	//std::cout<<"Konstruktor Spehre!"<<std::endl;
}


sphere::sphere(point3d M, double R,color c,std::string s):
	shape(c,s),
	m_(M),
	r_(R)

{
	//std::cout<<"Konstruktor Spehre!"<<std::endl;
}


sphere::sphere(sphere const& a):
	m_(a.m_),
	r_(a.r_),
	shape(a)
{
	//std::cout<<"Konstruktor Spehre!"<<std::endl;
}


sphere::~sphere()
{
	//std::cout<<"Destruktor Sphere!"<<std::endl;
}


double sphere::volume() const
{
	return ((4/3)*M_PI*pow(r_,2));
}


double sphere::surface() const
{
	return (4*M_PI*pow(r_,2));
}


bool sphere::is_inside(point3d const& a) const
{
	double ab1= sqrt(pow((m_.x()-a.x()),2)+pow((m_.y()-a.y()),2)+pow((m_.z()-a.z()),2));
	return (ab1<r_);
}


void sphere::print_on(std::ostream& str) const
{
	shape::print_on(str);
	str<<"Mittelpunkt: ["<<(m_.x())<<","<<m_.y()<<","<<m_.z()<<"]\nRadius: "<<r_<<"\nVolumen: "<<volume()<<"\nOberfläche: "<<surface()<<"\n"<<std::endl;

}

shape* sphere::clone()
  {
	shape* s=new sphere(m_,r_,shape::get_color(),shape::get_name());
	return s;
  }


std::ostream& operator<<(std::ostream& stream, sphere obj)
{
	obj.print_on(stream);
	return stream;
}
	



