#ifndef _VETOR_H
#define _VETOR_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct _vetor VETOR;

VETOR *vetor_criar(int tamanho);
int vetor_get_tamanho(VETOR *vetor);
bool vetor_set_elemento(VETOR *vetor, int indice, int valor);
int vetor_get_elemento(VETOR *vetor, int indice);
void vetor_apagar(VETOR **vetor);

#endif
