#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct no
{
    int val;
    struct no *prox;
};

struct linkedqueue
{
    struct no *frente;
    struct no *tras;
    int qtdade;
};

struct linkedqueue *inicializar()
{
    struct linkedqueue *fila = (struct linkedqueue *)malloc(sizeof(struct linkedqueue));
    fila->frente = NULL;
    fila->tras = NULL;
    fila->qtdade = 0;
    return fila;
}

struct no *alocarNovoNo(int valor)
{
    struct no *novoNo = (struct no *)malloc(sizeof(struct no));
    novoNo->val = valor;
    novoNo->prox = NULL;
    return novoNo;
}

bool vazia(struct linkedqueue *fila)
{
    if (fila == NULL || fila->qtdade == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//se a fila estiver nula, instancie a fila
//por causa da possibilidade de instanciacao usamos struct linkedqueue**
void enfileirar(struct linkedqueue **fila, int val)
{
    struct no *novoNo = alocarNovoNo(val);
    if ((*fila) == NULL || (*fila)->qtdade == 0)
    {
        if ((*fila) == NULL)
        {
            (*fila) = inicializar();
        }
        (*fila)->frente = novoNo;
        (*fila)->tras = novoNo;
    }
    if ((*fila)->frente == (*fila)->tras)
    {
        (*fila)->frente->prox = novoNo;
    }
    (*fila)->tras = novoNo;
    (*fila)->qtdade++;
}

//retorne a constante INT_MIN se a fila for nula ou vazia
//lembrem de desalocar o n� removido (free)
int desenfileirar(struct linkedqueue *fila)
{
    if (fila == NULL || fila->qtdade == 0)
    {
        return INT_MIN;
    }

    int temp = fila->frente->val;
    if (fila->frente->prox != NULL)
    {
        struct no *aux = fila->frente;
        fila->frente = fila->frente->prox;
        free(aux);
    }

    fila->qtdade--;

    return temp;
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int frente(struct linkedqueue *fila)
{
    if (fila == NULL || fila->qtdade == 0)
    {
        return INT_MIN;
    }
    else
    {
        return fila->frente->val;
    }
}