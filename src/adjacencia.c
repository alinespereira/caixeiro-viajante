#include "adjacencia.h"

struct _adjacencia {
    ARESTA **arestas;
    int n_arestas;
};

ADJACENCIA *adjacencia_criar() {
    ADJACENCIA *a = (ADJACENCIA *)malloc(sizeof(ADJACENCIA));
    if (a) {
        a->arestas = NULL;
        a->n_arestas = 0;
    }

    return a;
}

bool adjacencia_adicionar_aresta(ADJACENCIA *a, ARESTA *v) {
    if (a) {
        a->arestas = (ARESTA **)realloc(a->arestas, (adjacencia_get_n_arestas(a) + 1) * sizeof(ARESTA *));
        if (a->arestas) {
            a->arestas[adjacencia_get_n_arestas(a)] = v;
            a->n_arestas++;
            return true;
        }
    }

    return false;
}

int adjacencia_get_n_arestas(ADJACENCIA *a) {
    if (a) {
        return a->n_arestas;
    }

    return TAMANHO_INVALIDO;
}

ARESTA *adjacencia_buscar_aresta(ADJACENCIA *a, int p1, int p2) {
    if (a) {
        for (int i = 0; i < adjacencia_get_n_arestas(a); i++) {
            if (aresta_mesmo_trajeto(a->arestas[i], p1, p2)) {
                return a->arestas[i];
            }
        }
    }

    return NULL;
}

void adjacencia_imprimir(ADJACENCIA *a) {
    if (a) {
        for (int i = 0; i < adjacencia_get_n_arestas(a); i++)
            aresta_imprimir(a->arestas[i]);
    }
}
