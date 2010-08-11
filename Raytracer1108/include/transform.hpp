#ifndef __TRANSFORM_HPP__
#define __TRANSFORM_HPP__

#include "vector.hpp"
#include "point.hpp"
#include "rgb.hpp"
#include "matrix.hpp"


#include <cmath>
#include <string>

math3d::matrix	translationmatrix(math3d::vector const&);
math3d::matrix	rotationmatrix(math3d::vector const&, double);
math3d::matrix	scalingmatrix(math3d::vector const&);


#endif /* __transform_HPP__ */
