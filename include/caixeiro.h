#ifndef _CAIXEIRO_H
#define _CAIXEIRO_H

#include <stdio.h>
#include <stdlib.h>

#include "adjacencia.h"
#include "vetor.h"

typedef struct _caminho CAMINHO;

ADJACENCIA *caixeiro_ler_custos();
CAMINHO *caixeiro_criar_caminho(int n_cidades);
void caixeiro_calcular_caminhos(ADJACENCIA *custos, VETOR *disponiveis, CAMINHO **caminho, int *distanca);
int caixeiro_calcular_distancia(ADJACENCIA *custos, CAMINHO *caminho);
void caixeiro_imprimir_caminho(CAMINHO *caminho);
CAMINHO *caixeiro_calcular_menor_caminho();
int caixeiro_calcular_distancia(ADJACENCIA *custos, CAMINHO *caminho);

#endif
