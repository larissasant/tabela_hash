#include <stdio.h>
#include <stdbool.h>
#include "hashDu.h"

int main() {
    Has* Pai = cria(10);
    insere(Pai, 1);
    insere(Pai, 2);
    insere(Pai, 3);
    insere(Pai, 4);

    remover(Pai, 2);

    imprimir(Pai);



    return 0;
}
