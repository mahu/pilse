#include"box.hpp"
#include"shape.hpp"
#include<iostream>
#include<list>

int main()

{
	box x(point3d(1,2,3),point3d(4,5,6),color(234,4,56),"Box 1");
	x.print_on(std::cout);

return 0;

}
