#ifndef _SHAPE_HPP
#define	_SHAPE_HPP

#include "rgb.hpp"
#include "point.hpp"
#include "ray.hpp"
#include "material.hpp"

#include <iostream>
#include <string>

class shape
{
    public:
	                        shape();
				shape(std::string const&, rgb const&, material const&);
				shape(shape const&);
	virtual			~shape();
 
	virtual double		volume() 					const 	=0;
	virtual bool		isInside(math3d::point const&)			const	=0;
	virtual	double		surface()					const	=0;
	virtual shape*		clone()						const	=0;
	virtual	double		intersection(ray const&)			const	=0;
		rgb		getColor()					const;
		std::string	getName()					const;
		material	getMaterial()					const;
	virtual	void		printOn(std::ostream& = std::cout)		const;
		int		ref();
		int		unRef();
	//	shape*		operator=(shape*);

   private:

	rgb		color_;
	std::string	name_;
	int		refCount_;
	material	material_;

};

std::ostream&	operator<<(std::ostream&, shape const&);
bool		operator==(shape const& lhs, shape const& rhs);



#endif	/* _shape_HPP */

