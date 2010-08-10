#include "shape.hpp"


shape::shape() : refCount_(0)	{}
shape::shape(std::string const& s, rgb const& col) : color_(col) , name_(s) , refCount_(0) {}
shape::shape(shape const& sh) : color_(sh.color_) , name_(sh.name_), refCount_(0) {}
shape::~shape() {}


//
// getcolor
//
rgb shape::getColor()	const
{
	return color_;	
}


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
	stream << "Name: " << name_ << ", Farbe: (" << color_[rgb::r] << "," << color_[rgb::g] << "," << color_[rgb::b] << ")\n";
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













