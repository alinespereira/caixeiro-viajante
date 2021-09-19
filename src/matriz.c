#include "matriz.h"

#include <stdlib.h>

struct _matriz
{
    int tamanho;
    int **dados;
};

MATRIZ *matriz_criar(int tamanho)
{
    MATRIZ *m = (MATRIZ *)malloc(sizeof(MATRIZ));
    m->tamanho = tamanho;
    m->dados = (int **)malloc(tamanho * sizeof(int *));
    for (int i = 0; i < tamanho; i++)
        m->dados[i] = (int *)malloc(tamanho * sizeof(int));

    return m;
}

int matriz_buscar_entrada(MATRIZ *m, int i, int j)
{
    return m->dados[i][j];
}
