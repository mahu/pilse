#include<point.hpp>
#include<vector.hpp>

struct ray
{

	//Konstruktoren

	ray();
	ray(point a, vector b);


	//Membervariablen

	point	origin_;
	vector	direction_;
};
