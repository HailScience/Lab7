#makefile

#Makefile
CXX = g++


queue: main.o menu.o queue.o
	${CXX} main.o menu.o queue.o -o queue

main.o: main.cpp
	${CXX} -c main.cpp

menu.o: menu.cpp menu.hpp
	${CXX} -c menu.cpp

queue.o: queue.cpp queue.hpp
	${CXX} -c queue.cpp

clean:
	rm *.o queue
