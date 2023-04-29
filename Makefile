all: 
	g++ -c main.cpp onibus.cpp
	g++ -o programa01 main.o onibus.o

rodar:
	./programa01

limpar:
	rm -f programa01 *.o 