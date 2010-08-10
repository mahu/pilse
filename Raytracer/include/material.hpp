#ifndef __MATERIAL_HPP__
#define __MATERIAL_HPP__

#include "vector.hpp"
#include "point.hpp"
#include "rgb.hpp"

#include <iostream>
#include <cmath>
#include <string>

struct material
{

	//Konstruktoren

			material();
			material(std::string, rgb, rgb, rgb, double);


	//Membervariablen

	std::string	name_;
	rgb		reflexionAmbient_;
	rgb		reflexionDiffuse_;
	rgb		reflexionSpecular_;
	double		expReflexionSpecular_;
};


#endif /* __material_HPP__ */
