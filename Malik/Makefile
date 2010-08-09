FLAGS = -c 
COMPILER = g++
PROGRAM= boxtest

point:
	$(COMPILER) $(FLAGS) point3d.cpp
	$(COMPILER) $(FLAGS) p3dtest.cpp
	$(COMPILER) point3d.o p3dtest.o -o p3dtest
	rm *.o

box:
	$(COMPILER) $(FLAGS) shape.cpp
	$(COMPILER) $(FLAGS) box.cpp
	$(COMPILER) $(FLAGS) color.cpp
	$(COMPILER) $(FLAGS) point3d.cpp
	$(COMPILER) $(FLAGS) boxtest.cpp
	$(COMPILER) shape.o box.o color.o point3d.o boxtest.o -o btest
	rm *.o

sphere:
	$(COMPILER) $(FLAGS) shape.cpp
	$(COMPILER) $(FLAGS) sphere.cpp
	$(COMPILER) $(FLAGS) color.cpp
	$(COMPILER) $(FLAGS) point3d.cpp	
	$(COMPILER) $(FLAGS) sphtest.cpp
	$(COMPILER) shape.o sphere.o color.o point3d.o sphtest.o -o sphtest
	rm *.o

boxsphere:
	$(COMPILER) $(FLAGS) shape.cpp
	$(COMPILER) $(FLAGS) sphere.cpp
	$(COMPILER) $(FLAGS) box.cpp
	$(COMPILER) $(FLAGS) color.cpp
	$(COMPILER) $(FLAGS) point3d.cpp
	$(COMPILER) $(FLAGS) boxkugel.cpp
	$(COMPILER) shape.o box.o sphere.o color.o point3d.o boxkugel.o -o bk
	rm *.o

sizeof:
	$(COMPILER) $(FLAGS) shape.cpp
	$(COMPILER) $(FLAGS) sphere.cpp
	$(COMPILER) $(FLAGS) box.cpp
	$(COMPILER) $(FLAGS) sifo.cpp
	$(COMPILER) $(FLAGS) color.cpp
	$(COMPILER) $(FLAGS) point3d.cpp
	$(COMPILER) shape.o box.o sphere.o color.o point3d.o sifo.o -o sifo
	rm *.o

condes:
	$(COMPILER) $(FLAGS) shape.cpp
	$(COMPILER) $(FLAGS) sphere.cpp
	$(COMPILER) $(FLAGS) color.cpp
	$(COMPILER) $(FLAGS) point3d.cpp	
	$(COMPILER) $(FLAGS) condes.cpp
	$(COMPILER) shape.o sphere.o color.o point3d.o condes.o -o condes
	rm *.o

shape_container:
	$(COMPILER) $(FLAGS) shape.cpp
	$(COMPILER) $(FLAGS) sphere.cpp
	$(COMPILER) $(FLAGS) box.cpp
	$(COMPILER) $(FLAGS) color.cpp
	$(COMPILER) $(FLAGS) point3d.cpp	
	$(COMPILER) $(FLAGS) shape_container.cpp
	$(COMPILER) $(FLAGS) shacon.cpp
	$(COMPILER) shape.o box.o sphere.o color.o shape_container.o point3d.o shacon.o -o shacon
	rm *.o

refcounter:
	$(COMPILER) $(FLAGS) shape.cpp
	$(COMPILER) $(FLAGS) sphere.cpp
	$(COMPILER) $(FLAGS) box.cpp
	$(COMPILER) $(FLAGS) color.cpp
	$(COMPILER) $(FLAGS) point3d.cpp	
	$(COMPILER) $(FLAGS) shape_container.cpp
	$(COMPILER) $(FLAGS) counter.cpp
	$(COMPILER) shape.o box.o sphere.o color.o shape_container.o point3d.o counter.o -o counter
	rm *.o

clone_deep:
	$(COMPILER) $(FLAGS) shape.cpp
	$(COMPILER) $(FLAGS) sphere.cpp
	$(COMPILER) $(FLAGS) box.cpp
	$(COMPILER) $(FLAGS) color.cpp
	$(COMPILER) $(FLAGS) point3d.cpp	
	$(COMPILER) $(FLAGS) shape_container.cpp
	$(COMPILER) $(FLAGS) clone_deep.cpp
	$(COMPILER) shape.o box.o sphere.o color.o shape_container.o point3d.o clone_deep.o -o clone_d
	rm *.o

clone_shallow:
	$(COMPILER) $(FLAGS) shape.cpp
	$(COMPILER) $(FLAGS) sphere.cpp
	$(COMPILER) $(FLAGS) box.cpp
	$(COMPILER) $(FLAGS) color.cpp
	$(COMPILER) $(FLAGS) point3d.cpp	
	$(COMPILER) $(FLAGS) shape_container.cpp
	$(COMPILER) $(FLAGS) clone_shallow.cpp
	$(COMPILER) shape.o box.o sphere.o color.o shape_container.o point3d.o clone_shallow.o -o clone_s
	rm *.o


clean:

