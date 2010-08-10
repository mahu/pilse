#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__



#include <string>

struct camera
{

	//Konstruktoren

			camera();
			camera(std::string, double, double);


	//Membervariablen

	std::string	name_;
	double		fovX_;
	double		fovY_;
};


#endif /* __camera_HPP__ */
