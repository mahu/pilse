#include"box.hpp"
#include"sphere.hpp"
#include"shape.hpp"
#include<iostream>
#include<list>
#include<cstdlib>
#include<ctime>
#include <sstream>


int main()
{
	std::list<shape*> li;
	shape *a;

	srand(time(NULL));
	int box_nr=0;
	int kugel_nr=0;

	for(int i=0;i<11;++i)
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
		li.push_back(a);
	}

	for(std::list<shape*>::iterator i=li.begin();i!=li.end();++i)
	{
		(*i)->print_on(std::cout);
	}

return 0;

}
