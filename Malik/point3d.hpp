#ifndef POINT3D_HPP
#define POINT3D_HPP
class point3d{

	public:
		point3d(void);
		point3d(double, double, double);
		point3d(point3d const&);
		~point3d();
	
		double x() const;
		double y() const;
		double z() const;
	
		void print_point(void) const;
		double& operator[](int);

	private:
		double x_;
		double y_;
		double z_;
};

#endif
