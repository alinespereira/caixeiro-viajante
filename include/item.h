#ifndef _ITEM_H
#define _ITEM_H

typedef struct _item ITEM;

ITEM *item_criar(int chave, int valor);
void item_apagar(ITEM *item);
int item_get_chave(ITEM *item);
int item_get_valor(ITEM *item);
void item_imprimir(ITEM *item);

#endif
