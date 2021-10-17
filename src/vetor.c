#include "vetor.h"

struct _vetor {
    int *dados;
    int tamanho;
};

VETOR *vetor_criar(int tamanho) {
    VETOR *v = (VETOR *)malloc(sizeof(VETOR));

    // Tratar erro (?)
    if (v != NULL) {
        v->dados = (int *)malloc(tamanho * sizeof(int));
        v->tamanho = tamanho;
    }

    if (v != NULL && v->dados != NULL)
        return v;

    return NULL;
}

VETOR *vetor_copiar(VETOR *v) {
    VETOR *tmp = vetor_criar(v->tamanho);

    for (int i = 0; i < v->tamanho; i++)
        tmp->dados[i] = v->dados[i];

    return tmp;
}

int vetor_get_tamanho(VETOR *v) {
    if (v != NULL)
        return v->tamanho;

    return INT_MIN;
}

bool vetor_set_elemento(VETOR *v, int indice, int valor) {
    if (indice < v->tamanho) {
        v->dados[indice] = valor;
        return true;
    }

    return false;
}

int vetor_get_elemento(VETOR *v, int indice) {
    return v->dados[indice];
}

bool vetor_push_elemento(VETOR *v, int valor) {
    v->dados = (int *)realloc(v->dados, (v->tamanho + 1) * sizeof(int));
    if (v->dados == NULL)
        return false;

    v->dados[v->tamanho] = valor;
    v->tamanho++;
    return true;
}

int vetor_pop_elemento(VETOR *v) {
    int valor = vetor_get_elemento(v, v->tamanho - 1);
    v->tamanho--;
    v->dados = (int *)realloc(v->dados, v->tamanho * sizeof(int));

    if (v->dados == NULL)
        return INT_MAX;

    return valor;
}

VETOR *vetor_remover_elemento(VETOR *v, int indice) {
    VETOR *tmp = vetor_copiar(v);

    if (indice >= tmp->tamanho)
        return NULL;

    for (int i = indice; i < tmp->tamanho - 1; i++) {
        int proximo = tmp->dados[i + 1];
        tmp->dados[indice] = proximo;
    }

    tmp->dados = (int *)realloc(tmp->dados, (tmp->tamanho - 1) * sizeof(int));
    tmp->tamanho--;

    return tmp;
}

void vetor_imprimir(VETOR *v) {
    printf("\t\tvetor: [%d", vetor_get_elemento(v, 0));
    for (int i = 1; i < v->tamanho; i++)
        printf(", %d", vetor_get_elemento(v, i));
    printf("]\n");
}

bool vetor_vazio(VETOR *v) {
    return (v->dados == NULL || v->tamanho > 0);
}

void vetor_apagar(VETOR **v) {
    if (!((v == NULL) || vetor_vazio(*v))) 
    {
        free((*v)->dados);
        (*v)->dados = NULL;    
    }

    free(*v);
    v = NULL;
}
