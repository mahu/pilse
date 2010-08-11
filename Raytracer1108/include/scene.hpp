#ifndef __SCENE_PARSER__
#define __SCENE_PARSER__

#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"
#include "material.hpp"
#include "camera.hpp"
#include "light.hpp"


#include<list>
#include<string>
#include<fstream>
#include<sstream>

class scene

{
	public:
		scene(std::string const&);
	

	public:
		std::list<shape*>	objects;
		std::list<light>	lights;
		std::list<material>	mats;
		std::list<camera>	cam;





};

#endif
