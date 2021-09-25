#ifndef _MATRIZ_H
#define _MATRIZ_H

#include <stdbool.h>

typedef struct _matriz MATRIZ;

MATRIZ *matriz_criar(int tamanho);
int matriz_get_entrada(MATRIZ *m, int i, int j);
void matriz_set_entrada(MATRIZ *m, int i, int j, int valor);
bool matriz_preencher(MATRIZ *m);
bool matriz_vazia(MATRIZ *m);
void matriz_limpar(MATRIZ *m);
void matriz_imprimir(MATRIZ *m);

#endif
