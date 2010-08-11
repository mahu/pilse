#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__


#include "matrix.hpp"
#include "transform.hpp"
#include "vector.hpp"


#include <string>

class camera
{

    public:

				camera();
				camera(std::string const&, double, double,
					math3d::matrix const& matr    = math3d::matrix::identity(), 
					math3d::matrix const& matrInv = math3d::matrix::identity() );
		void		translate(math3d::vector const&);
		void		scale(math3d::vector const&);
		void		rotate(math3d::vector const&, double);


    private:

	std::string	name_;
	double		fovX_;
	double		fovY_;

	math3d::matrix	worldMatrix_;
	math3d::matrix	worldMatrixInvers_;
};


#endif /* __camera_HPP__ */
