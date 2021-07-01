
#include <stdio.h>
#include <stdlib.h>

struct arraylist
{
    int *vetor;
    int qtdade;
    int capacidade;
};

struct arraylist *inicializar(int capacidade)
{
    struct arraylist *lista = (struct arraylist *)malloc(sizeof(struct arraylist));
    lista->vetor = (int *)calloc(capacidade, sizeof(int));
    lista->qtdade = 0;
    lista->capacidade = capacidade;
    return lista;
}

int obterElementoEmPosicao(struct arraylist *lista, int posicao)
{
    //TODO
    //cuidado com casos em que a posição não está contida no array
    return lista->vetor[posicao];
}

void duplicarCapacidade(struct arraylist *lista)
{
    //TODO
    lista->vetor = (int *)realloc(lista->vetor, 2 * sizeof(lista->vetor) * sizeof(int));
}

void inserirElementoNoFim(struct arraylist *lista, int valor)
{
    if (lista->qtdade == sizeof(lista->capacidade))
    {
        printf("%d ei!", lista->qtdade);
        duplicarCapacidade(lista);
    }
    lista->vetor[lista->qtdade] = valor;
    lista->qtdade++;
}

void inserirElementoEmPosicao(struct arraylist *lista, int valor, int posicao)
{
    //TODO
    return;
}

void atualizarElemento(struct arraylist *lista, int valor, int posicao)
{
    //TODO
    return;
}

void removerElementoNoFim(struct arraylist *lista)
{
    //TODO
    return;
}

void removerElementoEmPosicao(struct arraylist *lista, int posicao)
{
    //TODO
    return;
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