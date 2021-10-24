#include "caixeiro.h"

#include <limits.h>

struct _caminho {
    LISTA *cidades;
    int custo;
};

//lê as entradas do arquivo
ADJACENCIA *caixeiro_ler_custos() {
    ADJACENCIA *custos = adjacencia_criar();

    if (custos) {
        int origem, destino, custo;
        while (scanf("%d %d %d", &origem, &destino, &custo) != EOF) {
            ARESTA *v = aresta_criar(origem, destino, custo);
            adjacencia_adicionar_aresta(custos, v);
            scanf("%*[\n\r]s");
        }
    }

    return custos;
}

CAMINHO *caixeiro_criar_caminho() {
    CAMINHO *c = (CAMINHO *)malloc(sizeof(CAMINHO));
    if (c) {
        c->cidades = NULL;
        c->custo = INT_MAX;
    }

    return c;
}

LISTA *caminho_get_cidades(CAMINHO *caminho) {
    if (caminho) {
        return caminho->cidades;
    }
    return NULL;
}

bool caminho_set_cidades(CAMINHO *caminho, LISTA *cidades) {
    if (caminho && cidades) {
        lista_apagar(&caminho->cidades);
        caminho->cidades = cidades;
        return true;
    }
    return false;
}

int caminho_get_custo(CAMINHO *caminho) {
    if (caminho) {
        return caminho->custo;
    }
    return INT_MAX;
}
bool caminho_set_custo(CAMINHO *caminho, int custo) {
    if (caminho) {
        caminho->custo = custo;
        return true;
    }
    return false;
}

void caminho_apagar(CAMINHO **caminho) {
    if (*caminho) {
        lista_apagar(&(*caminho)->cidades);
    }
    free(*caminho);
    *caminho = NULL;
}

void caixeiro_calcular_caminhos_rec(ADJACENCIA *custos, LISTA *cidades, CAMINHO *melhor_caminho, int indice) {
    if (indice == lista_tamanho(cidades) - 1) {
        CAMINHO *caminho = caixeiro_criar_caminho();
        caminho_set_cidades(caminho, lista_copiar(cidades));
        int nova_distancia = caixeiro_calcular_distancia(custos, caminho);
        caminho_set_custo(caminho, nova_distancia);
        if (nova_distancia != INT_MAX && nova_distancia < caminho_get_custo(melhor_caminho)) {
            caminho_set_cidades(melhor_caminho, lista_copiar(cidades));
            caminho_set_custo(melhor_caminho, nova_distancia);
        }
        caminho_apagar(&caminho);
    } else {
        for (int i = indice; i < lista_tamanho(cidades); i++) {
            lista_trocar(cidades, i, indice);
            caixeiro_calcular_caminhos_rec(custos, cidades, melhor_caminho, indice + 1);
            lista_trocar(cidades, i, indice);
        }
    }
}

void caixeiro_calcular_caminhos(ADJACENCIA *custos, LISTA *cidades, CAMINHO *melhor_caminho) {
    caixeiro_calcular_caminhos_rec(custos, cidades, melhor_caminho, 1);
}

int caixeiro_calcular_distancia(ADJACENCIA *custos, CAMINHO *caminho) {
    int partida, chegada, total = 0;
    ITEM *cidade_atual = lista_get_inicio(caminho->cidades);

    partida = item_get_valor(cidade_atual);

    for (int i = 0; i < lista_tamanho(caminho->cidades) - 1; i++) {
        cidade_atual = lista_get_proximo(caminho->cidades, cidade_atual);
        chegada = item_get_valor(cidade_atual);

        ARESTA *aresta = adjacencia_buscar_aresta(custos, partida, chegada);
        if (!aresta)
            return INT_MAX;

        total += aresta_get_custo(aresta);

        partida = chegada;
    }

    chegada = item_get_valor(lista_get_inicio(caminho->cidades));

    ARESTA *aresta = adjacencia_buscar_aresta(custos, partida, chegada);
    if (!aresta)
        return INT_MAX;

    total += aresta_get_custo(aresta);

    return total;
}

void caixeiro_imprimir_caminho(CAMINHO *caminho) {
    printf("caminho: ");
    lista_imprimir(caminho->cidades);
    printf(" distancia = %d\n", caminho->custo);
}
