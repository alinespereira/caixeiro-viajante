#ifndef _ARESTA_H
#define _ARESTA_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct _aresta ARESTA;

ARESTA *aresta_criar(int p1, int p2, int custo);
int aresta_get_p1(ARESTA *aresta);
int aresta_get_p2(ARESTA *aresta);
bool aresta_set_custo(ARESTA *aresta, int custo);
int aresta_get_custo(ARESTA *aresta);
bool aresta_mesmo_trajeto(ARESTA *v1, int p1, int p2);
void aresta_imprimir(ARESTA *v);
void aresta_apagar(ARESTA *a);

#endif
