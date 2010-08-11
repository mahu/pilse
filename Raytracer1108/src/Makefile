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


main:
	$(COMPILER) $(FLAGS) point.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) vector.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) shape.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) rgb.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) pixel.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) sphere.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) ray.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) main.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) glutwindow.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) camera.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) light.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) ppmwriter.cpp $(BFLAGS)
	$(COMPILER) $(FLAGS) transform.cpp $(BFLAGS)
	$(COMPILER) point.o vector.o shape.o rgb.o sphere.o ray.o pixel.o glutwindow.o camera.o light.o ppmwriter.o transform.o main.o -o main
	rm *.o
