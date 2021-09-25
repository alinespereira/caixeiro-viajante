#include "caixeiro.h"

struct _caminho
{
    VETOR *cidades;
    int custo;
};

MATRIZ *caixeiro_ler_dados()
{
    int tamanho;
    MATRIZ *m = NULL;

    scanf("%d\n", &tamanho);

    m = matriz_criar(tamanho);

    int linha, coluna, valor;
    int contador = (tamanho * tamanho) - tamanho;

    for (int i = 0; i < contador; i++)
    {
        scanf("%d %d %d\n", &linha, &coluna, &valor);

        if (linha > tamanho || coluna > tamanho)
        {
            printf("Fora do escopo");
            return NULL;
        }
        matriz_set_entrada(m, linha - 1, coluna - 1, valor);
    }

    return m;
}

CAMINHO *caixeiro_calcular_menor_caminho()
{
    return NULL;
}

int caixeiro_calcular_distancia(MATRIZ *custos, CAMINHO *caminho)
{
    return 0;
}
