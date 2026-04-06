#include <stdio.h>
#include <stdlib.h>

#define LEN 100

typedef struct {
    int valores[LEN];
    int qtde;
} Heap;


int PAI(int i) {
    return (i - 1) / 2;
}

int FILHO_ESQ(int i) {
    return 2 * i + 1;
}

int FILHO_DIR(int i) {
    return 2 * i + 2;
}

int ULTIMO_PAI(Heap *h) {
    return (h->qtde / 2) - 1;
}

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void PENEIRAR(Heap *h, int pai) {

    int esq = FILHO_ESQ(pai);
    int dir = FILHO_DIR(pai);
    int maior;

    if (esq < h->qtde && h->valores[esq] > h->valores[pai])
        maior = esq;
    else
        maior = pai;

    if (dir < h->qtde && h->valores[dir] > h->valores[maior])
        maior = dir;

    if (pai != maior) {
        trocar(&h->valores[pai], &h->valores[maior]);
        PENEIRAR(h, maior);
    }
}

void PENEIRAR_PARA_CIMA(Heap *h, int filho) {

    if (filho <= 0)
        return;

    int pai_idx = PAI(filho);

    if (h->valores[filho] > h->valores[pai_idx]) {
        trocar(&h->valores[filho], &h->valores[pai_idx]);
        PENEIRAR_PARA_CIMA(h, pai_idx);
    }
}

void CONSTRUIR(Heap *h) {

    for (int i = ULTIMO_PAI(h); i >= 0; i--) {
        PENEIRAR(h, i);
    }
}

void INSERIR(Heap *h, int valor) {

    if (h->qtde < LEN) {

        h->valores[h->qtde] = valor;

        PENEIRAR_PARA_CIMA(h, h->qtde);

        h->qtde = h->qtde + 1;
    }
}

void REMOVER(Heap *h) {

    if (h->qtde > 0) {

        trocar(&h->valores[0], &h->valores[h->qtde - 1]);

        h->qtde = h->qtde - 1;

        if (h->qtde > 0)
            PENEIRAR(h, 0);
    }
}

void imprimir(Heap *h) {
    for (int i = 0; i < h->qtde; i++)
        printf("%d ", h->valores[i]);
    printf("\n");
}

int main() {

    Heap h;
    h.qtde = 0;

    INSERIR(&h, 10);
    INSERIR(&h, 30);
    INSERIR(&h, 20);
    INSERIR(&h, 5);
    INSERIR(&h, 40);

    printf("Heap após inserções:\n");
    imprimir(&h);

    REMOVER(&h);

    printf("Heap após remover máximo:\n");
    imprimir(&h);

    return 0;
}