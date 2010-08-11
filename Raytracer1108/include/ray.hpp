#ifndef __RAY_HPP__
#define __RAY_HPP__

#include "vector.hpp"
#include "rgb.hpp"
#include "light.hpp"
#include "shape.hpp"


#include <iostream>
#include <cmath>
#include <list>

class ray
{
    public:
	//Konstruktoren, Funktionen
			ray();
			ray(math3d::vector a, math3d::vector b);

//	double		trace (std::list<shape*>, std::list<light> const&);


	//Membervariablen
	math3d::vector	origin_;
	math3d::vector	direction_;
};


#endif /* __RAY_HPP__ */

