#include <stdio.h>
#include <stdlib.h>

// Estrutura de uma célula da lista duplamente ligada
typedef struct Celula {
	int valor;					// Valor armazenado na célula
	struct Celula *proximo;		// Ponteiro para o próximo elemento
	struct Celula *anterior;	// Ponteiro para o elemento anterior
} Celula;

// Estrutura da fila com ponteiros para início e fim
typedef struct {
	Celula *head;	// Ponteiro para o primeiro elemento (início da fila)
	Celula *tail;	// Ponteiro para o último elemento (fim da fila)
	int qtde;		// Contador de elementos na fila
} Queue;

// Cria uma nova célula com o valor especificado
Celula *cria_celula(int valor){
	Celula *nova = (Celula *)malloc(sizeof(Celula));
	nova->valor = valor;
	nova->proximo = NULL;
	nova->anterior = NULL;
	return nova;
}

// Cria uma nova fila vazia
Queue *cria_queue(){
	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->head = NULL;
	q->tail = NULL;
	q->qtde = 0;
	return q;
}

// Operação ENQUEUE: insere elemento no final da fila (FIFO)
void enqueue(Queue *queue, int valor){
	Celula *nova = cria_celula(valor);

	if(queue->tail == NULL){
		queue->head = nova;
		queue->tail = nova;
	} else {
		nova->anterior = queue->tail;
		queue->tail->proximo = nova;
		queue->tail = nova;
	}

	queue->qtde++;
}

// Operação DEQUEUE: remove elemento do início da fila (FIFO)
int dequeue(Queue *queue){
	if(queue->head == NULL){
		return -1; // fila vazia
	}

	Celula *removida = queue->head;
	int valor = removida->valor;

	queue->head = removida->proximo;

	if(queue->head != NULL){
		queue->head->anterior = NULL;
	} else {
		queue->tail = NULL;
	}

	free(removida);
	queue->qtde--;

	return valor;
}

// Exibe todos os elementos da fila (do início ao fim)
void show(Queue *queue){
	Celula *aux = queue->head;
	while(aux != NULL){
		printf("%d ", aux->valor);
		aux = aux->proximo;
	}
}

int main(void) {
	Queue *fila = cria_queue();

	int valores[] = {10, 2, 0, 4, 5, 5, 6, 2, 8, 1, 9};
	int n = sizeof(valores) / sizeof(int);

	printf("=== INSERINDO ELEMENTOS ===\n");
	for(int i = 0; i < n; i++){
		enqueue(fila, valores[i]);
		printf("Inserido %d: ", valores[i]);
		show(fila);
		printf("\n");
	}

	printf("\n=== REMOVENDO ELEMENTOS ===\n");
	while(fila->qtde > 0){
		int removido = dequeue(fila);
		printf("Valor removido: %d, Fila restante: ", removido);
		show(fila);
		printf("\n");
	}

	return 0;
}