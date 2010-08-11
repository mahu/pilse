#ifndef __LIGHT_HPP__
#define __LIGHT_HPP__

#include "vector.hpp"
#include "point.hpp"
#include "rgb.hpp"

#include <iostream>
#include <string>
#include <cmath>

struct light
{
			light();
			light(math3d::point, std::string, rgb, rgb);


	// Membervariablen

	math3d::point	location_;
	std::string	name_;
	rgb		lightAmbient_;
	rgb		lightDiffuse_;	
};


#endif /* __light_HPP__ */

