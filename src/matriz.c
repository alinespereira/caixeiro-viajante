#include "matriz.h"

#include <stdio.h>
#include <stdlib.h>

struct _matriz {
    int tamanho;
    int **dados;
};

MATRIZ *matriz_criar(int tamanho) {
    MATRIZ *m;

    m = (MATRIZ *)malloc(sizeof(MATRIZ));
    m->tamanho = tamanho;
    m->dados = (int **)malloc(tamanho * sizeof(int *));
    for (int i = 0; i < tamanho; i++) {
        m->dados[i] = (int *)malloc(tamanho * sizeof(int));
        for (int j = 0; j < tamanho; j++)
            m->dados[i][j] = 0;
    }
    return m;
}

int matriz_get_tamanho(MATRIZ *m) {
    return m->tamanho;
}

int matriz_get_entrada(MATRIZ *m, int i, int j) {
    return m->dados[i][j];
}

void matriz_set_entrada(MATRIZ *m, int i, int j, int valor) {
    m->dados[i][j] = valor;
}

bool matriz_preencher(MATRIZ *m) {
    if (m == NULL || m->tamanho == 0)
        return false;

    int linha, coluna, valor;
    int counter = (m->tamanho * m->tamanho) - m->tamanho - 1;

    for (int i = 0; i < counter; i++) {
        scanf("%d %d %d\n", &linha, &coluna, &valor);

        if (linha > m->tamanho || coluna > m->tamanho) {
            printf("Fora do escopo");
            return false;
        }
        m->dados[linha - 1][coluna - 1] = valor;
    }

    return true;
}

bool matriz_vazia(MATRIZ *m) {
    if (m != NULL && m->tamanho > 0)
        return false;
    else
        return true;
}

void matriz_limpar(MATRIZ *m) {
    if (!matriz_vazia(m)) {
        for (int i = 0; i < m->tamanho; i++) {
            free(m->dados[i]);
            m->dados[i] = NULL;
            printf("Limpou a matriz\n");
        }
        free(m->dados);
        m->dados = NULL;
    }

    free(m);
    m = NULL;
    printf("Limpou a struct\n");
}

void matriz_imprimir(MATRIZ *m) {
    for (int i = 0; i < m->tamanho; i++) {
        for (int j = 0; j < m->tamanho; j++)
            printf("%d ", m->dados[i][j]);
        printf("\n");
    }
}
