#include "material.hpp"

material::material()	{}

material::material(std::string n, rgb ra, rgb rd, rgb rs, double ers) : 
		name_(n) , 
		reflexionAmbient_(ra), 
		reflexionDiffuse_(rd), 
		reflexionSpecular_(rs), 
		expReflexionSpecular_(ers) 	{}


