#ifndef _SPHERE_HPP
#define	_SPHERE_HPP

#include "shape.hpp"
#include "point.hpp"
#include "rgb.hpp"
#include "ray.hpp"

class sphere : public shape
{
    public:
                        	sphere();
				sphere(math3d::point const&, double, std::string const&, rgb const&);
				sphere(sphere const&);
				~sphere();
 
	/*virtual*/ 	double	volume()			const;
	/*virtual*/ 	bool	isInside(math3d::point const&)	const;
	/*virtual*/	double	surface()			const;
	/*virtual*/	void	printOn( std::ostream&)		const;
	/*virtual*/	sphere*	clone()				const;

			double	intersection(ray const&);
	//		sphere*	operator=(sphere*);
	//		sphere	operator=(sphere);




    private:
			math3d::point	center_;
			double 		radius_;

};



#endif	/* _sphere_HPP */

