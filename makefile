pagrindine:
	g++ -std=c++11 -c main.cpp
funkcijos:
	g++ -std=c++11 -c funkcijos.cpp
prog:
	g++ -std=c++11 -o prog main.o funkcijos.o
