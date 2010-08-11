#include "ray.hpp"

ray::ray() :
	origin_(0,0,0,0),
	direction_(0,0,1,0)		{}

ray::ray(math3d::vector o,math3d::vector d) :
  	origin_(o) ,
 	direction_(d)	{}

/*{
	//Normalisieren des Richtungsvektors

	double laenge_dir = std::sqrt(std::pow(direction_[math3d::vector::x],2) +
			              std::pow(direction_[math3d::vector::y],2) +
				      std::pow(direction_[math3d::vector::z],2)  );
	
	if(laenge_dir != 1)
	{
		direction_ = direction_/laenge_dir;
	}
}*/

/*double ray::trace(std::list<shape*> shapeList, std::list<light> const& lightList)
{

}*/
