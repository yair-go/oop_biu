a.out: main.o admin.o card.o commpany.o date.o manager.o technian.o worker.o util.o
	g++ main.o admin.o card.o commpany.o date.o manager.o technian.o worker.o util.o
main.o: main.cpp commpany.h date.h
	g++ -c main.cpp
admin.o: admin.cpp worker.h
	g++ -c admin.cpp
card.o: card.cpp card.h date.h
	g++ -c card.cpp
commpany.o: commpany.cpp commpany.h worker.h
	g++ -c commpany.cpp
date.o: date.cpp date.h
	g++ -c date.cpp
manager.o: manager.cpp worker.h
	g++ -c manager.cpp
technian.o: technian.cpp worker.h
	g++ -c technian.cpp
worker.o: worker.cpp worker.h
	g++ -c worker.cpp
util.o: util.cpp util.h
	g++ -c util.cpp
