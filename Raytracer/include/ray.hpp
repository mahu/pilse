
#include "vector.hpp"

#include <iostream>
#include <cmath>

struct ray
{

	//Konstruktoren

			ray();
			ray(math3d::vector a, math3d::vector b);


	//Membervariablen

	math3d::vector	origin_;
	math3d::vector	direction_;
};
