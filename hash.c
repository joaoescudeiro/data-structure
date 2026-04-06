#include <stdio.h>
#include <stdlib.h>
#define TAM 7

typedef struct Celula{
    struct Celula *proximo;
    int valor;
} Celula;

typedef struct{
    Celula *primeira;
    int qtde;
} Lista;

typedef struct {
    int qtde;
    Lista *lista[TAM];
} Hash;

Celula *criar_celula(int valor){
    Celula *nova = malloc(sizeof(Celula));
    nova->proximo=NULL;
    nova->valor=valor;
    return nova;
}

Lista *criar_lista(){
    Lista *nova = malloc(sizeof(Lista));
    nova->primeira=NULL;
    nova->qtde=0;
    return nova;
}

Hash *criar_hash(){
    Hash *nova = malloc(sizeof(Hash));
    nova->qtde = 0;
    for(int i = 0; i < TAM; i++){
        nova->lista[i] = criar_lista();
    }
    return nova;
}

int funcao_hash(int valor){
    return valor % TAM;
}

void inserir(Hash *hash, int valor){
    int chave = funcao_hash(valor);
    Celula *nova = criar_celula(valor);
    nova->proximo = hash->lista[chave]->primeira;
    hash->lista[chave]->primeira = nova;
    hash->lista[chave]->qtde++;
    hash->qtde++;
}

void remover(Hash *hash, int valor){
    
}

void imprimir(Hash *hash){
    Celula *atual = NULL;
    for(int i = 0; i < TAM; i++){
        atual = hash->lista[i]->primeira;
        printf("Lista %d -> ", i);
        while(atual != NULL){
            printf("%d -> ", atual->valor);
            atual = atual->proximo;
        }
        printf("\n");
    }
}

int main(){
    int valores[] = {190, 322, 172, 89, 13, 4, 769, 61, 15, 76};
    int qte = sizeof(valores) / sizeof(int);
    Hash *hash = criar_hash();
    for(int i = 0; i < qte; i++){
        inserir(hash, valores[i]);
        imprimir(hash);
    }
    return 0;
}