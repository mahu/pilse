#include"box.hpp"
#include"sphere.hpp"
#include"shape.hpp"
#include<iostream>

int main()
{

	color red(255,0,0);
	point3d p(0,0,0);
	sphere *s1 = new sphere(p,1.2,red," sphere0 " );
	shape *s2 = new sphere(p,1.2,red," sphere1 " );
	//s1->print_on(std::cout);
	//s2-> print_on(std::cout);
	
	delete s1 ;
	delete s2 ;



return 0;
}
