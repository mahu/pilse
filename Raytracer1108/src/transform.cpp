#include "transform.hpp"

//
// translate
//
math3d::matrix	translationmatrix(math3d::vector const& v)
{
   	math3d::matrix tmp;

    	tmp[math3d::matrix::da] = v[math3d::vector::x];
    	tmp[math3d::matrix::db] = v[math3d::vector::y];
    	tmp[math3d::matrix::dc] = v[math3d::vector::z];

	return tmp;	
};
//


//
// rotate
//
math3d::matrix	rotationmatrix(math3d::vector const& v, double w)
{
   	math3d::matrix tmp;

   	double const cosW(std::cos(w));
    	double const sinW(std::sin(w));
	double const x = v[math3d::vector::x];
	double const y = v[math3d::vector::y];
	double const z = v[math3d::vector::z];
	double const einsMinusCosW = 1 - cosW;

    	tmp[math3d::matrix::aa] = cosW + x * x * einsMinusCosW;
    	tmp[math3d::matrix::ab] = x * y * einsMinusCosW + y * sinW;
    	tmp[math3d::matrix::ac] = x * z * einsMinusCosW - y * sinW;
    	tmp[math3d::matrix::ba] = x * y * einsMinusCosW - z * sinW;
    	tmp[math3d::matrix::bb] = cosW + y * y * einsMinusCosW;
    	tmp[math3d::matrix::bc] = y * z * einsMinusCosW + x * sinW;
    	tmp[math3d::matrix::ca] = x * z * einsMinusCosW + y * sinW;
    	tmp[math3d::matrix::cb] = y * z * einsMinusCosW - x * sinW;
    	tmp[math3d::matrix::cc] = cosW + z * z * einsMinusCosW;

	return tmp;
};
//


//
// scale
//
math3d::matrix	scalingmatrix(math3d::vector const& v)
{
	math3d::matrix tmp;

    	tmp[math3d::matrix::aa] = v[math3d::vector::x];
    	tmp[math3d::matrix::bb] = v[math3d::vector::y];
    	tmp[math3d::matrix::cc] = v[math3d::vector::z];

	return tmp;
};
//




