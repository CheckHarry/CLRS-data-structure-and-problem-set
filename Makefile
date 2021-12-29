


CC=g++

main : main.o heap.h
	g++ -o main main.o heap.h
	
main.o : main.cpp
	g++ -c main.cpp


clean:
	rm *.o main