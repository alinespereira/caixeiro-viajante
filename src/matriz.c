#include "matriz.h"

#include <stdlib.h>
#include <stdio.h>

struct _matriz
{
    int tamanho;
    int **dados;
};

MATRIZ *matriz_criar(int tamanho)
{
    MATRIZ *m;

    m = (MATRIZ *)malloc(sizeof(MATRIZ));
    m->tamanho = tamanho;
    m->dados = (int **)malloc(tamanho * sizeof(int *));
    for (int i = 0; i < tamanho; i++)
        {
            m->dados[i] = (int *)malloc(tamanho * sizeof(int));
            for (int j = 0; j < tamanho; j++)
                m->dados[i][j] = 1;
        }
    return m;
}

int matriz_buscar_entrada(MATRIZ *m, int i, int j)
{
    return m->dados[i][j];
}

bool matriz_preencher(MATRIZ *m)
{
    printf("%d\n", m->tamanho);
    if (m == NULL || m->tamanho == 0)
        return false;

    int linha, coluna, valor;
    scanf ("%d %d %d\n", &linha, &coluna, &valor);

    printf("linha: %d\ncoluna: %d\nvalor: %d\n", linha, coluna, valor);

    if (linha > m->tamanho || coluna > m->tamanho)
        return false;
    m->dados[linha - 1][coluna -1] = valor;
    
    if (linha <= m->tamanho && coluna < m->tamanho - 1)
        matriz_preencher(m);
    
    return true;
}

bool matriz_vazia (MATRIZ *m)
{
    if (m != NULL && m->tamanho > 0)
        return false;
    else
        return true;
}

void matriz_limpar (MATRIZ **m)
{
    if (!matriz_vazia(*m))
    {
        for (int i = 0; i < (*m)->tamanho; i++)
        {
            /*for (int j = 0; j < (*m)->tamanho; j++)
            {
                free ((*m)->dados[i][j]);
                (*m)->dados[i][j] = NULL;
            }*/
            free ((*m)->dados[i]);
            (*m)->dados[i] = NULL;
            printf ("Limpou a matriz\n");
        }
    }
    
    free(*m);
    *m = NULL;
    printf("limpou a struct");
}

void matriz_imprimir(MATRIZ *m)
{
    for (int i = 0; i < m->tamanho; i++)
    {
        for (int j = 0; j < m->tamanho; j++)
        {
            if (i == j)
                printf ("0 ");
            else
                printf ("%d ", m->dados[i][j]);
        }
        printf ("\n");
    }
    
}