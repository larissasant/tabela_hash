#ifndef HAS_H_INCLUDED
#define HAS_H_INCLUDED
#include "arvore_RB.h"

typedef struct hash{
    Arv **tabela;
    int size;
}hash_n;

hash_n* criar_has(int valor);

void insere_has(hash_n* has, int valor);
void remover_has(hash_n* has, int valor);

void imprimir_has(hash_n* has);
void imprimir_PreOrdem_has(hash_n* has);
void imprimir_EmOrdem_has(hash_n* has);
void imprimir_PosOrdem_has(hash_n* has);


#endif // HASH_H_INCLUDED

