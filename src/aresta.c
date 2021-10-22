#include <stdio.h>

#include "aresta.h"

struct _aresta
{
    int p1;
    int p2;
    int custo;
};

ARESTA *aresta_criar(int p1, int p2, int custo)
{
    ARESTA *v = (ARESTA *)malloc(sizeof(ARESTA));
    if (v)
    {
        v->p1 = p1;
        v->p2 = p2;
        v->custo = custo;
    }

    return v;
}

int aresta_get_p1(ARESTA *aresta)
{
    return aresta->p1;
}

int aresta_get_p2(ARESTA *aresta)
{
    return aresta->p2;
}

bool aresta_set_custo(ARESTA *aresta, int custo)
{
    if (aresta)
    {
        aresta->custo = custo;
        return true;
    }
    return false;
}
int aresta_get_custo(ARESTA *aresta)
{
    return aresta->custo;
}

// verifica a semelhança entre trajetos;
bool aresta_mesmo_trajeto(ARESTA *v, int p1, int p2)
{
    bool caminho_direto_igual = aresta_get_p1(v) == p1 && aresta_get_p2(v) == p2;
    bool caminho_inverso_igual = aresta_get_p1(v) == p2 && aresta_get_p2(v) == p1;
    return caminho_direto_igual || caminho_inverso_igual;
}

void aresta_imprimir(ARESTA *v)
{
    if (v)
    {
        printf("custo(%d, %d) = %d\n", aresta_get_p1(v), aresta_get_p2(v), aresta_get_custo(v));
    }
}

void aresta_apagar(ARESTA *a)
{
    free(a);
    a = NULL;
}
