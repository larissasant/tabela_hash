#ifndef HASHDU_H_INCLUDED
#define HASHDU_H_INCLUDED

typedef struct info{
    char nome[20];
}info;

typedef struct Has{
    info* valor;
    int size;
}Has;

Has* cria(int valor);
Has* insere(Has *has_d, char* info);
Has* remover(Has *has_d, char* info);

void imprimir(Has* H);

#endif // HASHDU_H_INCLUDED
