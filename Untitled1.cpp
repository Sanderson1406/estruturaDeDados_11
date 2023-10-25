//programa que implementa um grafo

#include <stdio.h>

//definição de copnstantes

const int TAMANHO = 5;

//funcão que define o grafo

void criar(int grafo[TAMANHO][TAMANHO]) {
	//declaração de variaveis
	int i = 0;
	int j = 0;
	int amigo = 0;
	
	//inicialização do grafo
	for (i = 0; i < TAMANHO; i++) {
		for (j = 0; j < TAMANHO; j++) {
			grafo[i][j] = 0;
		}
	}
	
	//definição das conecções do grafo
	for (i = 0; i < TAMANHO - 1; i++) {
		for (j = (i + 1); j < TAMANHO; j++) {
			printf("Digite <1> caso %d seja amigo de %d: ", i, j);
			scanf("%d", &amigo);
			grafo[i][j] = amigo;
			grafo[j][i] = amigo;
		}
	}
	
}

//função que imprime o grafo

void imprimir(int grafo[TAMANHO][TAMANHO]) {
	//declaração de variaveis
	int i = 0;
	int j = 0;
	
	//impreção propriamnete dita
	for (i = 0; i < TAMANHO; i++) {
		for (j = 0; j < TAMANHO; j++) {
			printf("%d\t", grafo[i][j]);
		}
		printf("%\n");
	}
}

//função que descobre o vertice de maior grau

int descobrirVerticeMaiorGrau(int grafo[TAMANHO][TAMANHO]) {
	int i = 0;
	int j = 0;
	int contador = 0;
	int maior = 0;
	int vertice = 0;
	
	//navegação do grafo
	for (i = 0; i < TAMANHO; i++) {
		contador = 0;
		for (j = 0; j < TAMANHO; j++) {
			if (grafo[i][j]) {
				contador++;
			}
		}
		if (contador > maior) {
			maior = contador;
			vertice = i;
		}
	}
	
	return vertice;
}

//função de execução de programa

int main() {
	int grafo[TAMANHO][TAMANHO];
	criar(grafo);
	imprimir(grafo);
	printf("Vertice mais popular: %d\n", descobrirVerticeMaiorGrau(grafo));
}
