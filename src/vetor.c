#include "vetor.h"

struct _vetor
{
    int *dados;
    int tamanho;
};

VETOR *vetor_criar(int tamanho)
{
    VETOR *v = (VETOR *)malloc(sizeof(VETOR));

    // Tratar erro (?)
    if (v != NULL)
    {
        v->dados = (int *)malloc(tamanho * sizeof(int));
        v->tamanho = tamanho;
    }

    if (v != NULL && v->dados != NULL)
        return v;

    return NULL;
}

int vetor_get_tamanho(VETOR *vetor)
{
    return vetor->tamanho;
}

bool vetor_set_elemento(VETOR *vetor, int indice, int valor)
{
    if (indice < vetor->tamanho)
    {
        vetor->dados[indice] = valor;
        return true;
    }

    return false;
}

int vetor_get_elemento(VETOR *vetor, int indice)
{
    return vetor->dados[indice];
}

void vetor_apagar(VETOR **vetor)
{
}
