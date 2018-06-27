#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "arvore_RB.h"
#include "has.h"

int main() {
    int tam;
    printf("\t____________Tabela Hash______________\n\n");
    printf("digite o tamanho:\n");

    scanf("%d",&tam);
    hash_n * Pai = criar_has(tam);

    for (int i = 0; i < (tam*3);i++){
            int valor;
            valor =  rand()%10;
            inserir_has(Pai, valor);
    }
    imprimir_has(Pai);
    return 0;

}
