#include "glutwindow.hpp"
#include "ppmwriter.hpp"
#include "pixel.hpp"
#include "vector.hpp"
#include "ray.hpp"
#include "camera.hpp"
#include "shape.hpp"
#include "light.hpp"


#include <iostream>
#include <cmath>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>

#ifdef __APPLE__
  #include <GLUT/glut.h>
#else
  #include <GL/glut.h>
#endif

// this is a dummy raytrace application
class rt_application 
{
    private : // attributes

 	// you may add a scene description here
	std::list<shape*>	shapeList_;
	camera 			cam_;
	std::list<light*>	lightList_;


    public :
 
	void 	raytrace() 	const 
  	{
    		// get glutwindow instance
    		glutwindow& gw = glutwindow::instance();
    
    		// create a ppmwriter
    		ppmwriter pw(gw.width(), gw.height(), "./checkerboard.ppm");

    		// for all pixels of window
		double height (gw.height());
		double width (gw.width());
		double z = height * 0.5 / std::tan(cam_.fovX_ * M_PI / 360);

    		for (int y = -int( height / 2); y < int((height+1) / 2); ++y) 
		{
      			for (int x = -int( width / 2); x < int((width+1) / 2); ++x) 
			{     
        			// create pixel at x,y
			        pixel p(x, y);

        			// compute color for pixel
				//ray r(math3d::vector(0,0,0,0), math3d::vector(x, y, z));

				//p.color = r.trace (shapeList_, lightList_);

       				// write pixel to output window
        			gw.write(p);

        			// write pixel to image writer
        			pw.write(p);
      			}
    		}

    		// save final image
    		pw.save();
  	}




};





int main(int argc, char* argv[])
{
  	// set resolution and checkersize
  	const std::size_t width = 480;
  	const std::size_t height = 320;
	
  	// create output window
  	glutwindow::init(width, height, 100, 100, "CheckerBoard", argc, argv);
 	
  	// create a ray tracing application
  	rt_application app;
	
  	// start computation in thread
  	boost::thread thr(boost::bind(&rt_application::raytrace, &app));
  	
  	// start output on glutwindow
  	glutwindow::instance().run();
  	
  	// wait on thread
  	thr.join();
	
  	return 0;
}









