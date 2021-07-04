#include <stdlib.h>
#include <stdio.h>

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

struct doublylinkedlist *inicializar()
{
    struct doublylinkedlist *lista = (struct doublylinkedlist *)malloc(sizeof(struct doublylinkedlist));
    lista->cabeca = NULL;
    lista->cauda = NULL;
    lista->qtdade = 0;
    return lista;
}

struct no *alocarNovoNo(int valor)
{
    struct no *novoNo = (struct no *)malloc(sizeof(struct no));
    novoNo->val = valor;
    novoNo->ant = NULL;
    novoNo->prox = NULL;
    return novoNo;
}

void inserirElementoNoInicio(struct doublylinkedlist *lista, int valor)
{
    struct no *novoNo = alocarNovoNo(valor);
    novoNo->prox = lista->cabeca;
    lista->cabeca = novoNo;
    if (lista->qtdade == 0)
    {
        lista->cauda = novoNo;
    }
    lista->qtdade++;
}

void inserirElementoNoFim(struct doublylinkedlist *lista, int valor)
{
    if (lista->cabeca == NULL)
    {
        inserirElementoNoInicio(lista, valor);
    }
    else
    {
        struct no *aux = lista->cauda;
        struct no *novoNo = alocarNovoNo(valor);
        aux->prox = novoNo;
        novoNo->ant = aux;
        lista->cauda = novoNo;
        lista->qtdade++;
    }
}

void inserirElementoEmPosicao(struct doublylinkedlist *lista, int valor, int posicao)
{
    if (posicao == 0)
    {
        inserirElementoNoInicio(lista, valor);
    }
    else if (posicao == lista->qtdade)
    {
        inserirElementoNoFim(lista, valor);
    }
    else
    {
        struct no *novoNo = alocarNovoNo(valor);
        struct no *aux = lista->cabeca;
        for (int i = 0; i < posicao - 1; i++)
        {
            aux = aux->prox;
        }
        novoNo->prox = aux->prox;
        aux->prox = novoNo;
        novoNo->ant = aux;
        lista->qtdade++;
    }
}

int obterElementoEmPosicao(struct doublylinkedlist *lista, int posicao)
{
    struct no *aux = lista->cabeca;
    if (posicao == lista->qtdade)
    {
        aux = lista->cauda;
    }
    else
    {
        for (int i = 0; i < posicao; i++)
        {
            aux = aux->prox;
        };
    }
    return aux->val;
}

void removerElementoEmPosicao(struct doublylinkedlist *lista, int posicao)
{
    if (lista->qtdade == 1)
    {
        lista->cabeca = NULL;
        lista->cauda = NULL;
    }
    else if (posicao == 0)
    {
        lista->cabeca = lista->cabeca->prox;
    }
    else if (posicao == lista->qtdade)
    {
        struct no *aux = lista->cauda;
        lista->cauda = aux->ant;
    }
    //possivel percorrer do fim para o comeco, se posicao for mais proxima do fim
    else
    {
        struct no *aux = lista->cabeca;
        for (int i = 0; i < posicao - 1; i++)
        {
            aux = aux->prox;
        }
        struct no *temp = aux->prox;

        aux->prox = temp->prox;
        aux->ant = aux;

        free(temp);
    }
    lista->qtdade--;
}

void imprimirLista(struct doublylinkedlist *lista)
{
    //usamos o aux para percorrer a lista
    if (lista->cabeca != NULL)
    {
        struct no *aux = lista->cabeca;
        //navega partindo da cabeça até chegar NULL
        printf("[");
        do
        {
            printf("%d", aux->val);
            aux = aux->prox;
            if (aux != NULL)
            {
                printf(", ");
            }
        } while (aux != NULL);
        printf("]");
    }
    else
    {
        printf("A lista está vazia!");
    }
}