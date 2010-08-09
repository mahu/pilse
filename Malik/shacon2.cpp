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

sphere s1(point3d(0,3,1),4,color(23,46,123),"Fuck");
sphere s2(point3d(0,3,3),12,color(23,46,123),"Fuck");
shape *p1,*p2;

p1=&s1;
p2=&s2;

shape_container a,b,c;

a.add_shape(p1);
a.add_shape(p2);

std::cout<<s1.get_refcount()<<std::endl;
b=a;
std::cout<<s1.get_refcount()<<std::endl;
c=a;
std::cout<<s1.get_refcount()<<std::endl;
c.remove_shape("Fuck");
std::cout<<s1.get_refcount()<<std::endl;
a.remove_shape(color(23,46,123));
std::cout<<s1.get_refcount()<<std::endl;
b.remove_shape(p1);
std::cout<<s1.get_refcount()<<std::endl;
return 0;
}
