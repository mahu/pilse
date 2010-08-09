#include"color.hpp"
#include<iostream>

color::color(void):
r_(255),
g_(255),
b_(255)
{}

color::color(short r, short g, short b):
r_(r),
b_(b),
g_(g)
{}

color::color(color const& c):
r_(c.r_),
g_(c.g_),
b_(c.b_)
{}

void color::invert()
{
	r_=255-r_;
	g_=255-g_;
	b_=255-b_;
}

bool operator<(color a, color b)
{
	int a_wert=((a.r_*1000000)+(a.g_*1000)+a.b_);
	int b_wert=((b.r_*1000000)+(b.g_*1000)+b.b_);
	return (a_wert<b_wert);
}

bool operator>(color a, color b)
{
	int a_wert=((a.r_*1000000)+(a.g_*1000)+a.b_);
	int b_wert=((b.r_*1000000)+(b.g_*1000)+b.b_);
return (a_wert>b_wert);
}

bool operator==(color a, color b)
{
	int a_wert=((a.r_*1000000)+(a.g_*1000)+a.b_);
	int b_wert=((b.r_*1000000)+(b.g_*1000)+b.b_);
return (a_wert==b_wert);
}

