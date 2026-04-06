#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    int valor;
    struct Celula *proximo;
} Celula;

typedef struct Pilha{
    Celula *topo;
    int qtde;
} Pilha;

Celula *criar_celula(int valor){
    Celula *nova = malloc(sizeof(Celula));
    nova->proximo = NULL;
    nova->valor = valor;
    return nova;
}

Pilha *criar_pilha(){
    Pilha *nova = malloc(sizeof(Pilha));
    nova->qtde = 0;
    nova->topo = NULL;
    return nova;
}

void empilhar(Pilha *pilha, int valor){
    Celula *nova = criar_celula(valor);
    nova->proximo = pilha->topo;
    pilha->topo = nova;
    pilha->qtde++;
}

int desempilhar(Pilha *pilha){
    if(pilha->topo == NULL){
        return 0;
    }
    int valor = pilha->topo->valor;
    Celula *end_valor = pilha->topo;

    pilha->topo = pilha->topo->proximo;
    free(end_valor);
    pilha->qtde--;
    return valor;
}

void imprimir(Pilha *pilha){
    Celula *atual = pilha->topo;
    printf("TOPO -> ");
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("<- BASE\n");
}

int main(){
    Pilha *pilha = criar_pilha();
    for(int i = 0; i < 7; i++){
        empilhar(pilha, i);
        imprimir(pilha);
    }
    for(int i = 0; i < 7; i++){
        desempilhar(pilha);
        imprimir(pilha);
    }
    return 0;
}