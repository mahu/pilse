
#include<cmath>
#include "sphere.hpp"


sphere::sphere() 	{}
sphere::sphere(math3d::point const& c, double r, std::string const& name, rgb const& col) : shape(name, col) , center_(c) , radius_(r)
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
bool	sphere::isInside(math3d::point const& p)	const
{
	return ( (sqrt(pow(center_[math3d::point::x]-p[math3d::point::x],2) + pow(center_[math3d::point::y]-p[math3d::point::y],2) + pow(center_[math3d::point::z]-p[math3d::point::z],2))) <= radius_);
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
	stream << "Mittelpunkt: (" << center_[math3d::point::x] << "," << center_[math3d::point::y] << "," << center_[math3d::point::z] << ")\n";
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

double sphere::intersection(ray a)
{
	if(sqrt(pow(a.origin_,2)-4*(origin_*origin_-pow(radius,2)))>0)
	{
		double i_1=0.5*(-(2*a.origin_)-sqrt(pow(a.origin_,2)-4*(origin_*origin_-pow(radius,2))));
		double i_2=0.5*(-(2*a.origin_)+sqrt(pow(a.origin_,2)-4*(origin_*origin_-pow(radius,2))));
		
		if(i_1<=i_2)
			return i_1;
		else
			return i_2;
		

	}
	else if (sqrt(pow(a.origin_,2)-4*(origin_*origin_-pow(radius,2)))==0)
	{
		double i_1=0.5*(-(2*a.origin_)-sqrt(pow(a.origin_,2)-4*(origin_*origin_-pow(radius,2))));
		
		return i_1;
	}
	
	return ~0;
}


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











