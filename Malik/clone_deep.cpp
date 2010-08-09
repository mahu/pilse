#include<iostream>
#include"shape_container.hpp"
#include"box.hpp"
#include"sphere.hpp"


int main()
{

shape *s1= new sphere(point3d(0,3,1),4,color(23,46,123),"Mama");
shape *s2=new sphere(point3d(0,3,3),12,color(23,46,123),"Papa");

shape_container a,b;

a.add_shape(s1);
a.add_shape(s2);
b=a.clone_deep();
s1->set_color(color(0,0,0));
std::cout<<"Erster Container neu\n";
a.print();
std::cout<<"Zweiter Container neu\n";
b.print();


return 0;
}
