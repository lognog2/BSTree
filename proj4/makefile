output: proj4.x

proj4.x: proj4_driver.o
	g++ -std=c++11 proj4_driver.o -o proj4.x

proj4_driver.o: proj4_driver.cpp bst.hpp
	g++ -c -std=c++11 proj4_driver.cpp

.PHONY: clean
clean:
	rm -f *.o *.gch proj4.x
