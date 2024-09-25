#include "ordenacao.h"
#include <string.h>

void getNome(char nome[]) {
    // substitua por seu nome
    strncpy(nome, "Vitor Faria Medeiros da Silveira", MAX_CHAR);
    // adicionada terminação manual para caso de overflow
    nome[MAX_CHAR - 1] = '\0';
}

void getNomeAlgoritmoExtra(char nomeAlg[]) {
    // substitua pelo nome do algoritmo que você escolheu
    strncpy(nomeAlg, "TimSort", MAX_CHAR);
    nomeAlg[MAX_CHAR - 1] = '\0';
}

// a função a seguir deve retornar o seu número de GRR
unsigned int getGRR() { 
	return 20232342; 
}

unsigned long mergeSort(int vetor[], int tam) {
	long custo = 0;
    if (tam <=1)
		return 0;

    int m = tam / 2;
// chamando recursivamente o merge para as duas metades do vetor
    custo += mergeSort(vetor, m);
    custo += mergeSort(vetor+m, tam-m);
    custo += merge(vetor, 0, m-1, tam-1);

    return custo;
}

unsigned long quickSort(int vetor[], int tam) {
    long numComparacoes = 0;
	if (tam <= 1)
        return numComparacoes;

    int m = particiona(vetor, 0, tam-1, &numComparacoes);
// chamando recursivamente o quickSort para as partes divididas pelo pivot do vetor
    numComparacoes += quickSort(vetor, m);
    numComparacoes += quickSort(vetor+m+1, tam-m-1);
    return numComparacoes;
}

unsigned long heapSort(int vetor[], int tam) {
	long numComparacoes = 0;
    numComparacoes += build_max_heap(vetor,tam);
// loop principal do heapsort, com trocas e max heapify
	for (int i = tam; i > 1; i--) {
		troca(&vetor[0], &vetor[i-1]);
		tam--;
		numComparacoes += max_heapify(vetor, 0, tam);
	}

	return numComparacoes;
}

void countingSort(unsigned int vetor[], int tam, int maxVal) {
// vetores de contagem e auxiliar para counting sort
    int* c = (int*) malloc((maxVal+1)*sizeof(int));
	int* aux = (int*) malloc(tam*sizeof(int));
	
	for (int i = 0; i < maxVal+1; i++)
		c[i] = 0;

	for (int i = 0; i < tam; i++)
		c[vetor[i]]++;

	for (int i = 1; i <= maxVal; i++)
		c[i] += c[i-1];

	for (int i = tam-1; i >= 0; i--) {
		aux[c[vetor[i]] - 1] = vetor[i];
		c[vetor[i]]--;
	}

// passando o vetor auxiliar para o vetor de parâmetro
	for (int i = 0; i < tam; i++)
		vetor[i] = aux[i];

	free(c);
	free(aux);
}

unsigned long algoritmoExtra(int vetor[], int tam) {
// constante RUN delimita o tamanho dos blocos a serem ordenados
	const int RUN = 32;
	long numComparacoes = 0;

// aplicacao do insertion sort em blocos de tamanho RUN
	for (int i = 0; i <= tam; i += RUN) {
        numComparacoes += TIM_insertionSort(vetor, i, (i + RUN - 1) < (tam - 1) ? (i + RUN - 1) : (tam - 1));
    }
	
// loops para encontrar os coeficientes esq, m e dir, e depois mesclagem dos blocos com o merge do MergeSort
    for (int size = RUN; size <= tam; size = 2 * size) {
        for (int esq = 0; esq <= tam; esq += 2 * size) {
            int m = esq + size - 1;
            int dir = (esq + 2 * size - 1) < (tam - 1) ? (esq + 2 * size - 1) : (tam - 1);

            if (m <= dir) {
                numComparacoes += merge(vetor, esq, m, dir);
            }
        }
    }
    
	return numComparacoes;
}

unsigned long merge(int vetor[], int a, int m, int b) {
	long custo = 0;
    int* aux = (int*) malloc((b+1)* sizeof(int));
    int j = a+m+1;
    int i = 0;
    int l = 0;
// passando para um vetor auxiliar as partes do merge ordenadas
    while (l < b+1){
        if ( (j > b) || (i <=m && (vetor[i] < vetor[j]))){
            aux[l] = vetor[i];
            i++;
        }
        else{
            aux[l] = vetor[j];
            j++;
        }
        l++;
        custo++;
    }
// retornando no vetor auxiliar
	for (int k = 0; k<b-a+1; k++){
        vetor[k] = aux[k];
    }

	free(aux);
    return custo;
}

int particiona(int vetor[], int a, int b, long* numComparacoes) {
// funcao particiona utilizando o ultimo elemento do vetor passado como pivot
    int x = vetor[b];
    int m = a;

    for (int i = a; i < b; i++){
        if (vetor[i] <= x){
            troca(&vetor[m], &vetor[i]);
            m++;
        }
        (*numComparacoes)++;
    }

    troca(&vetor[m], &vetor[b]);
    return m;
}

unsigned long max_heapify(int v[], int i, int n){
	long numComparacoes = 0;
    int maior = i;
// filhos da esquerda e direita, somados com constante por causa da primeira posicao em C ser 0.
    int l = (i*2) + 1;
    int r = (i*2) + 2;

    if (l < n && v[l] > v[i]){
		numComparacoes += 2;
        maior = l;
	}

    if (r < n && v[r] > v[maior]){
		numComparacoes += 2;
        maior = r;
	}

// considerando que os 2 if's de cima sejam negados na primeira comparacao, num recebe +2
	numComparacoes += 2;

    if (maior != i){
        troca(&v[i], &v[maior]);
		// recursao
        numComparacoes += max_heapify(v, maior, n);
    }

	return numComparacoes;
}

void troca(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

unsigned long build_max_heap(int v[], int tam){
	long numComparacoes = 0;
//build max heap recursivo com uso do max heapify
    for (int i = (tam-1)/2; i>= 0; i--){
        numComparacoes += max_heapify(v, i, tam);
	}

	return numComparacoes;
}

unsigned long TIM_insertionSort(int vetor[], int a, int b){
// insertionSort simples para uso no TimSort
	long numComparacoes = 0;
    for (int i = a + 1; i <= b; i++) {
        int key = vetor[i];
        int j = i - 1;

        while (j >= a && vetor[j] > key) {
            vetor[j + 1] = vetor[j];
            j--;
			numComparacoes += 2;
        }
		numComparacoes++;

        vetor[j + 1] = key;
    }

	return numComparacoes;
}

