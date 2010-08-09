#include<list>
#include<string>
#include<iostream>
#include"color.hpp"
#include"shape.hpp"
class shape_container{

public:

	shape_container();
	shape_container(std::list<shape*>);
	shape_container(shape_container const&);
	void add_shape(shape*);
	void remove_shape(shape*);
	void remove_shape(std::string);
	void remove_shape(color);
	void remove_shape_v(double);
	void remove_shape_s(double);
	double volumina();
	void print();
	shape_container clone_deep();
	shape_container clone_shallow();
	shape_container& operator=(shape_container const&);
	
private:
	
	std::list<shape*> shapes_;
	
};




