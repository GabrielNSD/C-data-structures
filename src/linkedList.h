#include <stdio.h>
#include <stdlib.h>

struct no
{
    int val;
    struct no *prox;
};


// int tamanho = 0;
// struct no *lista;

void imprimirLista(struct no **cabeca)
{
    if ((*cabeca) != NULL)
    {
        struct no *aux = (*cabeca);
        do
        {
            printf("%d\n", aux->val);
            aux = aux->prox;
        } while (aux != NULL);
    }
    else
    {
        printf("A lista está vazia!");
    }
}

void inserirElementoNoFim(struct no **cabeca, int valor, int *tamanho)
{
    //caso esteja vazia, criar novo no
    //caso nao esteja vazia, percorrer toda a lista e inserir novo nó no final

    if (tamanho == 0)
    {
    }
}

void inserirElementoNoInicio(struct no **cabeca, int valor, int *tamanho)
{
}

void inserirElementoEmPosicao(struct no **cabeca, int valor, int posicao, int *tamanho)
{
}

int obterElementoEmPosicao(struct no **cabeca, int posicao)
{
}

void removerElementoEmPosicao(struct no **cabeca, int posicao, int *tamanho)
{
}