#include "caixeiro.h"

#include <limits.h>

struct _caminho {
    LISTA *cidades;
    int custo;
};

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
}

void caixeiro_calcular_caminhos_rec(ADJACENCIA *custos, LISTA *cidades, CAMINHO *melhor_caminho, int indice, int *contador) {
    if (indice == lista_tamanho(cidades) - 1) {
        (*contador)++;
        printf("Caminhos calculados: %d\n", *contador);
        CAMINHO *caminho = caixeiro_criar_caminho();
        caminho_set_cidades(caminho, lista_copiar(cidades));
        int nova_distancia = 0;  // caixeiro_calcular_distancia(custos, caminho);
        caminho_set_custo(caminho, nova_distancia);
        if (nova_distancia != INT_MAX && nova_distancia < caminho_get_custo(melhor_caminho)) {
            caminho_set_cidades(melhor_caminho, lista_copiar(cidades));
            caminho_set_custo(melhor_caminho, nova_distancia);
        }
        caminho_apagar(&caminho);
    } else {
        for (int i = indice; i < lista_tamanho(cidades); i++) {
            lista_trocar(cidades, i, indice);
            caixeiro_calcular_caminhos_rec(custos, cidades, melhor_caminho, indice + 1, contador);
            lista_trocar(cidades, i, indice);
        }
    }
}

void caixeiro_calcular_caminhos(ADJACENCIA *custos, LISTA *cidades, CAMINHO *melhor_caminho) {
    int contador = 0;
    caixeiro_calcular_caminhos_rec(custos, cidades, melhor_caminho, 1, &contador);
}

int caixeiro_calcular_distancia(ADJACENCIA *custos, CAMINHO *caminho) {
    /*lista_imprimir(caminho->cidades);
    printf("n_cidades: %d\n", lista_tamanho(caminho->cidades));
    caixeiro_imprimir_caminho(caminho);
    printf("---------------------\n");*/
    int partida, chegada, total = 0;
    ITEM *cidade_atual = lista_get_inicio(caminho->cidades);

    caixeiro_imprimir_caminho(caminho);
    partida = item_get_valor(cidade_atual);

    for (int i = 0; i < lista_tamanho(caminho->cidades) - 1; i++) {
        printf("partida: %d\n", partida);
        cidade_atual = lista_get_proximo(caminho->cidades, cidade_atual);

        chegada = item_get_valor(cidade_atual);
        printf("chegada: %d\n", chegada);

        total += aresta_get_custo(adjacencia_buscar_aresta(custos, partida, chegada));

        partida = chegada;
    }

    chegada = item_get_valor(lista_get_inicio(caminho->cidades));

    total += aresta_get_custo(adjacencia_buscar_aresta(custos, partida, chegada));

    printf("total: %d\n", total);

    return total;
}

void caixeiro_imprimir_caminho(CAMINHO *caminho) {
    printf("caminho:\n");
    lista_imprimir(caminho->cidades);
    printf("distancia = %d\n", caminho->custo);
}
