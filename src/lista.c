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
    if (!lista || !item)
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

ITEM *lista_buscar_posicao(LISTA *lista, int pos) {
    if (!lista || pos >= lista_tamanho(lista))
        return false;

    NO *no;
    if (pos == 0) {
        no = lista->inicio;
        if (lista_tamanho(lista) - 1 == 0) {
            lista->inicio = NULL;
            lista->fim = NULL;
        } else {
            lista->inicio = lista->inicio->proximo;
        }
    } else {
        NO *prev = lista->inicio;
        for (int i = 1; i < pos; i++) {
            prev = prev->proximo;
        }
        no = prev->proximo;
        if (pos == lista_tamanho(lista) - 1) {
            prev->proximo = NULL;
        } else {
            prev->proximo = no->proximo;
        }
    }

    lista->tamanho--;
    if (no) {
        return no->item;
    } else {
        return NULL;
    }
}

bool lista_inserir_posicao(LISTA *lista, ITEM *item, int pos) {
    if (!lista || !item || pos >= lista_tamanho(lista))
        return false;

    NO *no = (NO *)malloc(sizeof(NO));
    if (no) {
        no->item = item;
        if (pos == 0) {
            no->proximo = lista->inicio;
            lista->inicio = no;
        } else if (pos == lista_tamanho(lista) - 1) {
            lista->fim = no;
            no->proximo = NULL;
        } else {
            NO *prev = lista->inicio;
            for (int i = 0; i < pos; i++) {
                prev = prev->proximo;
            }
            no->proximo = prev->proximo;
            prev->proximo = no;
        }
        lista->tamanho++;
        return true;
    }
    return false;
}

LISTA *lista_copiar(LISTA *lista) {
    if (lista) {
        LISTA *copia = lista_criar();
        for (NO *no = lista->inicio; no != NULL; no = no->proximo) {
            ITEM *it = item_criar(item_get_chave(no->item), item_get_valor(no->item));
            lista_inserir_fim(copia, it);
        }
        return copia;
    }

    return NULL;
}

bool lista_trocar(LISTA *lista, int i, int j) {
    if (!lista || i >= lista_tamanho(lista) || j >= lista_tamanho(lista))
        return false;
    else if (i == j)
        return true;

    NO *n1 = NULL;
    NO *n2 = lista->inicio;
    for (int k = 0; k < i; k++) {
        n1 = n2;
        n2 = n2->proximo;
    }

    NO *n3 = NULL;
    NO *n4 = lista->inicio;
    for (int k = 0; k < j; k++) {
        n3 = n4;
        n4 = n4->proximo;
    }

    if (n1) {
        n1->proximo = n4;
    } else {
        lista->inicio = n4;
    }

    if (n3) {
        n3->proximo = n2;
    } else {
        lista->inicio = n2;
    }

    NO *tmp = n4->proximo;
    n4->proximo = n2->proximo;
    n2->proximo = tmp;

    return true;
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
            item_apagar(&no->item);
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

ITEM *lista_remover(LISTA *lista, int chave) {
    if (lista) {
        NO *prev = NULL;
        NO *curr = lista->inicio;

        while ((item_get_chave(curr->item) != chave && curr)) {
            prev = curr;
            curr = curr->proximo;
        }

        if (curr) {
            if (curr == lista->fim) {
                lista->fim = prev;
            }
            if (!prev) {
                lista->inicio = curr;
            } else {
                prev->proximo = curr;
            }
            lista->tamanho--;
            return curr->item;
        }
    }
    return NULL;
}

ITEM *lista_get_inicio(LISTA *lista) {
    return lista->inicio->item;
}

ITEM *lista_get_proximo(LISTA *lista, ITEM *item) {
    if (lista) {
        for (NO *no = lista->inicio; no != lista->fim; no = no->proximo) {
            if (no->item == item) {
                return no->proximo->item;
            }
        }
    }
    return NULL;
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
    for (NO *no = lista->inicio; no != NULL; no = no->proximo) {
        item_imprimir(no->item);
    }
}
