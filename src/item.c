#include "item.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct _item {
    int chave;
    int valor;
};

ITEM *item_criar(int chave, int valor) {
    ITEM *item = (ITEM *)malloc(sizeof(ITEM));
    if (item) {
        item->chave = chave;
        item->valor = valor;
    }
    return item;
}

void item_apagar(ITEM **item) {
    free(*item);
    *item = NULL;
}

int item_get_chave(ITEM *item) {
    if (item) {
        return item->chave;
    }
    return INT_MAX;
}

int item_get_valor(ITEM *item) {
    if (item) {
        return item->valor;
    }
    return INT_MAX;
}

void item_imprimir(ITEM *item) {
    printf("%d",item_get_valor(item));
}
