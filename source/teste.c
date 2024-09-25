#include "teste.h"

void criaVetores(int **vetorM, int **vetorQ, int **vetorH, unsigned int **vetorC, int **vetorT, int tam, int max){
// alocacao dinamica em todos os vetores
    *vetorM = (int *)malloc(tam*sizeof(int));
    *vetorQ = (int *)malloc(tam*sizeof(int));
    *vetorH = (int *)malloc(tam*sizeof(int));
	*vetorC = (unsigned int *)malloc(tam*sizeof(unsigned int));
	*vetorT = (int *) malloc(tam*sizeof(int));

// preencher os vetores com uma variavel obtida com a funcao rand()
    for (int i = 0; i < tam; i++){
        int k = aleat(max);
        (*vetorM)[i] = k;
        (*vetorQ)[i] = k;
        (*vetorH)[i] = k;
        (*vetorC)[i] = k;
		(*vetorT)[i] = k;
    }
}

void criaVetoresOrdenado(int **vetorM, int **vetorQ, int **vetorH, unsigned int **vetorC, int **vetorT, int tam){
    *vetorM = (int *)malloc(tam*sizeof(int));
    *vetorQ = (int *)malloc(tam*sizeof(int));
    *vetorH = (int *)malloc(tam*sizeof(int));
    *vetorC = (unsigned int *)malloc(tam*sizeof(unsigned int));
	*vetorT = (int *)malloc(tam*sizeof(int));

// para criar um vetor ordenado, preenche um vetor de i=0 ate b com o indicie i
    for (int i = 0; i < tam; i++){
        (*vetorM)[i] = i;
        (*vetorQ)[i] = i;
        (*vetorH)[i] = i;
        (*vetorC)[i] = i;
		(*vetorT)[i] = i;
    }
}

int aleat(int max){
	return (rand() % max);
}

void imprimeVetor(int vetor[], int tam){
    printf("Vetor ordenado: \n");
    for (int i = 0; i < tam; i++){
        printf("%d\n", vetor[i]);
    }
}

