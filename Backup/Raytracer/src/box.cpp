#include "box.hpp"

//
// Konstruktoren, Destruktor
//
box::box():
  		shape("Box",rgb(),material()),
 		vertexLuv_(math3d::point(0,0,0,1)),
  		vertexRoh_(math3d::point(1,1,1,1))
	{}

box::box(math3d::point const& p1, math3d::point const& p2, std::string const& name,rgb const& col, material const& mat) 
				: shape(name,col,mat) , vertexLuv_ (p1), vertexRoh_ (p2)
		{}

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

double box::intersection(ray const& g) const
{

	double t_x_min= (vertexLuv_[math3d::point::x]/g.direction_[math3d::vector::x])-g.origin_[math3d::vector::x];

	double t_x_min_y=g.origin_[math3d::vector::y]+t_x_min*g.direction_[math3d::vector::y];

	double t_x_min_z=g.origin_[math3d::vector::z]+t_x_min*g.direction_[math3d::vector::z];

	if(vertexLuv_[math3d::point::y]<=t_x_min_y && t_x_min_y<=vertexRoh_[math3d::point::y] && vertexLuv_[math3d::point::z]<=t_x_min_z && t_x_min_z<=vertexRoh_[math3d::point::z])
	{
		return t_x_min;
	}

	double t_y_min= (vertexLuv_[math3d::point::y]/g.direction_[math3d::vector::y])-g.origin_[math3d::vector::y];
	
	double t_y_min_x=g.origin_[math3d::vector::x]+t_y_min*g.direction_[math3d::vector::x];
	
	double t_y_min_z=g.origin_[math3d::vector::z]+t_y_min*g.direction_[math3d::vector::z];
	
	if(vertexLuv_[math3d::point::x]<=t_y_min_x && t_y_min_x<=vertexRoh_[math3d::point::x] && vertexLuv_[math3d::point::z]	<=t_y_min_z && t_y_min_z<=vertexRoh_[math3d::point::z])
	{
		return t_y_min;
	}
	
	double t_z_min= (vertexLuv_[math3d::point::z]/g.direction_[math3d::vector::z])-g.origin_[math3d::vector::z];
	
	double t_z_min_x=g.origin_[math3d::vector::x]+t_z_min*g.direction_[math3d::vector::x];
	
	double t_z_min_y=g.origin_[math3d::vector::y]+t_z_min*g.direction_[math3d::vector::y];
	
	if(vertexLuv_[math3d::point::x]<=t_z_min_x && t_z_min_x<=vertexRoh_[math3d::point::x] && vertexLuv_[math3d::point::y]	<=t_z_min_y && t_z_min_y<=vertexRoh_[math3d::point::y])
	{
		return t_z_min;
	}
	
	double t_x_max= (vertexRoh_[math3d::point::x]/g.direction_[math3d::vector::x])-g.origin_[math3d::vector::x];
	
	double t_x_max_y=g.origin_[math3d::vector::y]+t_x_min*g.direction_[math3d::vector::y];
	
	double t_x_max_z=g.origin_[math3d::vector::z]+t_x_min*g.direction_[math3d::vector::z];

	if(vertexLuv_[math3d::point::y]<=t_x_min_y && t_x_min_y<=vertexRoh_[math3d::point::y] && vertexLuv_[math3d::point::z]	<=t_x_min_z && t_x_min_z<=vertexRoh_[math3d::point::z])
	{
		return t_x_max;
	}

	double t_y_max= (vertexRoh_[math3d::point::y]/g.direction_[math3d::vector::y])-g.origin_[math3d::vector::y];

	double t_y_max_x=g.origin_[math3d::vector::x]+t_y_min*g.direction_[math3d::vector::x];

	double t_y_max_z=g.origin_[math3d::vector::z]+t_y_min*g.direction_[math3d::vector::z];

	if(vertexLuv_[math3d::point::x]<=t_y_min_x && t_y_min_x<=vertexRoh_[math3d::point::x] && vertexLuv_[math3d::point::z]<=t_y_min_z && t_y_min_z<=vertexRoh_[math3d::point::z])
	{
		return t_y_max;
	}

	double t_z_max= (vertexRoh_[math3d::point::z]/g.direction_[math3d::vector::z])-g.origin_[math3d::vector::z];

	double t_z_max_x=g.origin_[math3d::vector::x]+t_z_min*g.direction_[math3d::vector::x];

	double t_z_max_y=g.origin_[math3d::vector::y]+t_z_min*g.direction_[math3d::vector::y];

	if(vertexLuv_[math3d::point::x]<=t_z_min_x && t_z_min_x<=vertexRoh_[math3d::point::x] && vertexLuv_[math3d::point::y]<=t_z_min_y && t_z_min_y<=vertexRoh_[math3d::point::y])
	{
		return t_z_max;
	}

return ~0;

}


