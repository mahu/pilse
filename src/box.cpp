

#include "box.hpp"


box::box() 	{ std::cout << "Konstruktor Box\n"; }
box::box(point const& p1, point const& p2, std::string const& name, color const& col) 
		: shape(name,col) , vertex_[0](p1), vertex_[1](p2)
		{ std::cout << "Konstruktor Box\n"; }
box::box(box const& bx) : shape(bx) , vertex_(bx.vertex_[0]) , vertex_[1](bx.vertex_[1])	{}
box::~box() 	{ std::cout << "Destruktor Box\n"; }

//
// volume - Berechnung boxvolumen
//
double	box::volume()	const
{
	return  std::abs( (vertex_[0].data[x]-vertex_[1].data[x]) * (vertex_[0].data[y]-vertex_[1].data[y]) * (vertex_[0].data[z]-vertex_[1].data[z]) );
}
//


//
// isInside - Kollision
//
bool	box::isInside(point const& p)	const
{	
	return ( (p[x] >= vertex_[0].data[x] && p[x] <= vertex_[1].data[x]) &&
		 (p[y] >= vertex_[0].data[y] && p[y] <= vertex_[1].data[y]) &&
		 (p[z] >= vertex_[0].data[z] && p[z] <= vertex_[1].data[z]) );
	//return  (p.getx() >= vertex_.getx() && p.getx() <= vertex_.getx()+x_) &&
	//	(p.gety() >= vertex_.gety() && p.gety() <= vertex_.gety()+y_) &&
	//	(p.getz() >= vertex_.getz() && p.getz() <= vertex_.getz()+z_);	

	/*if ( 	skalarpro( point3d(-1,0,0), point3d(p.getx()-vertex_.getx(),    p.gety()-vertex_.gety(),    p.getz()-vertex_.getz()))    >= 0 &&
		skalarpro( point3d(1,0,0),  point3d(p.getx()-vertex_.getx()-x_, p.gety()-vertex_.gety(),    p.getz()-vertex_.getz()))    >= 0 &&
		skalarpro( point3d(0,1,0),  point3d(p.getx()-vertex_.getx(),    p.gety()-vertex_.gety()-y_, p.getz()-vertex_.getz()))    >= 0 &&
		skalarpro( point3d(0,-1,0), point3d(p.getx()-vertex_.getx(),    p.gety()-vertex_.gety(),    p.getz()-vertex_.getz()))    >= 0 &&
		skalarpro( point3d(0,0,1),  point3d(p.getx()-vertex_.getx(),    p.gety()-vertex_.gety(),    p.getz()-vertex_.getz()))    >= 0 &&
		skalarpro( point3d(0,0,-1), point3d(p.getx()-vertex_.getx(),    p.gety()-vertex_.gety(),    p.getz()-vertex_.getz()+z_)) >= 0 )
		return false;
	else
		return true;*/
}
//


//
// surface - Berechnung Oberfläche
//
double	box::surface()	const
{
	return (  std::abs(2 * (vertex_[0].data[x]-vertex_[1].data[x]) * (vertex_[0].data[y]-vertex_[1].data[y])) 
	 	+ std::abs(2 * (vertex_[0].data[x]-vertex_[1].data[x]) * (vertex_[0].data[z]-vertex_[1].data[z])) 
		+ std::abs(2 * (vertex_[0].data[z]-vertex_[1].data[z]) * (vertex_[0].data[y]-vertex_[1].data[y]))  );
}
//


//
// printOn - Ausgabe
//
void box::printOn(std::ostream& stream)		const
{
	stream << "\nBox: \n";
	shape::printOn(stream);
	//stream << "Vertex: " << vertex_[x] << " " << vertex_[y] << " " << vertex_[z] << "\n";
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


