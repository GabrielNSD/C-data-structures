#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

struct arraylist
{
    int *vetor;
    int qtdade;
    int capacidade;
};

struct arraylist *inicializarAL(int capacidade)
{
    struct arraylist *lista = (struct arraylist *)malloc(sizeof(struct arraylist));
    lista->vetor = (int *)calloc(capacidade, sizeof(int));
    lista->qtdade = 0;
    lista->capacidade = capacidade;
    return lista;
}

void duplicarCapacidade(struct arraylist *lista)
{
    lista->vetor = (int *)realloc(lista->vetor, 2 * lista->capacidade * sizeof(int));
    lista->capacidade = 2 * lista->capacidade;
}

void inserirElementoNoFim(struct arraylist *lista, int valor)
{
    if (lista->qtdade == lista->capacidade)
    {
        duplicarCapacidade(lista);
    }
    lista->vetor[lista->qtdade] = valor;
    lista->qtdade++;
}

int obterElementoEmPosicao(struct arraylist *lista, int posicao)
{
    if (posicao >= 0 && posicao < lista->qtdade)
    {
        return lista->vetor[posicao];
    }
    else
    {
        return 0;
    }
}

void inverterArrayList(struct arraylist *lista)
{
    //TODO

    //inverte um struct arraylist* in-place
    //in-place significa que n�o poder� ser usado
    //nenhum array ou lista adicional, al�m do original
    int temp;
    int parada = (lista->qtdade) / 2;

    for (int i = 0; i < parada; i++)
    {
        temp = lista->vetor[i];
        lista->vetor[i] = lista->vetor[(lista->qtdade) - 1 - i];
        lista->vetor[(lista->qtdade) - 1 - i] = temp;
    }
}

struct no
{
    struct no *ant;
    int val;
    struct no *prox;
};

struct doublylinkedlist
{
    struct no *cabeca;
    struct no *cauda;
    int qtdade;
};

struct doublylinkedlist *inicializarDLL()
{
    struct doublylinkedlist *lista = (struct doublylinkedlist *)malloc(sizeof(struct doublylinkedlist));
    lista->cabeca = NULL;
    lista->cauda = NULL;
    lista->qtdade = 0;
    return lista;
}

struct no *alocarNovoNo(int valor)
{
    struct no *novoNo;
    novoNo = (struct no *)malloc(sizeof(struct no));
    novoNo->val = valor;
    novoNo->ant = NULL;
    novoNo->prox = NULL;
    return novoNo;
}

void inserirElementoNoFim(struct doublylinkedlist *lista, int valor)
{
    //aloca espa�o na mem�ria e popula novoNo
    struct no *novoNo = alocarNovoNo(valor);

    if (lista->cabeca == NULL)
    {
        //quando a lista � vazia, basta apontar o cabeca e cauda para o novoNo
        lista->cabeca = novoNo;
    }
    else
    {
        //atualizamos o ponteiro novoNo->ant para o antigo �ltimo n�
        novoNo->ant = lista->cauda;
        //ponteiro prox do antigo último nó para o novoNo
        lista->cauda->prox = novoNo;
    }
    //uma certeza: inserindo no fim, a cauda apontar� para o novoNo
    lista->cauda = novoNo;
    lista->qtdade++;
}

int obterElementoEmPosicao(struct doublylinkedlist *lista, int posicao)
{
    struct no *aux = lista->cabeca;
    for (int i = 0; i < posicao && aux->prox != NULL; i++)
    {
        aux = aux->prox;
    }
    return aux->val;
}

void inverterDoublyLinkedList(struct doublylinkedlist *lista)
{
    //TODO

    //inverte uma struct doublylinkedlist* in-place
    //in-place significa que n�o poder� ser usado
    //nenhum array ou lista adicional, al�m da original

    int temp;
    int parada = (lista->qtdade) / 2;

    struct no *head = lista->cabeca;
    struct no *tail = lista->cauda;

    for (int i = 0; i < parada; i++)
    {
        temp = head->val;
        head->val = tail->val;
        tail->val = temp;
        head = head->prox;
        tail = tail->ant;
    }
}

/* funcoes adicionais*/

int buscaBinaria(int *vetor, int ini, int fim, int valor)
{
    int tam = fim - ini + 1;

    if (tam >= 1)
    {
        int meio = ceil((fim + ini) / 2.0);

        if (vetor[meio] == valor)
        {
            return meio;
        }
        else if (valor < vetor[meio])
        {
            fim = meio - 1;
        }
        else
        {
            ini = meio + 1;
        }
        //tam = fim - ini + 1;
        return buscaBinaria(vetor, ini, fim, valor);
    }
    return -1;
}

//int indiceAnterior()

void inserirElementoEmPosicao(struct arraylist *lista, int valor, int posicao)
{
    if (posicao >= 0 && posicao < lista->capacidade)
    {
        if (lista->qtdade == lista->capacidade)
        {
            duplicarCapacidade(lista);
        }
        for (int i = lista->qtdade; i > posicao; i--)
        {
            lista->vetor[i] = lista->vetor[i - 1];
        }
        lista->vetor[posicao] = valor;
        lista->qtdade++;
    }
}

void exibirLista(struct arraylist *lista)
{
    printf("[");
    for (int i = 0; i < lista->qtdade; i++)
    {
        printf("%d", lista->vetor[i]);
        if (i < lista->qtdade - 1)
        {
            printf(", ");
        }
    }
    printf("]");
}

/**/

void insereOrdenado(struct arraylist *lista, int val)
{
    //TODO

    //deve usar o algoritmo de busca binaria para encontrar o indice
    int index;
    int checkVal = val;

    index = buscaBinaria(lista->vetor, 0, lista->qtdade, val);
    //printf("index: %d \n", index);

    //dps, abre espaco no array, e insere no local encontrado

    //checar se há elemento menor na lista
    if (checkVal > 0 && index == -1)
    {
        checkVal = checkVal - 1;
        //printf("check: %d \n", checkVal);
        index = buscaBinaria(lista->vetor, 0, lista->qtdade, checkVal);
    }
    //printf("index1: %d \n", index);

    //caso nao haja elemento menor na lista
    if (index == -1)
    {
        inserirElementoEmPosicao(lista, val, 0);
    }
    inserirElementoEmPosicao(lista, val, index+1);
}