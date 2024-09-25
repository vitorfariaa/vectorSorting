#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR 50

// a função getNome deve colocar o seu nome no vetor
// seu nome pode ter no máximo MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

// a função getNomeAlgoritmoExtra deve colocar o nome do algoritmo
// extra implementado no trabalho
void getNomeAlgoritmoExtra(char nomeAlg[]);

// a função a seguir deve retornar o seu número de GRR
unsigned int getGRR();

// Cada uma das funções deve ordenar o vetor passado como parâmetro

// O retorno das funções de ordenação é o número de comparações
// entre elementos do vetor

unsigned long mergeSort(int vetor[], int tam);

unsigned long quickSort(int vetor[], int tam);

unsigned long merge(int vetor[], int a, int m, int b);

int particiona(int vetor[], int a, int b, long* numComparacoes);

unsigned long heapSort(int vetor[], int tam);

unsigned long max_heapify(int v[], int i, int n);

unsigned long build_max_heap(int v[], int tam);

void troca(int* a, int* b);

void countingSort(unsigned int vetor[], int tam, int maxVal);  // maxVal é o k do algoritmo

// Na função algoritmoExtra implemente o algoritmo extra solicitado.
// Se o seu algoritmo escolhido não faz comparações, retorne -1.
unsigned long algoritmoExtra(int vetor[], int tam);

unsigned long TIM_insertionSort(int vetor[], int a, int b);


