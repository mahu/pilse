#ifndef _BOX_HPP
#define	_BOX_HPP

#include "shape.hpp"
#include "matrix.hpp"
#include "vector.hpp"
#include "point.hpp"
#include "rgb.hpp"
#include "ray.hpp"
#include "material.hpp"


#include <cmath>


class box : public shape
{
    public:
                        	box();
				box( math3d::point const&, math3d::point const&, std::string const&, material const&,
					math3d::matrix const& matr    = math3d::matrix::identity(), 
					math3d::matrix const& matrInv = math3d::matrix::identity()  );
				box(box const&);
				~box();
 
	/*virtual*/ 	double	volume()				const;
	/*virtual*/ 	bool	isInside(math3d::point const&)		const;
	/*virtual*/	double	surface()				const;
	/*virtual*/	void	printOn(std::ostream&)			const;
	/*virtual*/	box*	clone()					const;
			double	intersection(ray const&)		const;



    private:
			math3d::point	vertexLuh_;
			math3d::point	vertexRov_;
};



#endif	/* _BOX_HPP */
