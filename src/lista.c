#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

#define LISTA_INVALIDA -1

struct _no {
    ITEM *item;
    NO *proximo;
};

struct _lista {
    NO *inicio;
    NO *fim;
    int tamanho;
};

LISTA *lista_criar() {
    LISTA *lista = (LISTA *)malloc(sizeof(LISTA));
    if (lista) {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }

    return lista;
}

bool lista_inserir_fim(LISTA *lista, ITEM *item) {
    if (!lista)
        return false;

    NO *no = (NO *)malloc(sizeof(NO));
    if (no) {
        no->item = item;
        no->proximo = NULL;
        if (lista_vazia(lista)) {
            lista->inicio = no;
        } else {
            lista->fim->proximo = no;
        }
        lista->fim = no;
        lista->tamanho++;
        return true;
    }
    return false;
}

void lista_apagar(LISTA **lista) {
    if (lista) {
        lista_limpar(*lista);
        free(*lista);
        *lista = NULL;
    }
}

bool lista_limpar(LISTA *lista) {
    if (lista) {
        for (NO *no = lista->inicio; !lista_vazia(lista); no = lista->inicio) {
            lista->inicio = no->proximo;
            item_apagar(no->item);
            no->item = NULL;
            free(no);
            lista->tamanho--;
        }
        lista->inicio = NULL;
        lista->fim = NULL;
        return true;
    } else {
        return false;
    }
}

bool lista_remover(LISTA *lista, int chave) {
    if (lista) {
        NO *prev = NULL;
        NO *curr = lista->inicio;

        while ((item_get_chave(curr->item) != chave && curr)) {
            NO *prev = curr;
            curr = curr->proximo;
        }

        if (curr) {
            if (curr == lista->fim) {
                lista->fim = prev;
            }
            prev->proximo = curr->proximo;
            item_apagar(curr->item);
            free(curr);
            curr = NULL;
            return true;
        }
    }
    return false;
}

ITEM *lista_get_inicio(LISTA *lista) {
    return lista->inicio;
}

ITEM *lista_get_proximo(LISTA *lista, ITEM *item) {
    if (lista) {
        for (NO *no = lista->inicio; no != NULL; no = no->proximo) {
            if (item_get_chave(no->item) == item_get_chave(item)) {
                return no->proximo->item;
            }
        }
    }
}

ITEM *lista_busca(LISTA *lista, int chave) {
    if (lista) {
        for (NO *no = lista->inicio; no != NULL; no = no->proximo) {
            if (item_get_chave(no->item) == chave) {
                return no->item;
            }
        }
    }
    return NULL;
}

int lista_tamanho(LISTA *lista) {
    if (lista)
        return lista->tamanho;
    return LISTA_INVALIDA;
}

bool lista_vazia(LISTA *lista) {
    return lista && lista_tamanho(lista) == 0;
}

void lista_imprimir(LISTA *lista) {
    for (NO *no = lista->inicio; no != lista->fim; no = no->proximo) {
        item_imprimir(no->item);
    }
    printf("\n");
}
