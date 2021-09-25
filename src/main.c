#include <stdio.h>

#include "adjacence-list.h"
#include "matriz.h"
#include "caixeiro.h"

int main()
{   
    MATRIZ *distancias = caixeiro_ler_dados();

    matriz_imprimir(distancias);

    matriz_limpar(distancias);

    return 0;
}
