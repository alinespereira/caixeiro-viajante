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

void caixeiro_calcular_caminhos(ADJACENCIA *custos, int n_cidades, LISTA *atual, LISTA *disponiveis, CAMINHO *melhor_caminho) {
    printf("disponíveis: %d\n", lista_tamanho(disponiveis));
    if (lista_tamanho(disponiveis) == 0) {
        int nova_distancia = caixeiro_calcular_distancia(custos, melhor_caminho);
        if (nova_distancia != INT_MAX && nova_distancia < caminho_get_custo(melhor_caminho)) {
            caminho_set_cidades(melhor_caminho, atual);
            caminho_set_custo(melhor_caminho, nova_distancia);
        }
    } else {
        for (int i = 0; i < lista_tamanho(disponiveis); i++) {
            lista_imprimir(disponiveis);
            ITEM *proximo = lista_buscar_posicao(disponiveis, i);
            printf("--\n");
            item_imprimir(proximo);
            printf("--\n");
            lista_inserir_fim(atual, proximo);
            lista_imprimir(atual);
            printf("--------------------\n");
            // lista_remover(disponiveis, item_get_chave(proximo));
            caixeiro_calcular_caminhos(custos, n_cidades, atual, disponiveis, melhor_caminho);
            lista_inserir_posicao(disponiveis, proximo, i);
        }
    }

    // do {
    //     lista_inserir_fim(atual, proximo);
    //     lista_remover(disponiveis, item_get_chave(proximo));
    //     if (lista_tamanho(atual) == n_cidades) {
    //         int nova_distancia = caixeiro_calcular_distancia(custos, melhor_caminho);
    //         if (nova_distancia != INT_MAX && nova_distancia < caminho_get_custo(melhor_caminho)) {
    //             caminho_set_cidades(melhor_caminho, atual);
    //             caminho_set_custo(melhor_caminho, nova_distancia);
    //         }
    //     } else {
    //         caixeiro_calcular_caminhos(custos, n_cidades, atual, disponiveis, melhor_caminho);
    //         lista_inserir_fim(atual, proximo);
    //         proximo = lista_get_proximo(disponiveis, proximo);
    //     }
    // } while (item_get_chave(proximo) < n_cidades);
}

int caixeiro_calcular_distancia(ADJACENCIA *custos, CAMINHO *caminho) {
    int partida, chegada, total = 0;

    partida = item_get_chave(lista_get_inicio(caminho->cidades));

    for (int i = 0; i < lista_tamanho(caminho->cidades); i++) {
        chegada = item_get_chave(lista_get_proximo(caminho->cidades, lista_busca(caminho->cidades, partida)));

        total += aresta_get_custo(adjacencia_buscar_aresta(custos, partida, chegada));

        partida = chegada;
    }

    chegada = item_get_chave(lista_get_inicio(caminho->cidades));

    total += aresta_get_custo(adjacencia_buscar_aresta(custos, partida, chegada));

    return total;
}

void caixeiro_imprimir_caminho(CAMINHO *caminho) {
    int n_cidades = lista_tamanho(caminho->cidades);
    printf("caminho: %d", item_get_valor(lista_busca(caminho->cidades, 0)));
    for (int i = 1; i < n_cidades; i++) {
        printf(" -> %d", item_get_valor(lista_busca(caminho->cidades, i)));
    }
    printf(": distancia = %d\n", caminho->custo);
}
