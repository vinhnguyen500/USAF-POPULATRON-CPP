Run : main.o ioParser.o population.o
	g++ -std=c++11 main.o ioParser.o population.o -o Run

Test : testIt.o ioParser.o population.o
	g++ -std=c++11 testIt.o ioParser.o population.o -lgmock -lgtest -lgtest_main -pthread -o Test
	./Test

main.o : main.cpp population.h ioParser.h
	g++ -std=c++11 -c main.cpp -v
	
testIt.o : testIt.cpp
	g++ -std=c++11 -c testIt.cpp

ioParser.o : ioParser.h ioParser.cpp
	g++ -std=c++11 -c ioParser.cpp

population.o : population.h population.cpp
	g++ -std=c++11 -c population.cpp

clean :
	rm Test Run *.o 
