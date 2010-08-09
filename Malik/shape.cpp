#include"shape.hpp"
#include"color.hpp"
#include<string>
#include<iostream>

shape::shape():clr_(),name_("Shape")
{
	//std::cout<<"Konstruktor Shape"<<std::endl;
	count=0;
}

shape::shape(color c, std::string s):clr_(c),name_(s) 
{
	//std::cout<<"Konstruktor Shape"<<std::endl;
	count=0;
}

shape::shape(shape const& s):
  clr_(s.clr_),
  name_(s.name_)
  {
	count=0;
  }

shape::~shape()
{
	//std::cout<<"Destruktor Shape"<<std::endl;
}

void shape::print_on(std::ostream& str) const
{
	str<<"\nName:"<<name_<<"\nFarbe: ["<<clr_.r_<<","<<clr_.g_<<","<<clr_.b_<<"]"<<std::endl;
}

std::string shape::get_name() const
  {
	return name_;
  }

color shape::get_color() const
  {
	return clr_;
  }

void shape::set_color(color const& c)
  {
	clr_=c;
  }

void shape::set_name(std::string const& n)
  {
	name_=n;
  }

void shape::ref()
  {
	++count;
  }

void shape::unref()
  {
	--count;
	if(count<=0)
	{	
		delete this;
	}
  }

int shape::get_refcount()
  {
	return count;
  }




std::ostream& operator<<(std::ostream& stream, shape const& obj)
{
	obj.print_on(stream);
	return stream;
}

