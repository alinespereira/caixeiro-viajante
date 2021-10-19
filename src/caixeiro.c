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
    // printf("disponíveis: %d\n", lista_tamanho(disponiveis));  // REMOVER
    // lista_imprimir(disponiveis);                              // REMOVER
    if (lista_tamanho(disponiveis) == 0) {
        printf("agora eu calculo a distancia\n");  // REMOVER
        CAMINHO *caminho = caixeiro_criar_caminho();
        // lista_imprimir(atual);  // REMOVER
        caminho_set_cidades(caminho, atual);
        int nova_distancia = caixeiro_calcular_distancia(custos, caminho);
        caminho_set_custo(caminho, nova_distancia);
        if (nova_distancia != INT_MAX && nova_distancia < caminho_get_custo(melhor_caminho)) {
            caminho_set_cidades(melhor_caminho, atual);
            caminho_set_custo(melhor_caminho, nova_distancia);
        }
    } else {
        // printf("ainda nao\n");
        for (int i = 0; i < lista_tamanho(disponiveis); i++) {
            printf("i: %d\n", i);  // REMOVER
            // lista_imprimir(disponiveis);  // REMOVER
            ITEM *proximo = lista_buscar_posicao(disponiveis, i);
            // printf("--\n");          // REMOVER
            // item_imprimir(proximo);  // REMOVER
            // printf("--\n");          // REMOVER
            lista_inserir_fim(atual, proximo);
            // lista_imprimir(atual);             // REMOVER
            printf("--------------------\n");  // REMOVER
            caixeiro_calcular_caminhos(custos, n_cidades, atual, disponiveis, melhor_caminho);
            // printf("past here\n");  // REMOVER
            if (lista_tamanho(disponiveis) == 0) {
                lista_inserir_fim(disponiveis, proximo);
            } else {
                printf("i [else]: %d\n", i);
                lista_inserir_posicao(disponiveis, proximo, i);
            }
            printf("disponíveis: %d\n", lista_tamanho(disponiveis));  // REMOVER
            lista_buscar_posicao(atual, lista_tamanho(atual) - 1);
            printf("atual      : %d\n", lista_tamanho(atual));     // REMOVER
            lista_imprimir(disponiveis);                           // REMOVER
            printf("---\n");                                       // REMOVER
            lista_imprimir(atual);                                 // REMOVER
            printf("----------------------------------------\n");  // REMOVER
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
