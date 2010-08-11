#include "shape.hpp"


shape::shape() : refCount_(0)	{}
shape::shape(std::string const& s, material const& mat, math3d::matrix const& matr, math3d::matrix const& matrInv) : 
		name_(s) , 
		refCount_(0), 
		material_(mat),
		worldMatrix_(matr),
		worldMatrixInvers_(matrInv)	{}

shape::shape(shape const& sh) : 
		name_(sh.name_), 
		refCount_(0), 
		material_(sh.material_),
		worldMatrix_(sh.worldMatrix_),
		worldMatrixInvers_(sh.worldMatrixInvers_)	 {}

shape::~shape() {}


//
// getmaterial
//
material shape::getMaterial()	const
{
	return material_;	
}
//


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
	stream << "Name: " << name_ << "\n";
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


//
// translate
//
void	shape::translate(math3d::vector const& v)
{
/*   	matrix tmp;

    	tmp[math3d::matrix::da] = v[math3d::vector::x];
    	tmp[math3d::matrix::db] = v[math3d::vector::y];
    	tmp[math3d::matrix::dc] = v[math3d::vector::z];
*/

	worldMatrix_ *= translationmatrix(v);
	worldMatrixInvers_ = inverse(worldMatrix_);
}
//


//
// scale
//
void	shape::scale(math3d::vector const& v)
{
/*   	matrix tmp;

    	tmp[math3d::matrix::aa] = v[math3d::vector::x];
    	tmp[math3d::matrix::bb] = v[math3d::vector::y];
    	tmp[math3d::matrix::cc] = v[math3d::vector::z];
*/

	worldMatrix_ *= scalingmatrix(v);
	worldMatrixInvers_ = inverse(worldMatrix_);
}
//


//
// rotate
//
void	shape::rotate(math3d::vector const& v, double w)
{
/*   	matrix tmp;

   	double const cosW(std::cos(w));
    	double const sinW(std::sin(w));
	double const x = v[math3d::vector::x];
	double const y = v[math3d::vector::y];
	double const z = v[math3d::vector::z];
	double const tmp = 1 - cosW;

    	tmp[math3d::matrix::aa] = cosW + x * x * tmp;
    	tmp[math3d::matrix::ab] = x * y * tmp + y * sinW;
    	tmp[math3d::matrix::ac] = x * z * tmp - y * sinW;
    	tmp[math3d::matrix::ba] = x * y * tmp - z * sinW;
    	tmp[math3d::matrix::bb] = cosW + y * y * tmp;
    	tmp[math3d::matrix::bc] = y * z * tmp + x * sinW;
    	tmp[math3d::matrix::ca] = x * z * tmp + y * sinW;
    	tmp[math3d::matrix::cb] = y * z * tmp - x * sinW;
    	tmp[math3d::matrix::cc] = cosW + z * z * tmp;
*/

	worldMatrix_ *= rotationmatrix(v,w);
	worldMatrixInvers_ = inverse(worldMatrix_);
}
//










