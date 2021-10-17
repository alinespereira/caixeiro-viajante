#include <stdio.h>
#include <stdlib.h>

#include "adjacencia.h"
#include "caixeiro.h"
#include "lista.h"

int main() {
    int n_cidades;

    scanf("%d", &n_cidades);
    ADJACENCIA *custos = caixeiro_ler_custos();

    LISTA *atual = lista_criar();
    ITEM *partida = item_criar(0, 1);
    lista_inserir_fim(atual, partida);
    lista_imprimir(atual);
    LISTA *disponiveis = lista_criar();
    for (int i = 1; i < n_cidades; i++) {
        ITEM *it = item_criar(i, i + 1);
        lista_inserir_fim(disponiveis, it);
    }
    lista_imprimir(disponiveis);
    CAMINHO *melhor_caminho = caixeiro_criar_caminho();
    caixeiro_calcular_caminhos(custos, n_cidades, atual, disponiveis, melhor_caminho);
    caixeiro_imprimir_caminho(melhor_caminho);

    adjacencia_imprimir(custos);
    adjacencia_apagar(&custos);
    return EXIT_SUCCESS;
}
