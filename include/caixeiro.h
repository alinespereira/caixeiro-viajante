#ifndef _CAIXEIRO_H
#define _CAIXEIRO_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "adjacencia.h"
#include "lista.h"
#include "vetor.h"

typedef struct _caminho CAMINHO;

ADJACENCIA *caixeiro_ler_custos();
CAMINHO *caixeiro_criar_caminho();
LISTA *caminho_get_cidades(CAMINHO *caminho);
bool caminho_set_cidades(CAMINHO *caminho, LISTA *cidades);
int caminho_get_custo(CAMINHO *caminho);
bool caminho_set_custo(CAMINHO *caminho, int custo);
void caixeiro_calcular_caminhos(ADJACENCIA *custos, int n_cidades, LISTA *atual, LISTA *disponiveis, CAMINHO *melhor_caminho);
int caixeiro_calcular_distancia(ADJACENCIA *custos, CAMINHO *caminho);
void caixeiro_imprimir_caminho(CAMINHO *caminho);
CAMINHO *caixeiro_calcular_menor_caminho();
int caixeiro_calcular_distancia(ADJACENCIA *custos, CAMINHO *caminho);

#endif
