#include <stdio.h>
#include <stdlib.h>

void em_ordem(Vertice *raiz){
    if(raiz==NULL){
        return;
    }
    em_ordem(raiz->esq);
    printf("%d",raiz->valor);
    em_ordem(raiz->dir);
}