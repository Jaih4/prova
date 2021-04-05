/*
mplemente um programa que possua a função “primos_no_inicio”, essa função deve receber uma lista ligada simples e percorrê-la, caso encontre um número primo a função
deve move-lo para o início da lista. Ao fim da execução da função, todos os números primos da lista devem estar nas primeiras posições da mesma. Na sua função principal leia N números
 do usuário e utilizando a função “primos_no_inicio”, mostre a lista dos números digitados com os números primos na frente.

*/
#include <stdio.h>
#include<stdlib.h>

typedef struct lista{
	int qtd;
	struct registro *inicio;
}lista;

typedef struct registro{
	
	int valor;
	struct registro *prox;
}registro;

lista *aloca_lista(){
	lista *l;
	l = (lista*)calloc(1,sizeof(lista));
	return l;
}
registro *aloca_registro(){
	registro *novo;
	novo = (registro*)calloc(1,sizeof(registro));
	return novo;
}
void incluir_na_lista(lista *l,int numero){
	registro *novo;
	novo = aloca_registro();
	novo->valor = numero;
	if(l->inicio ==NULL){
		l->inicio = novo;
	}else{
		registro *aux;
		aux =l->inicio;
		while(aux->prox!=NULL){
			aux = aux->prox;
		}
		aux->prox = novo;
	}
}
void primos_no_inicio(lista *l){
		if(l->inicio ==NULL){
			printf("lista vazia\n");
		}else{
			registro *aux, *ant = NULL;
			aux = l->inicio;
			int divisoes, i;
			while(aux!=NULL){
				divisoes=0;
				i=1;
				for(i;i<aux->valor/2;i++){
					if(aux->valor%2==0){
						divisoes++;
					}
				}
				if(divisoes==1){
					if (ant!=NULL){
						ant->prox= aux->prox;
						aux->prox = l->inicio;
						l->inicio=aux;
					}
				}
				ant =aux;
				aux=aux->prox;
			}
		}
}
void mostrar_lista(lista *l){
	if(l->inicio == NULL){
		printf("lista vazia\n");
	}else
	{
		registro *aux;
		aux = l->inicio;
		printf("lista: ");
		while(aux!=NULL){
			printf("%d ", aux->valor);
			aux=aux->prox;
		}
		printf("\n");
	}
}

int main(int argc, char** argv)
{
	lista *l;
	l = aloca_lista();
	int N;
	printf("quantos numeros serao adicionados a lista:");
	scanf("%d", &N);
	int i, numero;
	for(i=0;i<N;i++){
		printf("Digite o numero que sera adicionado a lista:");
		scanf("%d", &numero);
		incluir_na_lista(l, numero);
	}
	primos_no_inicio(l);
	mostrar_lista(l);
	return 0;
}
