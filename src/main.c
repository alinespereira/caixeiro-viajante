#include <stdio.h>

#include "vetor.h"
#include "matriz.h"
#include "caixeiro.h"

int main()
{
    MATRIZ *distancias = caixeiro_ler_dados();
    int n_caminhos = 0;
    CAMINHO **caminho = NULL;
    int n_cidades = matriz_get_tamanho(distancias);
    VETOR *disponiveis = vetor_criar(n_cidades - 1);

    for (int i = 1; i < n_cidades; i++)
        vetor_set_elemento(disponiveis, i - 1, i);

    matriz_imprimir(distancias);

    caixeiro_calcular_caminhos(distancias, disponiveis, caminho, &n_caminhos);

    matriz_imprimir(distancias);

    matriz_limpar(distancias);

    return 0;
}
