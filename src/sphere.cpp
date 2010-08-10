

#include "sphere.hpp"


sphere::sphere() 	{}
sphere::sphere(point const& c, double r, std::string const& name, rgb const& col) : shape(name, col) , center_(c) , radius_(r)
			{}
sphere::sphere(sphere const& sp) : shape(sp) , center_(sp.center_) , radius_(sp.radius_) {}
sphere::~sphere() 	{}

//
// volume - Berechnung Kugelvolumen
//
double	sphere::volume()	const
{
	return pow(radius_,3)*4/3*M_PI;
}
//


//
// isInside - Kollision
//
bool	sphere::isInside(point const& p)	const
{
	( (sqrt(pow(center_[x]-p[x],2) + pow(center_[y]-p[y],2) + pow(center_[z]-p[z],2))) <= radius_)
//		return true;
//	else
//		return false;
}
//


//
// surface - Berechnung Oberfläche
//
double	sphere::surface()	const
{
	return 4* radius_ * radius_ * M_PI; 
}
//


//
// printOn - Ausgabe
//
void sphere::printOn(std::ostream& stream)		const
{
	stream << "\nSphere:\n";
	shape::printOn(stream);
	stream << "Mittelpunkt: (" << center_[x] << "," << center_[y] << "," << center_[z] << ")\n";
	stream << "Radius: " << radius_ << "\n";
}
//


//
// clone
//
sphere* sphere::clone()	const
{
	return new sphere(*this);	
}
//

/*
//
// operator =
//
sphere*	sphere::operator=(sphere* sp)
{
	sp->ref();
std::cout << "\nhihu\n";
	return sp;
}
//

sphere	sphere::operator=(sphere sp)
{
	sp.ref();
std::cout << "\nhihu\n";
	return sp;
}*/
//











