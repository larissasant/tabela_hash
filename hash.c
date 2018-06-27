#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "has.h"
#include "te.h"

hash_n* criar_has(int valor){
    hash_n* novo = (hash_n *)malloc(sizeof(hash_n));
    novo->tabela = (Arv**)malloc(valor* sizeof(Arv));
    for (int i = 0 ; i<valor; i++)
        novo->tabela[i]=cria();
    novo->size = valor;
    return novo;
}

void inserir_has(hash_n* has, int valor){
     int x;
     x = valor%has->size;
     has->tabela[x]->raiz = insere_no (has->tabela[x],criar_nodo(valor));
}

void remover_has(hash_n* has, int valor){
    int x;
    x = valor%has->size;
    has->tabela[x]->raiz = remover_no(has->tabela[x],criar_nodo(valor));

}

void imprimir_has(hash_n* has){
    int escolha;
    printf("Escolha o tipo de impressao: ");
    printf("\n 1- PreOrdem\n 2-EmOrdem\n 3-PosOrdem\n");
    scanf("%d", &escolha);
    if (escolha == 1) {
        imprimir_PreOrdem_has(has);
    } else if (escolha == 2) {
        imprimir_EmOrdem_has(has);
    } else if (escolha == 3) {
        imprimir_PosOrdem_has(has);
    } else
    printf("\n");
}

void imprimir_PreOrdem_has(hash_n* has){
    for (int i =0; i< has->size; i++){
        printf("Posicao %d\n", i);
        imprimir(has->tabela[i],1);
        printf("\n");
    }
}


void imprimir_EmOrdem_has(hash_n* has){
    for (int i =0; i< has->size; i++){
        printf("Posicao %d\n", i);
        imprimir(has->tabela[i],2);
        printf("\n");
    }

}

void imprimir_PosOrdem_has(hash_n* has){
    for (int i =0; i< has->size; i++){
        printf("Posiçao %d\n",i);
        imprimir(has->tabela[i],3);
        printf("\n");
    }

}


