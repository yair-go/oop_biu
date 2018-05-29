a.out: mystring.o linestring.o texteditor.o main.o
	g++ -g mystring.o linestring.o texteditor.o main.o
main.o: main.cpp texteditor.h
	g++ -c -g main.cpp
mystring.o: mystring.cpp mystring.h
	g++ -c -g mystring.cpp
linestring.o: linestring.cpp linestring.h
	g++ -c -g linestring.cpp
texteditor.o: texteditor.cpp texteditor.h
	g++ -c -g texteditor.cpp
