#ifndef _CAIXEIRO_H
#define _CAIXEIRO_H

#include <stdio.h>
#include <stdlib.h

#include "matriz.h"
#include "vetor.h"

typedef struct _caminho CAMINHO;

MATRIZ *caixeiro_ler_dados();
CAMINHO *caixeiro_criar_caminho(int n_cidades);
void caixeiro_calcular_caminhos(MATRIZ *custos, VETOR *disponiveis, CAMINHO **caminho, int *distanca);
int caixeiro_calcular_distancia(MATRIZ *custos, CAMINHO *caminho);
void caixeiro_imprimir_caminho(CAMINHO *caminho);
CAMINHO *caixeiro_calcular_menor_caminho();
int caixeiro_calcular_distancia(MATRIZ *custos, CAMINHO *caminho);

#endif
