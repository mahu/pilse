#include "camera.hpp"

//
// Konstruktoren
//
camera::camera()	{}
camera::camera(std::string const& n, double x, double y, math3d::matrix const& matr, math3d::matrix const& matrInv) : 
		name_(n) , 
		fovX_(x), 
		fovY_(y),
		worldMatrix_(matr),
		worldMatrixInvers_(matrInv)	{}
//


//
// translate
//
void	camera::translate(math3d::vector const& v)
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
void	camera::scale(math3d::vector const& v)
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
void	camera::rotate(math3d::vector const& v, double w)
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

