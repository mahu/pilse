#ifndef _SPHERE_HPP
#define	_SPHERE_HPP

#include "shape.hpp"
#include "point3d.hpp"
#include "color.hpp"

class sphere : public shape
{
    public:
                        	sphere();
				sphere(point const&, double, std::string const&, rgb const&);
				sphere(sphere const&);
				~sphere();
 
	/*virtual*/ 	double	volume()			const;
	/*virtual*/ 	bool	isInside(point const&)	const;
	/*virtual*/	double	surface()			const;
	/*virtual*/	void	printOn( std::ostream&)		const;
	/*virtual*/	sphere*	clone()				const;
	//		sphere*	operator=(sphere*);
	//		sphere	operator=(sphere);


    private:
			point	center_;
			double 	radius_;

};



#endif	/* _sphere_HPP */

