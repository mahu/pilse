#ifndef _SHAPECONTAINER_HPP
#define	_SHAPECONTAINER_HPP

#include <iostream>
#include <string>
#include "color.hpp"
#include "point3d.hpp"
#include "shape.hpp"
#include <list>
#include <algorithm>
#include <numeric>
#include <functional>

class shapeContainer
{
    public:
				shapeContainer();
				shapeContainer(shapeContainer const&);
				~shapeContainer();
 	
	void			insertShapeObj(shape *);
	void			deleteShapeObj(color const&);
	void			deleteShapeObj(std::string const&);
	void			print(std::ostream& stream=std::cout)	const;
	shapeContainer		cloneDeep()	const;
	shapeContainer 		cloneShallow()	const;
	shapeContainer	&	operator=(shapeContainer const&);


    //private:

	std::list<shape*>	shapeCon_;


};

void printShapeName(shape const*);
double getTotalVolume(double, shape const*);

#endif	/* _shapecontainer_HPP */

