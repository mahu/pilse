#include"shape.hpp"
#include"sphere.hpp"
#include"box.hpp"
#include<iostream>

int main()
{
	std::cout<<"Double: "<<sizeof(double)<<std::endl;
	std::cout<<"Shape: "<<sizeof(shape)<<std::endl;
	std::cout<<"Box: "<<sizeof(box)<<std::endl;
	std::cout<<"Sphere: "<<sizeof(sphere)<<std::endl;

return 0;
}
