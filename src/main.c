#include <stdio.h>
#include <stdlib.h>

#include "adjacencia.h"
#include "caixeiro.h"
#include "lista.h"

int main() {
    int n_cidades;

    scanf("%d", &n_cidades);
    ADJACENCIA *custos = caixeiro_ler_custos();

    LISTA *cidades = lista_criar();
    for (int i = 0; i < n_cidades; i++) {
        ITEM *it = item_criar(i, i + 1);
        lista_inserir_fim(cidades, it);
    }

    CAMINHO *melhor_caminho = caixeiro_criar_caminho();
    caixeiro_calcular_caminhos(custos, cidades, melhor_caminho);
    caixeiro_imprimir_caminho(melhor_caminho);

    caminho_apagar(&melhor_caminho);
    adjacencia_apagar(&custos);
    lista_apagar(&cidades);
    return EXIT_SUCCESS;
}
