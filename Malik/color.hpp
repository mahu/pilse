#ifndef struct_color
#define struct_color

struct color
{
	short r_;
	short g_;
	short b_;
	color();
	color(color const&);
	color(short,short,short);
	void invert();

};

 bool operator <(color,color);
 bool operator >(color,color);
 bool operator ==(color,color);



#endif
