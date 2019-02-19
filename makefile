all: createCPPEnv clean

createCPPEnv: createCPPEnvMain.o createCPPEnv.o
	g++ -o createCPPEnv createCPPEnvMain.o createCPPEnv.o

createCPPEnvMain.o: createCPPEnvMain.cpp
	g++ -c createCPPEnvMain.cpp

createCPPEnv.o: createCPPEnv.cpp
	g++ -c createCPPEnv.cpp

clean:
	rm -f *.o
