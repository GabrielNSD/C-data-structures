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

// int tamanho = 0;
// struct no *lista;

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

struct linkedlist* inicializar() {
    //TODO
    return 0;
}

struct no* alocarNovoNo(int valor) {
    //TODO
    return 0;
}

void inserirElementoNoFim(struct linkedlist* lista, int valor) {
    //TODO
    //caso esteja vazia, criar novo no
    //caso nao esteja vazia, percorrer toda a lista e inserir novo nó no final
    return;

}

void inserirElementoNoInicio(struct linkedlist* lista, int valor) {
    //TODO
    return;
}

void inserirElementoEmPosicao(struct linkedlist* lista, int valor, int posicao) {
    //TODO
    return;
}

int obterElementoEmPosicao(struct linkedlist* lista, int posicao) {
    //TODO
    return 0;
}

void removerElementoEmPosicao(struct linkedlist* lista, int posicao) {
    //TODO
    return;
}
