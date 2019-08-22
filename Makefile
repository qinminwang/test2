objects = mainTest.o
result:$(objects)
	g++ --std=c++11 -g -o result $(objects) -lpthread
mainTest.o:mainTest.cpp
	g++ --std=c++11 -g -c -I./  mainTest.cpp -lpthread
.PHONY:clean

clean:
	-rm result $(objects)
