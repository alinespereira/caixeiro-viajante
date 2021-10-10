#include "item.h"

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

void item_apagar(ITEM *item) {
}

int item_get_chave(ITEM *item) {
    return item->chave;
}

void item_imprimir(ITEM *item) {
}
