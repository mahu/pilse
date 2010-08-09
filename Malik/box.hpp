#ifndef BOX_HPP_
#define BOX_HPP_
#include"shape.hpp"
#include"point3d.hpp"
#include"string"
#include"color.hpp"

class box : public shape
{

	public:
		box(void);
		box(point3d,point3d,color,std::string);
		box(box const&);
		~box(void);

		void print_on(std::ostream&) const;
		double volume() const;
		double surface() const;
		double laenge(point3d const&,point3d const&) const;
		bool is_inside(point3d const&)const;
		shape* clone();

	private:
		point3d a_;
		point3d b_;
		//point3d c_;
		point3d d_;
		point3d e_;
		//point3d f_;
		//point3d g_;
		point3d h_;
	//	std::string name_;
	//	color clr_;



};

std::ostream& operator<<(std::ostream& stream, box obj);
#endif
