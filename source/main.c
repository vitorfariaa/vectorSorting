#include "ordenacao.h"
#include "teste.h"

int main(){
// seed para a funcao rand() para preencher os vetores
	srand(time(NULL));
// clock para contar o tempo de cada algoritmo
    clock_t start, end;

    int tam;
    printf("Insira o tamanho maximo dos vetores (int): \n");
    scanf("%d", &tam);

    int max;
    printf("Insira o tamanho maximo dos elementos (int): \n");
    scanf("%d", &max);

    printf("Serao gerados 4 copias de um vetor para efetivar o MergeSort, QuickSort, InsertionSort e SelectionSort\n");

    int *vMerge;
    long nCompMerge = 0;
    double tempoMerge;

    int *vQuick;
    long nCompQuick = 0;
    double tempoQuick;

    int *vHeap;
    long nCompHeap = 0;
    double tempoHeap;

	unsigned int *vCount;
    double tempoCount;

	int *vTim;
	long nCompTim = 0;
	double tempoTim;

// duas funcoes de criar vetores separadas pelo comentario, para poder testar uma de cada vez. Uma cria um vetor ja ordenado e a outra um vetor aleatorio

    criaVetores(&vMerge, &vQuick, &vHeap, &vCount, &vTim, tam, max);
	//criaVetoresOrdenado(&vMerge, &vQuick, &vHeap, &vCount, &vTim, tam);

    printf("Agora os vetores serao ordenados, e os respectivos tempos de resposta/ numero de comparacoes sao: \n\n");

//efetivando os algoritmos e cronometrando com a funcao clock, e depois free nos vetores utilizados
    start = clock();
    nCompQuick = quickSort(vQuick, tam);
    end = clock();
    tempoQuick = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Tempo quickSort: %fs / num comparacoes: %li\n", tempoQuick, nCompQuick);
	free(vQuick);

    start = clock();
    nCompMerge = mergeSort(vMerge, tam);
    end = clock();
    tempoMerge = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Tempo mergeSort: %fs / num comparacoes: %li\n", tempoMerge, nCompMerge);
	free(vMerge);

    start = clock();
    nCompHeap = heapSort(vHeap, tam);
    end = clock();
    tempoHeap = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Tempo heapSort: %fs / num comparacoes: %li\n", tempoHeap, nCompHeap);
	free(vHeap);

	start = clock();
	countingSort(vCount, tam, 130000);
	end = clock();
	tempoCount = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo countingSort : %fs\n", tempoCount);
	free(vCount);

	start = clock();
    nCompTim = algoritmoExtra(vTim, tam);
    end = clock();
    tempoTim = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Tempo TimSort: %fs / num comparacoes: %li\n", tempoTim, nCompTim);
	free(vTim);

    return 0;
}
