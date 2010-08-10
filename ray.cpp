
ray::ray():
  origin_(0,0,0,1),
  direction_(0,0,1,0)

	{}

ray::ray(point o,vector d):
  origin_(o),
  direction_(d)

{
	double laenge_dir = sqrt(pow(direction_[0],2)+pow(direction_[1],2)+pow(direction_[2],2));
	
	if(laenge_dir!=1)
	{
		direction_ = direction_/laenge_dir;

	}
}


