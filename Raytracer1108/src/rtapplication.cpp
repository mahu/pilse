#include "rtapplication.hpp"

rtApplication::rtApplication()		{}

rtApplication::rtApplication(std::list<shape*> const& sl, camera const& cam, std::list<light> const& ll) :
		shapeList_ (sl) ,
		cam_(cam) ,
		lightList_(ll)		{}

rtApplication::~rtApplication() 	{}

void 	rtApplication::raytrace() 	const 
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
			ray r(math3d::vector(0,0,0,0), math3d::vector(x, y, z));
	
			double closestT = ~0;
			shape* closestObj = 0;

			for ( std::list<shape*>::const_iterator i = shapeList_.begin(); i != shapeList_.end(); ++i)
			{
				double newT = (**i).intersection(r);
			
				if (newT < closestT)
				{ 
					closestT = newT;
					closestObj = *i;
				}
				
				if (closestObj != 0)
					p.color = closestObj->getMaterial().reflexionAmbient_;
				else
					p.color = rgb(0.3,0.3,0.8);
			}

       			// write pixel to output window
        		gw.write(p);

        		// write pixel to image writer
        		pw.write(p);
      		}
    	}

    	// save final image
    	pw.save();
}










