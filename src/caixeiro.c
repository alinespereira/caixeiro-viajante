#include "caixeiro.h"

struct _caminho {
    VETOR *cidades;
    int custo;
};

MATRIZ *caixeiro_ler_dados() {
    int tamanho;
    MATRIZ *m = NULL;

    scanf("%d\n", &tamanho);

    m = matriz_criar(tamanho);

    int linha, coluna, valor;
    int contador = (tamanho * tamanho) - tamanho;

    for (int i = 0; i < contador; i++) {
        scanf("%d %d %d\n", &linha, &coluna, &valor);

        if (linha > tamanho || coluna > tamanho) {
            printf("Fora do escopo");
            return NULL;
        }
        matriz_set_entrada(m, linha - 1, coluna - 1, valor);
    }

    return m;
}

CAMINHO *caixeiro_criar_caminho(int n_cidades) {
    CAMINHO *c = (CAMINHO *)malloc(sizeof(CAMINHO));
    c->cidades = vetor_criar(n_cidades);
    c->custo = INT_MAX;

    return c;
}

void caixeiro_calcular_caminhos(MATRIZ *custos, VETOR *disponiveis, CAMINHO **caminho, int *n_caminhos) {
    printf("--------------------------------------------------------------------------------\n");
    printf("calcular novo caminho?\n");
    printf("início: cidades disponiveis = %d\n", vetor_get_tamanho(disponiveis));
    if (vetor_get_tamanho(disponiveis) == matriz_get_tamanho(custos) - 1) {
        printf("criar caminho; cidades disponiveis = %d\n", vetor_get_tamanho(disponiveis));
        (*n_caminhos)++;
        caminho = (CAMINHO **)realloc(caminho, (*n_caminhos) * sizeof(CAMINHO *));
        caminho[(*n_caminhos) - 1] = caixeiro_criar_caminho(1);
        vetor_set_elemento(caminho[(*n_caminhos) - 1]->cidades, 0, 0);
    }

    if (vetor_get_tamanho(disponiveis) > 0) {
        printf("--------------------------------------------------------------------------------\n");
        printf("\tdisponíveis\n");
        vetor_imprimir(disponiveis);
        printf("\trecursão; cidades disponiveis = %d\n", vetor_get_tamanho(disponiveis));
        printf("\tcaminhos calculados = %d\n", *n_caminhos);
        for (int i = 0; i < vetor_get_tamanho(disponiveis); i++) {
            int proxima = vetor_get_elemento(disponiveis, i);
            printf("\t\tproxima: %d\n", proxima);
            vetor_push_elemento(caminho[*n_caminhos - 1]->cidades, proxima);
            vetor_imprimir(caminho[*n_caminhos - 1]->cidades);
            VETOR *curr_disponiveis = vetor_remover_elemento(disponiveis, i);
            printf("\t>>> antes recursão; cidades disponiveis (curr) = %d\n", vetor_get_tamanho(curr_disponiveis));
            caixeiro_calcular_caminhos(custos, curr_disponiveis, caminho, n_caminhos);
            printf("\t>>> após recursão; cidades disponiveis = %d\n", vetor_get_tamanho(disponiveis));
            printf("\t>>> caminhos calculados = %d\n", *n_caminhos);
        }
    } else {
        printf("--------------------------------------------------------------------------------\n");
        printf("fim da recursão; cidades disponiveis = %d\n", vetor_get_tamanho(disponiveis));
        int curr_distancia = caixeiro_calcular_distancia(custos, caminho[*n_caminhos - 1]);
        caminho[*n_caminhos - 1]->custo = curr_distancia;
        caixeiro_imprimir_caminho(caminho[*n_caminhos - 1]);
    }
}

int caixeiro_calcular_distancia(MATRIZ *custos, CAMINHO *caminho) {
    return 0;
}

void caixeiro_imprimir_caminho(CAMINHO *caminho) {
    int n_cidades = vetor_get_tamanho(caminho->cidades);
    printf("caminho: %d", vetor_get_elemento(caminho->cidades, 0) + 1);
    for (int i = 1; i < n_cidades; i++) {
        printf(" -> %d", vetor_get_elemento(caminho->cidades, i) + 1);
    }
    printf(": distancia = %d\n", caminho->custo);
}
