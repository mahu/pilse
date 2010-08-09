#ifndef SHAPE_HPP_
#define SHAPE_HPP_
#include"point3d.hpp"
#include"color.hpp"
#include<string>
#include<iostream>

class shape 
{

	public:

		shape();
		shape(color,std::string);
		shape(shape const& s);
		
		~shape();


		virtual void print_on(std::ostream&) const;
		virtual double volume()const=0 ;
		virtual double surface()const=0 ;
		virtual bool is_inside(point3d const&)const=0;
		virtual shape* clone()=0;
		std::string get_name() const;
		color get_color() const;
		void set_color(color const&);
		void set_name(std::string const&);
		void ref();
		void unref();
		int get_refcount();
	
	private:
	
		std::string name_;
		color clr_;
		int count;

};


std::ostream& operator<<(std::ostream& stream, shape const& obj);
#endif
