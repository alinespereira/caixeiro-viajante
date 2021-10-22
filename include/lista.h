#ifndef _LISTA_H
#define _LISTA_H

#include <stdbool.h>

#include "item.h"

typedef struct _no NO;
typedef struct _lista LISTA;

LISTA *lista_criar();
bool lista_inserir_fim(LISTA *lista, ITEM *item);
LISTA *lista_copiar(LISTA *lista);
bool lista_trocar(LISTA *lista, int i, int j);
void lista_apagar(LISTA **lista);
bool lista_limpar(LISTA *lista);
ITEM *lista_get_inicio(LISTA *lista);
ITEM *lista_get_proximo(LISTA *lista, ITEM *item);
int lista_tamanho(LISTA *lista);
bool lista_vazia(LISTA *lista);
void lista_imprimir(LISTA *lista);

#endif
