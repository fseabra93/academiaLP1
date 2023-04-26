all: 
	g++ -c main.cpp aluno.cpp instrutor.cpp
	g++ -o programa01 main.o aluno.o instrutor.o

rodar:
	./programa01

limpar:
	rm -f programa01 *.o 