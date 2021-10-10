#include "vertice.h"

#include <stdio.h>

struct _vertice {
    int p1;
    int p2;
    int custo;
};

VERTICE *vertice_criar(int p1, int p2, int custo) {
    VERTICE *v = (VERTICE *)malloc(sizeof(VERTICE));
    if (v) {
        v->p1 = p1;
        v->p2 = p2;
        v->custo = custo;
    }

    return v;
}

bool vertice_set_p1(VERTICE *vertice, int p1) {
    if (vertice) {
        vertice->p1 = p1;
        return true;
    }
    return false;
}

bool vertice_set_p2(VERTICE *vertice, int p2) {
    if (vertice) {
        vertice->p2 = p2;
        return true;
    }
    return false;
}

int vertice_get_p1(VERTICE *vertice) {
    return vertice->p1;
}

int vertice_get_p2(VERTICE *vertice) {
    return vertice->p2;
}

bool vertice_set_custo(VERTICE *vertice, int custo) {
    if (vertice) {
        vertice->custo = custo;
        return true;
    }
    return false;
}
int vertice_get_custo(VERTICE *vertice) {
    return vertice->custo;
}

// bool vertice_mesmo_trajeto(VERTICE *v1, VERTICE *v2) {
//     return ((v1->p1 == v2->p1 && v1->p2 == v2->p2) || (v1->p2 == v2->p1 && v1->p1 == v2->p2));
// }

bool vertice_mesmo_trajeto(VERTICE *v, int p1, int p2) {
    bool caminho_direto_igual = vertice_get_p1(v) == p1 && vertice_get_p2(v) == p2;
    bool caminho_inverso_igual = vertice_get_p1(v) == p2 && vertice_get_p2(v) == p1;
    return caminho_direto_igual || caminho_inverso_igual;
}

void vertice_imprimir(VERTICE *v) {
    if (v) {
        printf("custo(%d, %d) = %d\n", vertice_get_p1(v), vertice_get_p2(v), vertice_get_custo(v));
    }
}
