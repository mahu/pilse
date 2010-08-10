#ifndef __RAY_HPP__
#define __RAY_HPP__

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


#endif /* __RAY_HPP__ */

