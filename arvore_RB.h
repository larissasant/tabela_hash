#ifndef ARVORE_RB_H_INCLUDED
#define ARVORE_RB_H_INCLUDED

typedef enum {
    black = 0, red = 1
} Cor;

typedef struct no {
    int info;
    int cor_no ;
    struct no* pai;
    struct no* esquerda;
    struct no* direita;
}Nodo;


typedef struct arv {
   Nodo* raiz;
   Nodo sentinela;
}Arv;

Arv* cria();
Nodo* criar_nodo(int valor);

Nodo* insere_no(Arv* arv, Nodo* no);
void insere(Arv* arv, Nodo* no);

Nodo* remover_no(Arv* arv, Nodo* no);
void remover(Arv* arv, Nodo* no);

void left_rotate(Arv* arv, Nodo * x);
void right_rotate(Arv* arv, Nodo * x);

int  verificar(Nodo* raiz);
Nodo* buscar_no(Nodo* raiz,int valor);

void imprimir(Arv* arv, int valor);
void imprimir_PreOrdem(Nodo* raiz);

void libera(Arv* arv);
void liberar_no(Nodo* raiz);

#endif // ARVORE_RB_H_INCLUDED
