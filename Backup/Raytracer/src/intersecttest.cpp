#include"sphere.hpp"
#include"ray.hpp"
#include"point.hpp"
#include"iostream"

int main()
{

math3d::vector a(-5,0,0,0);
math3d::vector c(-4,0,0,0);
math3d::point b(0,0,0,1);

sphere s(b,1,"kugel",rgb(1,2,3));
ray x(a,c);

s.printOn(std::cout);
std::cout<<s.intersection(x)<<std::endl;


return 0;
}
