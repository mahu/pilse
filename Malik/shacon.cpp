#include <sstream>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include"shape_container.hpp"
#include"box.hpp"
#include"sphere.hpp"


int main()
{

	shape *a;
	shape_container v;

	srand(time(NULL));
	int box_nr=0;
	int kugel_nr=0;

	for(int i=0;i<4;++i)
	{
		int x=rand()%2;
		if(x==0)
		{
			++box_nr;
			std::stringstream sstr;
			std::string name ="Box ";
			std::string x;
			sstr << box_nr;
			sstr >> x;
			name=name.append(x);
			box* b=new box(point3d((rand()%10),(rand()%20)+11,(rand()%30)+21),point3d((rand()%30)+21,(rand()%10),(rand()%20)+11),color(i*10+i,i*11,i*i),name);
			a=b;
		}
	
		if(x==1)
		{
			++kugel_nr;
			std::stringstream sstr;
			std::string name ="Kugel ";
			std::string x;
			sstr << kugel_nr;
			sstr >> x;
			name=name.append(x);
			sphere* b=new sphere(point3d((rand()%10),(rand()%10),(rand()%10)),rand()%10,color(i*10+i,i*11,i*i),name);
			a=b;
		}

		v.add_shape(a);
	}

	v.print();
	std::cout<<"Volumen: "<<v.volumina()<<std::endl;
return 0;
	
}
