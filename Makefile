main: fileclass.o main.o
	g++ -o fileclass main.o fileclass.o

fileclass.o: fileclass.cpp fileclass.h
	g++ -c fileclass.cpp

main.o: main.cpp fileclass.h
	g++ -c main.cpp

