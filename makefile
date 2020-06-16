Run : main.o processPop.o
	g++ -std=c++11 main.o processPop.o -o Run

Test : testIt.o processPop.o
	g++ -std=c++11 testIt.o processPop.o -lgmock -lgtest -lgtest_main -pthread -o Test

main.o : main.cpp processPop.h
	g++ -std=c++11 -c main.cpp

processPop.o : processPop.cpp processPop.h
	g++ -std=c++11 -c processPop.cpp
	
testIt.o : testIt.cpp processPop.h
	g++ -std=c++11 -c testIt.cpp

clean :
	rm Test Run processPop.o testIt.o main.o
