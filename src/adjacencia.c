#include "adjacencia.h"

struct _adjacencia {
    VERTICE **vertices;
    int n_vertices;
};

ADJACENCIA *adjacencia_criar() {
    ADJACENCIA *a = (ADJACENCIA *)malloc(sizeof(ADJACENCIA));
    if (a) {
        a->vertices = NULL;
        a->n_vertices = 0;
    }

    return a;
}

bool adjacencia_adicionar_vertice(ADJACENCIA *a, VERTICE *v) {
    if (a) {
        a->vertices = (VERTICE **)realloc(a->vertices, (adjacencia_get_n_vertices(a) + 1) * sizeof(VERTICE *));
        if (a->vertices) {
            a->vertices[adjacencia_get_n_vertices(a)] = v;
            a->n_vertices++;
            return true;
        }
    }

    return false;
}

int adjacencia_get_n_vertices(ADJACENCIA *a) {
    if (a) {
        return a->n_vertices;
    }

    return TAMANHO_INVALIDO;
}

VERTICE *adjacencia_buscar_vertice(ADJACENCIA *a, int p1, int p2) {
    if (a) {
        for (int i = 0; i < adjacencia_get_n_vertices(a); i++) {
            if (vertice_mesmo_trajeto(a->vertices[i], p1, p2)) {
                return a->vertices[i];
            }
        }
    }

    return NULL;
}

void adjacencia_imprimir(ADJACENCIA *a) {
    if (a) {
        for (int i = 0; i < adjacencia_get_n_vertices(a); i++)
            vertice_imprimir(a->vertices[i]);
    }
}
