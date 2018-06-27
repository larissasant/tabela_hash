#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashDu.h"


Has* cria(int valor){
    int n, i;
    Has * novo = (Has* )malloc(sizeof(Has));
    novo->valor = (info* )malloc(n* sizeof(info));
    for (i = 0 ; i<n; i++)
        strcpy(novo->valor[i].nome,"-1");
    novo->size = n;
    return novo;
}

Has* insere(Has* has_d, char* info){
    int i=1, res;
    res = (int)info[0] % has_d->size;
    while (res <= has_d->size && strcmp(has_d->valor[res].nome,"-1") !=0 &&  strcmp(has_d->valor[res].nome ,"-2")!=0){
        res = (res + i * (1+(((int)info[0]) % ((has_d->size)-2))))% has_d->size;
        i++;
    }
    if(strcmp(has_d->valor[res].nome,"-1")==0 || strcmp(has_d->valor[res].nome,"-2")==0)
        strcpy(has_d->valor[res].nome, info);
    else
        return has_d;
}

Has* remover(Has* has_d, char* info){
    int i=1, res;
    res = (int)info[0] % has_d->size;
    while (res<= has_d->size && strcmp(has_d->valor[res].nome, info)!=0) {
        res = (res + i * (1+ (((int)info[0]) % ((has_d->size)-2))))% has_d->size;
        i++;
    }
    if (strcmp(has_d->valor[res].nome, info)==0)
        strcpy(has_d->valor[res].nome, "-2");
    else
        return has_d;
}

void imprimir(Has* has_d) {
    for (int i = 0; i < has_d->size; i++) {
        if (strcmp(has_d->valor[i].nome,"-1")==0 || strcmp(has_d->valor[i].nome,"-2")==0)
            printf("\n");
         else
            printf("posicao:%d nome : %s \n",i,has_d->valor[i].nome);

    }
}
