#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct arrayqueue
{
    int frente;
    int tras;
    int *elementos;
    int tamanho; //tam do array
    int qtdade;  //qtdade de elementos no array
};

struct arrayqueue *inicializar(int tamArray)
{
    struct arrayqueue *fila = (struct arrayqueue *)malloc(sizeof(struct arrayqueue));
    fila->elementos = (int *)calloc(tamArray, sizeof(int));
    fila->frente = 0;
    fila->tras = 0;
    fila->tamanho = tamArray;
    fila->qtdade = 0;
    return fila;
}

//se a fila estiver nula, instancie a fila com tamanho 10
//por causa da possibilidade de instanciacao usamos struct arrayqueue**
//se a fila encher, simplesmente não enfileire
void enfileirar(struct arrayqueue **fila, int val)
{
    if ((*fila) == NULL)
    {
        (*fila) = inicializar(10);
    }

    if ((*fila)->qtdade < (*fila)->tamanho)
    {
        (*fila)->elementos[(*fila)->tras] = val;
        if ((*fila)->tras == (*fila)->tamanho - 1)
        {
            (*fila)->tras = -1;
        }
        (*fila)->tras++;
        (*fila)->qtdade++;
    }
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int desenfileirar(struct arrayqueue *fila)
{
    if (fila == NULL || fila->qtdade == 0)
    {
        return INT_MIN;
    }
    else
    {
        int temp = fila->elementos[fila->frente];
        fila->frente++;
        if (fila->frente > fila->tamanho - 1)
        {
            fila->frente = 0;
        }
        fila->qtdade--;
        if (fila->tras == fila->frente)
        {
            fila->frente = 0;
            fila->tras = 0;
        }
        return temp;
    }
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int frente(struct arrayqueue *fila)
{
    if (fila == NULL || fila->qtdade == 0)
    {
        return INT_MIN;
    }
    else
    {
        return fila->elementos[fila->frente];
    }
}