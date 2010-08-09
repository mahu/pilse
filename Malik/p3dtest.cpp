#include<iostream>
#include"point3d2.hpp"


int main()
{
	point3d A;
	point3d B(2.3,5,7.4);
	point3d C(B);


	A.print_point();
	B.print_point();
	C.print_point();
	
	A[2]=5;
	A.print_point();

	std::cout<<A.x();



return 0;
}
