#ifndef _BOX_HPP
#define	_BOX_HPP

#include "shape.hpp"
#include "point.hpp"
#include "rgb.hpp"
<<<<<<< HEAD
#include "ray.hpp"
#include "material.hpp"
=======
>>>>>>> upstream/master
#include <iostream>
#include <cmath>


class box : public shape
{
    public:
                        	box();
<<<<<<< HEAD
				box( math3d::point const&, math3d::point const&, std::string const&,rgb const&, material const&);
=======
				box( math3d::point const&, math3d::point const&, std::string const&, rgb const&);
>>>>>>> upstream/master
				box(box const&);
				~box();
 
	/*virtual*/ 	double	volume()				const;
	/*virtual*/ 	bool	isInside(math3d::point const&)		const;
	/*virtual*/	double	surface()				const;
	/*virtual*/	void	printOn(std::ostream&)			const;
	/*virtual*/	box*	clone()					const;
<<<<<<< HEAD
			double	intersection(ray const&)		const;
=======
>>>>>>> upstream/master



    private:
			math3d::point	vertexLuv_;
			math3d::point	vertexRoh_;
};



#endif	/* _BOX_HPP */
