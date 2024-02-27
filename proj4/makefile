output: bst.x

proj4.x: driver.o
	g++ -std=c++11 driver.o -o bst.x

driver.o: driver.cpp bst.hpp
	g++ -c -std=c++11 driver.cpp

.PHONY: clean
clean:
	rm -f *.o *.gch bst.x
