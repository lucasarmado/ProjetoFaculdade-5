#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i,aux,troca;
int numeros[10];

void temp(){
	float tempo;
	time_t t_ini, t_fim;
	int i, j;
	
	t_ini = time(NULL);
	for(i = 0; i < 50000; i++){
		for(j=0;j<50000;j++);
	}
	t_fim = time(NULL);
	tempo = difftime(t_fim, t_ini);
	
	printf("\nTempo: %f\n", tempo);
}

int main(){
	printf("\n Insira os numeros desejados: \n");
	for(i=0; i<10; i++){
		printf("\n Numero[%d] = ",i);
		scanf("%d",&numeros[i]);
	}
	
	printf("\n Ordenando os numeros");
	troca = 1;
	while(troca == 1){
		troca = 0;
		for(i=0;i<9; i++){
			if(numeros[i]>numeros[i+1]){
				troca = 1;
				aux = numeros[i];
				numeros[i] = numeros[i+1];
				numeros[i+1] = aux;
			}
		}
	}
	printf("\n ---Notas Ordenadas---");
	imprimir();
	
	temp();
	return 0;
}

void imprimir(){
	for (i=0; i<10; i++){
		printf("\n Numero[%d] = %d",i, numeros[i]);
	}
}
