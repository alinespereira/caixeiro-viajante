#ifndef _CAIXEIRO_H
#define _CAIXEIRO_H

#include <stdio.h>

#include "matriz.h"
#include "vetor.h"

typedef struct _caminho CAMINHO;

MATRIZ *caixeiro_ler_dados();
CAMINHO *caixeiro_calcular_menor_caminho();
int caixeiro_calcular_distancia(MATRIZ *custos, CAMINHO *caminho);

#endif
