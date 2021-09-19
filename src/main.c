#include <stdio.h>

#include "adjacence-list.h"
#include "matriz.h"
#include <stdio.h>

int main()
{
    MATRIZ *m;

    printf("teste");
    
    m = matriz_criar(3);
    matriz_imprimir(m);

    matriz_preencher(m);

    matriz_imprimir(m);

    matriz_limpar(&m);

    return 0;
}
