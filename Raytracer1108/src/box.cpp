#include "box.hpp"

//
// Konstruktoren, Destruktor
//
box::box() 	{}

box::box(math3d::point const& p1, math3d::point const& p2, std::string const& name, material const& mat, math3d::matrix const& matr, math3d::matrix const& matrInv) : 
		shape(name,mat, matr, matrInv) , 
		vertexLuh_ (p1), 
		vertexRov_ (p2)		{}

box::box(box const& bx) : 
		shape(bx) , 
		vertexLuh_(bx.vertexLuh_) , 
		vertexRov_(bx.vertexRov_)	{}

box::~box() 	{}
//


//
// volume - Berechnung boxvolumen
//
double	box::volume()	const
{
	return  std::abs( (vertexLuh_[math3d::point::x]-vertexRov_[math3d::point::x]) * 
			  (vertexLuh_[math3d::point::y]-vertexRov_[math3d::point::y]) * 
			  (vertexLuh_[math3d::point::z]-vertexRov_[math3d::point::z])   );
}
//


//
// isInside - Kollision
//
bool	box::isInside(math3d::point const& p)	const
{
	return ( (p[math3d::point::x] >= vertexLuh_[math3d::point::x] && p[math3d::point::x] <= vertexRov_[math3d::point::x]) &&
		 (p[math3d::point::y] >= vertexLuh_[math3d::point::y] && p[math3d::point::y] <= vertexRov_[math3d::point::y]) &&
		 (p[math3d::point::z] >= vertexLuh_[math3d::point::z] && p[math3d::point::z] <= vertexRov_[math3d::point::z]) );
}
//


//
// surface - Berechnung Oberfläche
//
double	box::surface()	const
{
     return (  std::abs(2* (vertexLuh_[math3d::point::x]-vertexRov_[math3d::point::x]) * (vertexLuh_[math3d::point::y]-vertexRov_[math3d::point::y])) 
	     + std::abs(2* (vertexLuh_[math3d::point::x]-vertexRov_[math3d::point::x]) * (vertexLuh_[math3d::point::z]-vertexRov_[math3d::point::z])) 
	     + std::abs(2* (vertexLuh_[math3d::point::z]-vertexRov_[math3d::point::z]) * (vertexLuh_[math3d::point::y]-vertexRov_[math3d::point::y])) );
}
//


//
// printOn - Ausgabe
//
void box::printOn(std::ostream& stream)		const
{
	stream << "\nBox: \n";
	shape::printOn(stream);
	stream << "Vertex Links unten hinten: " << vertexLuh_[math3d::point::x] << " " 
		<< vertexLuh_[math3d::point::y] << " " << vertexLuh_[math3d::point::z] << "\n";
	stream << "Vertex Rechts oben vorne: " << vertexRov_[math3d::point::x] << " " 
		<< vertexRov_[math3d::point::y] << " " << vertexRov_[math3d::point::z] << "\n";
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


//
// intersection
//
double box::intersection(ray const& ray) const
{

// durch Null teilen???

	double t = ~0;
	double p_x, p_y, p_z;
	
	//linke seite quader
	double t_x_min = (vertexLuh_[math3d::point::x] - ray.origin_[math3d::vector::x]) / ray.direction_[math3d::vector::x];

	if (t_x_min < t)
	{
		p_y = ray.origin_[math3d::vector::y] + t_x_min * ray.direction_[math3d::vector::y];
		p_z = ray.origin_[math3d::vector::z] + t_x_min * ray.direction_[math3d::vector::z];

		if( p_y >= vertexLuh_[math3d::point::y] && p_y <= vertexRov_[math3d::point::y] &&
		    p_z >= vertexLuh_[math3d::point::z] && p_z <= vertexRov_[math3d::point::z] )
			t = t_x_min;
	}

	//untere seite quader
	double t_y_min = (vertexLuh_[math3d::point::y] - ray.origin_[math3d::vector::y]) / ray.direction_[math3d::vector::y];

	if (t_y_min < t)
	{
		p_x = ray.origin_[math3d::vector::x] + t_y_min * ray.direction_[math3d::vector::x];
		p_z = ray.origin_[math3d::vector::z] + t_y_min * ray.direction_[math3d::vector::z];

		if( p_x >= vertexLuh_[math3d::point::x] && p_x <= vertexRov_[math3d::point::x] &&
		    p_z >= vertexLuh_[math3d::point::z] && p_z <= vertexRov_[math3d::point::z] )
			t = t_y_min;
	}

	//hintere seite quader
	double t_z_min = (vertexLuh_[math3d::point::z] - ray.origin_[math3d::vector::z]) / ray.direction_[math3d::vector::z];

	if (t_z_min < t)
	{
		p_x = ray.origin_[math3d::vector::x] + t_z_min * ray.direction_[math3d::vector::x];
		p_y = ray.origin_[math3d::vector::y] + t_z_min * ray.direction_[math3d::vector::y];

		if( p_x >= vertexLuh_[math3d::point::x] && p_x <= vertexRov_[math3d::point::x] &&
		    p_y >= vertexLuh_[math3d::point::y] && p_z <= vertexRov_[math3d::point::y] )
			t = t_z_min;
	}

	//rechte seite quader
	double t_x_max = (vertexRov_[math3d::point::x] - ray.origin_[math3d::vector::x]) / ray.direction_[math3d::vector::x];

	if (t_x_max < t)
	{
		p_y = ray.origin_[math3d::vector::y] + t_x_max * ray.direction_[math3d::vector::y];
		p_z = ray.origin_[math3d::vector::z] + t_x_max * ray.direction_[math3d::vector::z];

		if( p_y >= vertexLuh_[math3d::point::y] && p_y <= vertexRov_[math3d::point::y] &&
		    p_z >= vertexLuh_[math3d::point::z] && p_z <= vertexRov_[math3d::point::z] )
			t = t_x_max;
	}

	//obere seite quader
	double t_y_max = (vertexRov_[math3d::point::y] - ray.origin_[math3d::vector::y]) / ray.direction_[math3d::vector::y];

	if (t_y_max < t)
	{
		p_x = ray.origin_[math3d::vector::x] + t_y_max * ray.direction_[math3d::vector::x];
		p_z = ray.origin_[math3d::vector::z] + t_y_max * ray.direction_[math3d::vector::z];

		if( p_x >= vertexLuh_[math3d::point::x] && p_x <= vertexRov_[math3d::point::x] &&
		    p_z >= vertexLuh_[math3d::point::z] && p_z <= vertexRov_[math3d::point::z] )
			t = t_y_max;
	}

	//vordere seite quader
	double t_z_max = (vertexRov_[math3d::point::z] - ray.origin_[math3d::vector::z]) / ray.direction_[math3d::vector::z];

	if (t_z_max < t)
	{
		p_x = ray.origin_[math3d::vector::x] + t_z_max * ray.direction_[math3d::vector::x];
		p_y = ray.origin_[math3d::vector::y] + t_z_max * ray.direction_[math3d::vector::y];

		if( p_x >= vertexLuh_[math3d::point::x] && p_x <= vertexRov_[math3d::point::x] &&
		    p_y >= vertexLuh_[math3d::point::y] && p_y <= vertexRov_[math3d::point::y] )
			t = t_z_max;
	}

	return t;
}



