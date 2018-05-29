a.out: main.o userinterface.o invindex.o wordinfo.o instanceinfo.o
	g++ main.o userinterface.o invindex.o wordinfo.o instanceinfo.o
main.o: main.cpp userinterface.h
	g++ -c main.cpp
userinterface.o: userinterface.cpp userinterface.h
	g++ -c userinterface.cpp
invindex.o: invindex.cpp invindex.h
	g++ -c invindex.cpp
wordinfo.o: wordinfo.cpp wordinfo.h
	g++ -c wordinfo.cpp
instanceinfo.o: instanceinfo.cpp instanceinfo.h
	g++ -c instanceinfo.cpp


 
