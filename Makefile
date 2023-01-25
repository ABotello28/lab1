all: lab1

lab1: lab1.cpp
	g++ lab1.cpp -Wall -o lab1 -lglut -lGL -lGLU

clean:
	rm -f lab1
	clear
