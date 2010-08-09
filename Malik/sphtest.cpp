#include"sphere.hpp"
#include"iostream"
#include"point3d.hpp"

int main()
{
	sphere x(point3d(1,2,3),6,color(234,4,56),"Sphere 1");
	x.print_on(std::cout);

return 0;

}
