


CC=g++

main : main.o heap.o
	g++ main.o heap.o -o main
	
main.o : main.cpp
	g++ -c main.cpp
	
heap.o : heap.h heap.cpp 
	g++ -c heap.cpp
	
clean:
	rm *.o main