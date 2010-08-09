

#include "shapeContainer.hpp"


shapeContainer::shapeContainer() 	{ std::cout << "Konstruktor ShapeContainer\n"; }
shapeContainer::shapeContainer(shapeContainer const& sC) : shapeCon_(sC.shapeCon_) 
{
	for (std::list<shape*>::iterator i = shapeCon_.begin(); i != shapeCon_.end(); ++i )
	{
		(**i).ref();
	} 
	std::cout << "Konstruktor ShapeContainer\n"; 
}
shapeContainer::~shapeContainer() 
{
	for (std::list<shape*>::iterator i = shapeCon_.begin(); i != shapeCon_.end(); ++i )
	{
		(**i).unRef();

	} 
	std::cout << "Destruktor ShapeContainer\n";
}


//
// insertShapeObj
//
void	shapeContainer::insertShapeObj (shape * sh)
{
	shapeCon_.push_back(sh);
	sh->ref();
}
//


//
// deleteShapeObj
//
void	shapeContainer::deleteShapeObj (std::string const& name)
{
	for (std::list<shape*>::iterator i = shapeCon_.begin(); i != shapeCon_.end(); ++i )
	{
		if ( (**i).getName() == name ) 
		{
			(**i).unRef();

			i = shapeCon_.erase(i);
		}
	}
}
//
void	shapeContainer::deleteShapeObj (color const& clr)
{
	for (std::list<shape*>::iterator i = shapeCon_.begin(); i != shapeCon_.end(); ++i )
	{
		if ( (**i).getColor() == clr )
		{
			(**i).unRef();

			i = shapeCon_.erase(i);
		}
	}	
}
//


//
// print
//
void shapeContainer::print(std::ostream& stream )		const
{
	double tempVol=0;

	/*for (std::list<shape*>::const_iterator i = shapeCon_.begin(); i != shapeCon_.end(); ++i )
	{
		stream << "Name : " << (**i).getName() << "\n";
		tempVol += (**i).volume();
	}
	stream << "Gesamtvolumen: " << tempVol << std::endl;*/

	std::for_each (shapeCon_.begin(), shapeCon_.end(), printShapeName);
	stream << "Gesamtvolumen: " << std::accumulate (shapeCon_.begin(), shapeCon_.end(), tempVol, getTotalVolume) << std::endl;

}
// std::for_each Hilfsfunktion
void printShapeName(shape const* sh)
{
	std::cout << "Name: " << sh->getName() << std::endl;
}
// std::accumulate Hilfsfunktion
double getTotalVolume(double x, shape const* sh2)
{
	return x + sh2->volume();
}
//


//
// cloneDeep
//
shapeContainer 	shapeContainer::cloneDeep()	const
{
	shapeContainer sC;

	for (std::list<shape*>::const_iterator i = shapeCon_.begin(); i != shapeCon_.end(); ++i )
	{
		shape* sh = (**i).clone();
		sC.insertShapeObj(sh);
	}
	return sC;	
}
//


//
// cloneShallow
//
shapeContainer 	shapeContainer::cloneShallow()	const
{
	return shapeContainer(*this);	
}
//



//
// operator =
//
shapeContainer& shapeContainer::operator=(shapeContainer const& sC)
{
	if ( &sC == this )
		return *this;

	//for (std::list<shape*>::iterator i = shapeCon_.begin(); i != shapeCon_.end(); ++i )
	//{
	//	if ( (**i).unRef() == 0 )	i = shapeCon_.erase(i);	
	//}

	//for (std::list<shape*>::iterator i = sC.shapeCon_.begin(); i != sC.shapeCon_.end(); ++i )
	//{
	//	(**i).ref();
	//}
	// return sC;

	shapeContainer temp(sC);
	std::swap(temp.shapeCon_,this->shapeCon_);
	return *this;
	
}
//




