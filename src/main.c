#include <stdio.h>

#include "adjacence-list.h"
#include "matriz.h"
#include <stdio.h>

int main()
{
    MATRIZ *m;
    int tamanho;

    scanf("%d\n", &tamanho);
    
    m = matriz_criar(tamanho);

    matriz_preencher(m);

    matriz_imprimir(m);

    matriz_limpar(m);

    return 0;
}
