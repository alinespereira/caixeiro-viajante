#include <stdio.h>
#include <stdlib.h>

#include "adjacencia.h"
#include "aresta.h"

int main() {
    int n_cidades;

    scanf("%d", &n_cidades);
    printf("cidades: %d\n", n_cidades);
    ADJACENCIA *custos = caixeiro_ler_custos();

    adjacencia_imprimir(custos);
    adjacencia_apagar(&custos);
    return EXIT_SUCCESS;
}
