all: 
	g++ -c main.cpp onibus.cpp gerente.cpp
	g++ -o programa01 main.o onibus.o gerente.o

rodar:
	./programa01

limpar:
	rm -f programa01 *.o 