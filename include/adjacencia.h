#ifndef _ADJACENCIA_H
#define _ADJACENCIA_H

#include <stdbool.h>
#include <stdlib.h>

#include "vertice.h"

#define TAMANHO_INVALIDO -1

typedef struct _adjacencia ADJACENCIA;

ADJACENCIA *adjacencia_criar();
bool adjacencia_adicionar_vertice(ADJACENCIA *a, VERTICE *v);
int adjacencia_get_n_vertices(ADJACENCIA *a);
VERTICE *adjacencia_buscar_vertice(ADJACENCIA *a, int p1, int p2);
void adjacencia_imprimir(ADJACENCIA *a);
bool adjacencia_vazia(ADJACENCIA *a);
void adjacencia_apagar(ADJACENCIA **a);

#endif
