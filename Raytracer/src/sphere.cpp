
#include<cmath>
#include "sphere.hpp"

//
// Konstruktoren
//
sphere::sphere() 	{}
sphere::sphere(math3d::point const& c, double r, std::string const& name, rgb const& col, material const& mat) : 
		shape(name, col, mat) , 
		center_(c) , 
		radius_(r)
			{}
sphere::sphere(sphere const& sp) : 
		shape(sp) , 
		center_(sp.center_) , 
		radius_(sp.radius_) 	{}

sphere::~sphere() 	{}
//


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
//




//
// intersection
//
double sphere::intersection(ray const& g) const

{
	//Strahl transformieren
	//Multiplikation mit inverser Matrix der Sphere

	//quadratische gl

	double a = math3d::dot(g.direction_, g.direction_);
	double b = 2 * (math3d::dot(g.origin_ , g.direction_));
	double c = (math3d::dot(g.origin_ , g.origin_)) - (radius_*radius_);

	
	double under_sqrt = (b * b) - 4 * c;

	if(under_sqrt < 0)
	{
		return ~0;
	}
	else if (under_sqrt > 0)
	{
		double i_1 = 0.5 * (-b - sqrt(under_sqrt)) / a;
		double i_2 = 0.5 * (-b + sqrt(under_sqrt)) / a;
		
		if(i_1 >= i_2)
			return i_1;
		else
			return i_2;	
	}
	else
	{
		double i_1 = -(0.5 * b) / a;
		
		return i_1;
	}
}
//







