#ifndef _VETOR_H
#define _VETOR_H

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _vetor VETOR;

VETOR *vetor_criar(int tamanho);
VETOR *vetor_copiar(VETOR *v);
int vetor_get_tamanho(VETOR *v);
bool vetor_set_elemento(VETOR *v, int indice, int valor);
int vetor_get_elemento(VETOR *v, int indice);
bool vetor_push_elemento(VETOR *v, int valor);
int vetor_pop_elemento(VETOR *v);
VETOR *vetor_remover_elemento(VETOR *v, int indice);
void vetor_imprimir(VETOR *v);
void vetor_apagar(VETOR **v);

#endif
