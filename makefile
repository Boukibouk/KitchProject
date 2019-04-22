clean:
	rm -rf *.o

compile:  
	g++ -c Source/Map/Map.cpp -c Source/Test/main.cpp -I Include/

all: clean compile
