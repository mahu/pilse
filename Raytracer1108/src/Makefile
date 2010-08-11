FLAGS = -c 
COMPILER = g++
BFLAGS = -I ../include

default:
	$(COMPILER) $(FLAGS) point.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) vector.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) shape.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) rgb.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) pixel.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) sphere.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) ray.cpp $(BFLAGS)
	rm *.o

intersect:
	$(COMPILER) $(FLAGS) point.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) vector.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) shape.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) rgb.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) sphere.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) ray.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) intersecttest.cpp $(BFLAGS)
	$(COMPILER) point.o vector.o shape.o rgb.o sphere.o ray.o intersecttest.o -o intersect 
	rm *.o

