#ifndef _SHAPE_HPP
#define	_SHAPE_HPP

#include "ray.hpp"
#include "rgb.hpp"
#include "point.hpp"
#include "material.hpp"
#include "matrix.hpp"
#include "transform.hpp"

#include <iostream>
#include <string>

class shape
{
    public:
	                        shape();
				shape(std::string const&, material const&, 
					math3d::matrix const& matr,      // = math3d::matrix::identity(), 
					math3d::matrix const& matrInv ); // = math3d::matrix::identity() );
				shape(shape const&);
	virtual			~shape();
 
	virtual double		volume() 					const 	=0;
	virtual bool		isInside(math3d::point const&)			const	=0;
	virtual	double		surface()					const	=0;
	virtual shape*		clone()						const	=0;
	//virtual	double		intersection(ray const&)			const	=0;
		std::string	getName()					const;
		material	getMaterial()					const;
	virtual	void		printOn(std::ostream& = std::cout)		const;
		int		ref();
		int		unRef();

		void		translate(math3d::vector const&);
		void		scale(math3d::vector const&);
		void		rotate(math3d::vector const&, double);


   private:

	std::string	name_;
	int		refCount_;
	material	material_;
	math3d::matrix	worldMatrix_;
	math3d::matrix	worldMatrixInvers_;
	ray::ray x;

};

std::ostream&	operator<<(std::ostream&, shape const&);
bool		operator==(shape const& lhs, shape const& rhs);



#endif	/* _shape_HPP */

