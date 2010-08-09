#include"shape.hpp"
#include"point3d.hpp"

class sphere : public shape{

	public:
		sphere(void);
		sphere(point3d,double,color,std::string);
		sphere(sphere const&);
		~sphere(void);


		double volume() const;
		double surface() const;
		bool is_inside(point3d const&) const;
		void print_on(std::ostream&) const;
		shape* clone();


	private:
		point3d m_;
		double r_;
};

std::ostream& operator<<(std::ostream& stream, sphere obj);

