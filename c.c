#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

/* Funções */
No* criarNo(int valor);
No* inserir(No* raiz, int valor);
void emOrdem(No* raiz);
void liberar(No* raiz);

No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL)
        return criarNo(valor);

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}

void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        emOrdem(raiz->dir);
    }
}

void liberar(No* raiz) {
    if (raiz != NULL) {
        liberar(raiz->esq);
        liberar(raiz->dir);
        free(raiz);
    }
}

int main() {
	
    No* raiz = NULL;
    while (1){
    	int valor;
    	raiz = inserir(raiz, 10);
	    inserir(raiz, 5);
	    inserir(raiz, 15);
		printf("\nvalor que deseja adicionar:");
    	scanf("%d",&valor);
    	inserir(raiz,valor);
	    
	    emOrdem(raiz);
	}
	liberar(raiz);

    return 0;
}
