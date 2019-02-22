all: NeuronaleAnalyse clean

NeuronaleAnalyse: NeuronaleAnalyseMain.o NeuronaleAnalyse.o
	g++ -o NeuronaleAnalyse NeuronaleAnalyseMain.o NeuronaleAnalyse.o

NeuronaleAnalyseMain.o: NeuronaleAnalyseMain.cpp
	g++ -c NeuronaleAnalyseMain.cpp

NeuronaleAnalyse.o: NeuronaleAnalyse.cpp
	g++ -c NeuronaleAnalyse.cpp

clean:
	rm -f *.o
