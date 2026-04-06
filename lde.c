#include<stdio.h>
#include<stdlib.h>

typedef struct Celula{
    int valor;
    struct Celula *proximo;
}Celula;

typedef struct {
    Celula *primeira;
    int qtd;
} LDE;

Celula *criar_celula(int valor){
    Celula *novo = malloc(sizeof(Celula));
    novo->proximo = NULL;
    novo->valor = valor;
    return novo;
}

LDE *criar_lista(){
    LDE *lista = malloc(sizeof(LDE));
    lista->primeira = NULL;
    lista->qtd = 0;
    return lista;
}

void inserir(LDE *lista, int valor){
    Celula *novo = criar_celula(valor);
    Celula *anterior = NULL;
    Celula *atual = lista->primeira;
    while(atual != NULL && atual->valor < valor){
        anterior = atual;
        atual = atual->proximo;
    }
    if(anterior == NULL){
        novo->proximo = lista->primeira;
        lista->primeira = novo;
    }else{
        anterior->proximo = novo;
        novo->proximo = atual;
    }
    lista->qtd++;
}

void remover(LDE *lista, int valor){
    Celula *anterior = NULL;
    Celula *atual = lista->primeira;
    while(atual != NULL && atual->valor != valor){
        anterior = atual;
        atual = atual->proximo;
    }
    if(atual==NULL) return;
    if(anterior==NULL){
        lista->primeira = atual->proximo;
    }else{
        anterior->proximo=atual->proximo;
    }
    free(atual);
    lista->qtd--;
}

void imprimir(LDE *lista){
    Celula *atual = lista->primeira;
    while(atual!=NULL){
        printf("%d ",atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main(){
    LDE *lista = criar_lista();
    inserir(lista, 9);
    imprimir(lista);
    inserir(lista, 2);
    imprimir(lista);
    inserir(lista, 12);
    imprimir(lista);

    remover(lista, 2);
    imprimir(lista);
    remover(lista, 8);
    imprimir(lista);
    remover(lista, 12);
    imprimir(lista);
    remover(lista, 9);
    imprimir(lista);
    return 0;
}