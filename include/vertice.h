#ifndef _VERTICE_H
#define _VERTICE_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct _vertice VERTICE;

VERTICE *vertice_criar(int p1, int p2, int custo);
bool vertice_set_p1(VERTICE *vertice, int p1);
bool vertice_set_p2(VERTICE *vertice, int p2);
int vertice_get_p1(VERTICE *vertice);
int vertice_get_p2(VERTICE *vertice);
bool vertice_set_custo(VERTICE *vertice, int custo);
int vertice_get_custo(VERTICE *vertice);
bool vertice_mesmo_trajeto(VERTICE *v1, int p1, int p2);
void vertice_imprimir(VERTICE *v);

#endif
