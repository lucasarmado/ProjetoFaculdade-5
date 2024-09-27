#include <stdio.h>
#include <stdlib.h>

//BUBBLESORT

void bubbleSort(int *V , int N){
	int i, continua, aux, fim = N;
	do{
		continua = 0;
		for(i = 0; i < fim-1; i++){
			if(V[i] > V[i+1]){
				aux = V[i];
				V[i] = V[i+1];
				V[i+1] = aux;
				continua = i;
			}
		}
		fim--;
	}while(continua != 0);
}

//QUICKSORT

void quickSort(int *V, int inicio, int fim){
	int pivo;
	if(fim > inicio){
		pivo = particiona(V, inicio, fim);
		quickSort(V, inicio, pivo-1);
		quickSort(V, pivo+1, fim);
	}
}

int particiona(int *V, int inicio, int final){
	int esq, dir, pivo, aux;
	esq = inicio;
	dir = final;
	pivo = V[inicio];
	while(esq < dir){
		while(V[dir]<=pivo)
			esq++;
		while(V[dir]>pivo)
			dir--;
		if(esq < dir){
			aux = V[esq];
			V[esq] = V[dir];
			V[dir] = aux;
		}
	}
	V[inicio] = V[dir];
	V[dir] = pivo;
	return dir;
}

//INSERCTIONSORT

void insertionSort(int *V, int N){
	int i, j, aux;
	for(i = 1; i < N; i++){
		aux = V[i];
		for(j = i; (j>0) && (aux < V[j-1]); j--)
			V[j] = V[j-1];
		V[j] = aux;
	}
}

//SELECTIONSORT

void selectionSort(int *V, int N){
	int i,j, menor, troca;
	for(i = 0; i < N-1; i++){
		menor = i;
		for(j = i+1; j < N; j++){
			if(V[j] < V[menor])
				menor = j;
		}
		if(i != menor){
			troca = V[i];
			V[i] = V[menor];
			V[menor] = troca;
		}
	}
}

//HEAPSORT

void heapSort(int *vet, int N){
	int i, aux;
	for(i=(N-1)/2; i>=0; i--){
		criaHeap(vet, i, N-1);
	}
	for(i = N-1; i>=1; i--){
		aux = vet[0];
		vet[0] = vet[i];
		vet[i] = aux;
		criaHeap(vet, 0, i-1);
	}
}

//MERGESORT

void mergeSort(int *V, int inicio, int fim){
	int meio;
	if(inicio < fim){
		meio = floor((inicio+fim)/2);
		mergeSort(V,inicio,meio);
		mergeSort(V,meio+1,fim);
		merge(V,inicio,meio,fim);
	}
}

void merge(int *V, int inicio, int meio, int fim){
	int *temp, p1, p2, tamanho, i, j, k;
	int fim1 = 0, fim2 = 0;
	tamanho = fim-inicio+1;
	p1 = inicio;
	p2 = meio+1;
	temp = (int *) malloc(tamanho*sizeof(int));
	if(temp != NULL){
		for(i=0; i<tamanho; i++){
			if(!fim1 && !fim2){
				if(V[p1]<V[p2])
					temp[i]=V[p1++];
				else
					temp[i]=V[p2++];
				
				if(p1>meio) fim1=1;
				if(p2>fim) fim2=1;	
			}else{
				if(!fim1)
					temp[i]=V[p1++];
				else
					temp[i]=V[p2++];
			}
		}
		for(j=0, k=inicio; j<tamanho; j++, k++)
			V[k]=temp[j];
	}
	free(temp);
}

//BUCKETSORT

#define TAM 5 // tamanho do balde
struct balde{
	int qtd;
	int valores[TAM];
};

void bucketSort(int *V, int N){
	int i, j, maior, menor, nroBaldes, pos;
	struct balde *bd;
	//Acha maior e menor valor
	maior = menor = V[0];
	for(i = 1; i<N; i++){
		if(V[i] > maior) maior = V[i];
		if(V[i] < menor) menor = V[i];
	}
	//Inicializa baldes
	nroBaldes = (maior - menor) / TAM + 1;
	bd = (struct balde *) malloc(nroBaldes * sizeof(struct balde));
	for(i = 0; i < nroBaldes; i++)
		bd[i].qtd = 0;
	//Distribui os valores nos baldes
	for(i = 0; i < N; i++){
		pos = (V[i] - menor)/TAM;
		bd[pos].valores[bd[pos].qtd] = V[i];
		bd[pos].qtd++;
	}
	//Ordena baldes e coloca no array
	pos = 0;
	for(i = 0; i < nroBaldes; i++){
		insertionSort(bd[i].valores,bd[i].qtd);
		for(j = 0;j < bd[i].qtd; j++){
			V[pos] = bd[i].valores[j];
			pos++;
		}
	}
	free(bd);
}
