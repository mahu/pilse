#include"shape.hpp"
#include"box.hpp"
#include"point3d.hpp"
#include<string>
#include"color.hpp"
#include<iostream>
#include<cmath>

box::box(void):
shape(color(),"Box"),
a_(),
h_(1,1,1)

{
	b_=point3d(h_.x(),a_.y(),a_.z());
	//c_=point3d(h_.x(),a_.y(),h_.z());
	d_=point3d(a_.x(),a_.y(),h_.z());
	e_=point3d(a_.x(),h_.y(),a_.z());
	//f_=point3d(h_.x(),h_.y(),a_.z());
	//g_=point3d(a_.x(),h_.y(),h_.z());
	
	//std::cout<<"Konstruktor Box"<<std::endl;
}

box::box(point3d a, point3d h, color c,std::string s):
  shape(c,s),
  a_(a),
  h_(h)

{
	b_=point3d(h_.x(),a_.y(),a_.z());
	//c_=point3d(h_.x(),a_.y(),h_.z());
	d_=point3d(a_.x(),a_.y(),h_.z());
	e_=point3d(a_.x(),h_.y(),a_.z());
	//f_=point3d(h_.x(),h_.y(),a_.z());
	//g_=point3d(a_.x(),h_.y(),h_.z());
	//std::cout<<"Konstruktor Box"<<std::endl;
}

box::box(box const& k):
shape(k),
a_(k.a_),
b_(k.b_),
//c_(k.c_),
d_(k.d_),
e_(k.e_),
//f_(k.f_),
//g_(k.g_),
h_(k.h_)

{
	//std::cout<<"Konstruktor Box"<<std::endl;
}

box::~box()
{
	//std::cout<<"Destruktor Box"<<std::endl;
}

double box::volume() const
{
	return (laenge(a_,b_)*laenge(a_,e_)*laenge(a_,d_));
}

double box::surface() const
{
	return (2*((laenge(a_,b_)*laenge(a_,e_))+(laenge(a_,b_)*laenge(a_,d_))+(laenge(a_,e_)*laenge(a_,d_))));
}

double box::laenge(point3d const& a,point3d const& b) const
{
	double x_neu=b.x()-a.x();
	double y_neu=b.y()-a.y();
	double z_neu=b.z()-a.z();

return(sqrt(pow(x_neu,2)+pow(y_neu,2)+pow(z_neu,2)));
}

bool box::is_inside(point3d const& o) const
{

	if(a_.x()>o.x()||a_.x()+laenge(a_,b_)<o.x())return false;
	if(a_.y()>o.y()||a_.y()+laenge(a_,d_)<o.y())return false;
	if(a_.z()>o.z()||a_.z()+laenge(a_,e_)<o.z())return false;
	
return true;
}

void box::print_on(std::ostream& str) const
{
	shape::print_on(str);
	str<<"Punkt A: ["<<(a_.x())<<","<<a_.y()<<","<<a_.z()<<"]\nPunkt H:["<<(h_.x())<<","<<h_.y()<<","<<h_.z()<<"]\nVolumen: "<<volume()<<"\nOberfläche: "<<surface()<<"\n"<<std::endl;

}

std::ostream& operator<<(std::ostream& stream, box::box obj)
{
	obj.print_on(stream);
return stream;
}

shape* box::clone()
  {
	shape* s=new box(a_,h_,shape::get_color(),shape::get_name());
	return s;
  }


