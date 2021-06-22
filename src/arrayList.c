#include <stdio.h>
#include <stdlib.h>

int *lista;
int tamanho = 0;

void inicializar(int capacidade)
{
    lista = calloc(capacidade, sizeof(int));
}

void duplicarCapacidade()
{
    /* int novaLista[2*sizeof(lista)];
    for (int i =0; sizeof(lista); i++){
        novaLista[i] = lista[i];
    }
    free(lista);
    lista = novaLista; */

    lista = (int *)realloc(lista, 2 * sizeof(lista) * sizeof(int));
}

void inserirElementoNoFim(int valor)
{
    if (tamanho == sizeof(lista))
    {
        duplicarCapacidade();
    }
    lista[tamanho] = valor;
    tamanho++;
}

int obterElemento(int posicao)
{
    if (posicao >= 0 && posicao < tamanho)
    {
        return lista[posicao];
    }
}

void inserirElementoEmPosicao(int valor, int posicao)
{
    if (posicao >= 0 && posicao <= tamanho)
    {
        if (tamanho == sizeof(lista))
        {
            duplicarCapacidade();
        }
        for (int i = tamanho; i > posicao; i--)
        {
            lista[i] = lista[i - 1];
        }
        lista[posicao] = valor;
        tamanho++;
    }
}

void atualizarElemento(int valor, int posicao)
{
    if (posicao >= 0 && posicao < tamanho)
    {
        lista[posicao] = valor;
    }
}

int getTamanho()
{
    return tamanho;
}

//remover elemento no fim da lista
void removerElemento()
{
    tamanho--;
}

void removerElementoEmPosicao(int posicao)
{
    if (posicao >= 0 && posicao < tamanho)
    {
        while (posicao < tamanho - 1)
        {
            lista[posicao] = lista[posicao + 1];
            posicao++;
        }
        tamanho--;
    }
}