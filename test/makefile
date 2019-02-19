all: test clean

test: testMain.o test.o
	g++ -o test testMain.o test.o

testMain.o: testMain.cpp
	g++ -c testMain.cpp

test.o: test.cpp
	g++ -c test.cpp

clean:
	rm -f *.o
