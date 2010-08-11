#include "light.hpp"

light::light()	{}

light::light(math3d::point p, std::string n, rgb la, rgb ld) : 
		location_(p) , 
		name_(n) , 
		lightAmbient_(la) , 
		lightDiffuse_(ld)	{}

