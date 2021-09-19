#ifndef _MATRIZ_H
#define _MATRIZ_H

typedef struct _matriz MATRIZ;

MATRIZ *matriz_criar(int tamanho);
int matriz_buscar_entrada(MATRIZ *m, int i, int j);

#endif
