parametrosCompilacao=-Wall #-Wshadow
nomePrograma=trab2grr20232342

all: $(nomePrograma)

$(nomePrograma): ordenacao.o main.o teste.o
	gcc -o $(nomePrograma) ordenacao.o main.o teste.o $(parametrosCompilacao)


mainTeste.o: main.c
	gcc -c main.c $(parametrosCompilacao)

teste.o: teste.h teste.c
	gcc -c teste.c $(parametrosCompilacao)

ordenacao.o: ordenacao.h ordenacao.c
	gcc -c ordenacao.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
