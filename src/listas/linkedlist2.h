#include <stdio.h>
#include <stdlib.h>

struct no
{
    int val;
    struct no *prox;
};

struct linkedlist
{
    struct no *cabeca;
    int qtdade;
};

struct linkedlist *inicializar()
{
    //TODO
    struct linkedlist *lista = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    lista->cabeca = NULL;
    lista->qtdade = 0;
    return lista;
}

struct no *alocarNovoNo(int valor)
{
    //TODO
    struct no *novoNo = (struct no *)malloc(sizeof(struct no));
    novoNo->val = valor;
    novoNo->prox = NULL;
    return novoNo;
}

void inserirElementoNoFim(struct linkedlist *lista, int valor)
{
    //TODO
    //caso esteja vazia, criar novo no
    if (lista->cabeca == NULL)
    {
        lista->cabeca = alocarNovoNo(valor);
    }
    //caso nao esteja vazia, percorrer toda a lista e inserir novo nó no final
    else
    {
        struct no *aux = lista->cabeca;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = alocarNovoNo(valor);
    }
    lista->qtdade++;
}

void inserirElementoNoInicio(struct linkedlist *lista, int valor)
{
    struct no *novoNo = alocarNovoNo(valor);
    novoNo->prox = lista->cabeca;
    lista->cabeca = novoNo;
    lista->qtdade++;
}

void inserirElementoEmPosicao(struct linkedlist *lista, int valor, int posicao)
{
    //TODO
    if (lista->cabeca == NULL)
    {
        inserirElementoNoFim(lista, valor);
    }
    else if (posicao == 0)
    {
        inserirElementoNoInicio(lista, valor);
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
        lista->qtdade++;
    }
}

int obterElementoEmPosicao(struct linkedlist *lista, int posicao)
{
    //TODO
    struct no *aux = lista->cabeca;
    for (int i = 0; i < posicao; i++)
    {
        aux = aux->prox;
    }
    return aux->val;
}

void removerElementoEmPosicao(struct linkedlist *lista, int posicao)
{
    if (lista->qtdade == 1)
    {
        lista->cabeca = NULL;
    }
    else
    {
        //navegar até elemento anterior a posicao
        struct no *aux = lista->cabeca;
        if (posicao > 0)
        {
            for (int i = 0; i < posicao - 1; i++)
            {
                aux = aux->prox;
            }
            //atribuir valor aux->prox = valor do prox do no seguinte
            struct no *temp = aux->prox;

            aux->prox = temp->prox;

            free(temp);
        } else {
            lista->cabeca = aux->prox;
        }
    }
    lista->qtdade--;
}

void imprimirLista(struct linkedlist *lista)
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