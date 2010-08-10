#include "box.hpp"

//
// Konstruktoren, Destruktor
//
box::box() 	{ std::cout << "Konstruktor Box\n"; }

box::box(math3d::point const& p1, math3d::point const& p2, std::string const& name, rgb const& col) 
				: shape(name,col) , vertexLuv_ (p1), vertexRoh_ (p2)
		{ std::cout << "Konstruktor Box\n"; }

box::box(box const& bx) : shape(bx) , vertexLuv_(bx.vertexLuv_) , vertexRoh_(bx.vertexRoh_)	{}

box::~box() 	{ std::cout << "Destruktor Box\n"; }
//


//
// volume - Berechnung boxvolumen
//
double	box::volume()	const
{
	return  std::abs( (vertexLuv_[math3d::point::x]-vertexRoh_[math3d::point::x]) * 
			  (vertexLuv_[math3d::point::y]-vertexRoh_[math3d::point::y]) * 
			  (vertexLuv_[math3d::point::z]-vertexRoh_[math3d::point::z])   );
}
//


//
// isInside - Kollision
//
bool	box::isInside(math3d::point const& p)	const
{
	return ( (p[math3d::point::x] >= vertexLuv_[math3d::point::x] && p[math3d::point::x] <= vertexRoh_[math3d::point::x]) &&
		 (p[math3d::point::y] >= vertexLuv_[math3d::point::y] && p[math3d::point::y] <= vertexRoh_[math3d::point::y]) &&
		 (p[math3d::point::z] >= vertexLuv_[math3d::point::z] && p[math3d::point::z] <= vertexRoh_[math3d::point::z]) );
}
//


//
// surface - Berechnung Oberfläche
//
double	box::surface()	const
{
     return (  std::abs(2* (vertexLuv_[math3d::point::x]-vertexRoh_[math3d::point::x]) * (vertexLuv_[math3d::point::y]-vertexRoh_[math3d::point::y])) 
	     + std::abs(2* (vertexLuv_[math3d::point::x]-vertexRoh_[math3d::point::x]) * (vertexLuv_[math3d::point::z]-vertexRoh_[math3d::point::z])) 
	     + std::abs(2* (vertexLuv_[math3d::point::z]-vertexRoh_[math3d::point::z]) * (vertexLuv_[math3d::point::y]-vertexRoh_[math3d::point::y])) );
}
//


//
// printOn - Ausgabe
//
void box::printOn(std::ostream& stream)		const
{
	stream << "\nBox: \n";
	shape::printOn(stream);
	stream << "Vertex Links unten vorne: " << vertexLuv_[math3d::point::x] << " " 
		<< vertexLuv_[math3d::point::y] << " " << vertexLuv_[math3d::point::z] << "\n";
	stream << "Vertex Rechts oben hinten: " << vertexRoh_[math3d::point::x] << " " 
		<< vertexRoh_[math3d::point::y] << " " << vertexRoh_[math3d::point::z] << "\n";
	//stream << "Länge: " << x_ << " ,  Breite: " << z_ << " ,  Höhe: " << y_ << "\n";
	stream << "Volumen: " << volume() << "\nOberfläche: " << surface() << "\n";
}
//


//
// clone
//
box* box::clone()	const
{
	return new box(*this);	
}
//


