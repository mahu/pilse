#ifndef __RTAPPLICATION_HPP__
#define __RTAPPLICATION_HPP__

#include "light.hpp"
#include "shape.hpp"
#include "material.hpp"
#include "camera.hpp"

#include "glutwindow.hpp"
#include "ppmwriter.hpp"
#include "pixel.hpp"
#include "vector.hpp"
#include "rgb.hpp"

#include <iostream>
#include <cmath>
#include <list>


class rtApplication 
{
    public :
 
			rtApplication();
			rtApplication(std::list<shape*> const&, camera const&, std::list<light> const&);
			~rtApplication();
	void 		raytrace() 	const;

    //private :

	std::list<shape*>	shapeList_;
	camera 			cam_;
	std::list<light>	lightList_;
};



#endif /* __RTAPPLICATION_HPP__ */

