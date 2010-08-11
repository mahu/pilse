#include "scene.hpp"
#include<iostream>


scene::scene(std::string const& s)

{
	std::ifstream infile;
	std::string str;

	infile.open(s.c_str(),std::ifstream::in);
	
	while(infile.good())
	{
		std::getline(infile,str);
		std::stringstream sstr(str);
		std::string k;
		double d;
		sstr>>k;
		
		if(k[0]=='#')
			{std::cout<<"\nKommentar\n"<<std::endl;}
		else{
			if(k== "define")
			{
				sstr>>k;
				if(k=="shape")
				{
					sstr>>k;
					if(k=="box")
					{
						sstr>>k;
						std::string bname =k;

						math3d::point p1, p2;
						material a;

						sstr>>d;
						p1[math3d::point::x]=d;
						sstr>>d;
						p1[math3d::point::y]=d;
						sstr>>d;
						p1[math3d::point::z]=d;
						
						sstr>>d;
						p2[math3d::point::x]=d;
						sstr>>d;
						p2[math3d::point::y]=d;
						sstr>>d;
						p2[math3d::point::z]=d;

						sstr>>k;					
						std::string mat_name=k;
						
						for(std::list<material>::iterator i=mats.begin();i!=mats.end();++i)
						{
							if((*i).name_ == k)
							{
								a=(*i);
							}
						}
						
						shape *b = new box(p1,p2,bname,a);
						objects.push_back(b);
					}				

						else if(k=="sphere")
						{
							sstr>>k;
							std::string sname=k;
							math3d::point center;
							material a;

							sstr>>d;
							center[math3d::point::x]=d;
							sstr>>d;
							center[math3d::point::y]=d;
							sstr>>d;
							center[math3d::point::z]=d;

							sstr>>d;						
							double radius=d;
	
							sstr>>k;
							std::string mat_name=k;
								
							for(std::list<material>::iterator i=mats.begin();i!=mats.end();++i)
							{
								if((*i).name_ == k)
								{
									a=(*i);
								}
							}
				
							shape *s = new sphere(center,radius,sname,a);
							objects.push_back(s);
						}
					}
				else if(k=="light")
				{
					sstr>>k;
					std::string lname=k;
					math3d::point pos;
					
					sstr>>d;
					pos[math3d::point::x]=d;
					sstr>>d;
					pos[math3d::point::y]=d;
					sstr>>d;
					pos[math3d::point::z]=d;
					
					rgb la, ld;
					
					sstr>>d;
					la[rgb::r]=d;
					sstr>>d;
					la[rgb::g]=d;
					sstr>>d;
					la[rgb::b]=d;


					sstr>>d;
					ld[rgb::r]=d;
					sstr>>d;
					ld[rgb::g]=d;
					sstr>>d;
					ld[rgb::b]=d;


					light *s = new light(pos,lname,la,ld);
					
					lights.push_back(*s);


				}
			}

			else if(k=="camera")
			{
				sstr>>k;
				std::string cname=k;
	
				sstr>>d;			
				double fx=d;
				sstr>>d;
				double fy=d;
				
				camera *c = new camera(cname,fx,fy);
				cam.push_back(*c);
			}
			
			else if(k=="render")
			{
				sstr>>k;
				std::string camname=k;
				camera c;
				for(std::list<camera>::iterator i=cam.begin();i!=cam.end();++i)
				{
					if((*i).name_==k)
					{
						c=(*i);
					}
				}
				sstr>>k;				
				std::string filename=k;				
				
				sstr>>d;				
				int x_res=d;
				sstr>>d;				
				int y_res=d;
			}

		}
	
	}



}





