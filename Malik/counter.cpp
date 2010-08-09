#include <sstream>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include"shape_container.hpp"
#include"box.hpp"
#include"sphere.hpp"
#include"shape.hpp"


int main()
{

sphere *s1= new sphere(point3d(0,3,1),4,color(23,46,123),"Mama");
sphere *s2=new sphere(point3d(0,3,3),12,color(23,46,123),"Mama");
shape *p1,*p2;

std::cout<<s1->get_refcount()<<std::endl;//0

p1=s1;
p2=s2;

shape_container a,b,c;

a.add_shape(p1);
a.add_shape(p2);

std::cout<<s1->get_refcount()<<std::endl;//1
b=a;
std::cout<<s1->get_refcount()<<std::endl;//2
c=b;
std::cout<<s1->get_refcount()<<std::endl;//3
c=a;
std::cout<<s1->get_refcount()<<std::endl;//3
c.remove_shape("Mama");
std::cout<<s1->get_refcount()<<std::endl;//2
a.remove_shape(color(23,46,123));
std::cout<<s1->get_refcount()<<std::endl;//1
b.remove_shape(p1);
std::cout<<s1->get_refcount()<<std::endl;//0
//s1->print_on(std::cout);
return 0;
}
