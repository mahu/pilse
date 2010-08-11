#include "shape.hpp"


shape::shape() : refCount_(0)	{}
shape::shape(std::string const& s, material const& mat, math3d::matrix const& matr) : 
		name_(s) , 
		refCount_(0), 
		material_(mat),
		worldMatrix_(matr)	{}

shape::shape(shape const& sh) : 
		name_(sh.name_), 
		refCount_(0), 
		material_(sh.material_),
		worldMatrix_(sh.worldMatrix_)	 {}

shape::~shape() {}


//
// getmaterial
//
material shape::getMaterial()	const
{
	return material_;	
}
//


//
// getname
//
std::string shape::getName()	const
{
	return name_;	
}
//


//
// printOn
//
void shape::printOn( std::ostream& stream)	const
{
	stream << "Name: " << name_ << "\n"; //, Farbe: (" << color_[rgb::r] << "," << color_[rgb::g] << "," << color_[rgb::b] << ")\n";
}
//

std::ostream& operator<<(std::ostream& stream, shape const& sh)
{
	sh.printOn(stream);
	return stream;
}

bool operator==(shape const& lhs, shape const& rhs)
{
	return lhs.getName() == rhs.getName();	
}


//
// ref
//
int	shape::ref()
{
	return ++refCount_;
}
//


//
// unRef
//
int	shape::unRef()
{
	--refCount_;
	if (refCount_ <= 0)
	{
		delete this;	
		return 0;
	}
	return refCount_;
}
//


//
// translate
//
void	translate(math3d::vector const&)
{
	
}
//


//
// scale
//
void	scale(math3d::vector const&)
{
	
}
//


//
// rotate
//
void	rotate(math3d::vector const&, double)
{
	
}
//










