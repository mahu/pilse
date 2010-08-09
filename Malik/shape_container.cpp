#include<list>
#include<string>
#include<iostream>
#include<algorithm>
#include<functional>
#include<numeric>
#include"color.hpp"
#include"shape.hpp"
#include"shape_container.hpp"

shape_container::shape_container():
  shapes_(0)
  {}

shape_container::shape_container(shape_container const& a):
  shapes_(a.shapes_)
  {
	std::for_each(shapes_.begin(),shapes_.end(),std::mem_fun(&shape::ref));
  }

shape_container::shape_container(std::list<shape*> l):
  shapes_(l)
  {
	std::for_each(shapes_.begin(),shapes_.end(),std::mem_fun(&shape::ref));
  }

void shape_container::add_shape(shape* c)
  {
	shapes_.push_back(c);
	c->ref();
  }

void shape_container::remove_shape(shape* s)
  {
	for(std::list<shape*>::iterator i=shapes_.begin();i!=shapes_.end();++i)
	{
		if(*i==s)
		{
			(*i)->unref();
			i=shapes_.erase(i);
		}
	}

  }

void shape_container::remove_shape(std::string s)
  {
	for(std::list<shape*>::iterator i=shapes_.begin();i!=shapes_.end();++i)
	{
		if((*i)->get_name()==s)
		{
			(*i)->unref();
			i=shapes_.erase(i);
		}
	}
	if(shapes_.back()->get_name()==s)
	{		
		shapes_.back()->unref();
		shapes_.pop_back();
	}
  }

void shape_container::remove_shape(color c)
  {
	for(std::list<shape*>::iterator i=shapes_.begin();i!=shapes_.end();++i)
	{
		if((*i)->get_color()==c)
		{
			(*i)->unref();
			i=shapes_.erase(i);
		}
	}
	if(shapes_.back()->get_color()==c)
	{		
		shapes_.back()->unref();
		shapes_.pop_back();
	}
  }

void shape_container::remove_shape_v(double c)
  {
	for(std::list<shape*>::iterator i=shapes_.begin();i!=shapes_.end();++i)
	{
		if((*i)->volume()==c)
		{
			(*i)->unref();
			i=shapes_.erase(i);
		}
	}
	if(shapes_.back()->volume()==c)
	{		
		shapes_.back()->unref();	
		shapes_.pop_back();
	}
  }


void shape_container::remove_shape_s(double c)
  {
	for(std::list<shape*>::iterator i=shapes_.begin();i!=shapes_.end();++i)
	{
		if((*i)->surface()==c)
		{
			(*i)->unref();
			i=shapes_.erase(i);
		}
	}
	if(shapes_.back()->surface()==c)
	{
		shapes_.back()->unref();	
		shapes_.pop_back();
	}
  }

double hilf(double x ,shape* c)
  {
	return (x+c->volume());
  }
	
double shape_container::volumina()
  {
	double init=0;
	return	accumulate(shapes_.begin(),shapes_.end(),init,hilf);

  }

void shape_container::print()
  {
	std::for_each(shapes_.begin(),shapes_.end(),std::bind2nd(std::mem_fun(&shape::print_on),std::cout));
  }


shape_container shape_container::clone_deep()
  {
		shape_container a;
	
		for(std::list<shape*>::iterator i=shapes_.begin();i!=shapes_.end();++i)
			{
				shape* x= (*i)->clone();
				a.add_shape(x);		
			}
  	return a;
  }

shape_container shape_container::clone_shallow()
  {
	return shape_container(*this);
  }

shape_container& shape_container::operator=(shape_container const& b)
  {
	for_each(shapes_.begin(),shapes_.end(),std::mem_fun(&shape::unref));
	shapes_=b.shapes_;
	for_each(shapes_.begin(),shapes_.end(),std::mem_fun(&shape::ref));
  	return (*this);
	
  }
