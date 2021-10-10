#include <stdio.h>
#include <stdlib.h>

#include "adjacencia.h"
#include "vertice.h"

int main() {
    int n_cidades;
    ADJACENCIA *custos = adjacencia_criar();
    int origem, destino, custo;

    scanf("%d", &n_cidades);
    printf("cidades: %d\n", n_cidades);
    while (scanf("%d %d %d", &origem, &destino, &custo) != EOF) {
        VERTICE *v = vertice_criar(origem, destino, custo);
        if (!adjacencia_adicionar_vertice(custos, v)) {
            exit(EXIT_FAILURE);
        }
    }

    adjacencia_imprimir(custos);
    return EXIT_SUCCESS;
}
