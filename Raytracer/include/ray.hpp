#include "point.hpp"
#include "vector.hpp"

#include <iostream>
#include <cmath>

struct ray
{

	//Konstruktoren

			ray();
			ray(math3d::point a, math3d::vector b);


	//Membervariablen

	math3d::point	origin_;
	math3d::vector	direction_;
};
