#include <stdio.h>
#include <stdlib.h>
#include "arvore_RB.h"


Arv* cria(){
     Arv *arv_RB = (Arv *) malloc(sizeof(Arv));
     arv_RB->raiz = NULL;
     return arv_RB;
}

Nodo *criar_nodo(int valor){
    Nodo *novo = (Nodo *) malloc(sizeof(Nodo));
    novo->info = valor;
    novo->esquerda = novo->direita = novo->pai = NULL;
    novo->cor_no = red;
    return novo;
}

Nodo* insere_no(Arv* arv, Nodo* no){
    Nodo *y = NULL;
    Nodo *x = arv->raiz;
    while (x != NULL) {
        y = x;
        if (no->info < x->info) {
            x = x->esquerda;
        } else
            x = x->direita;
    }
    no->pai = y;
    if (y == NULL) {
        arv->raiz = no;
    } else if (no->info < y->info) {
        y->esquerda = no;
    } else {
        y->direita = no;
    }
    insere(arv, no);
    return arv->raiz;
}


void insere(Arv* arv, Nodo *no){
    ///1 caso:
    // primeiro caso:
    while (no != arv->raiz && no->pai->cor_no == red) {
        if (no->pai->pai->esquerda == no->pai) {
            Nodo *y = no->pai->pai->direita;
            if (y != NULL && y->cor_no == red) {
                no->pai->cor_no = black;
                y->cor_no = black;
                no->pai->pai->cor_no = red;
                no = no->pai->pai;
                // segundo caso:
            } else {
                if (no == no->pai->direita) {
                    no = no->pai;
                    left_rotate(arv, no);
                }
                //terceiro caso:
                no->pai->cor_no = black;
                no->pai->pai->cor_no = red;
                right_rotate(arv, no->pai->pai);
            }

        } else {
            ///2 caso
            //primeiro caso
            Nodo *y = no->pai->pai->esquerda;
            if (y != NULL && y->cor_no == red) {
                no->pai->cor_no = black;
                y->cor_no = black;
                no->pai->pai->cor_no = red;
                no = no->pai->pai;
                //segundo caso
            } else {
                if (no == no->pai->esquerda) {
                    no = no->pai;
                    right_rotate(arv, no);
                }
                //terceiro caso
                no->pai->cor_no = black;
                no->pai->pai->cor_no = red;
                left_rotate(arv, no->pai->pai);
            }
        }
    }
    arv->raiz->cor_no = black;
}


Nodo* remover_no(Arv* arv, Nodo* no){
    while (no!= NULL){
        Nodo* y = no->pai;
        Nodo* x = no;
        int n = verificar(x);
        if (n == 0) {
            if (y->esquerda == x)
                y->esquerda = NULL;
            else
                y->direita = NULL;
            free(x);
           remover(arv, y);
        }
        if (n == 1) {
            if (x->esquerda){
                Nodo *aux = x;
                x = x->esquerda;
                free(aux);
            } else{
                Nodo *aux2 = x;
                x = x->direita;
                free(aux2);
            }
        }
        if (n == 2){
            Nodo *p = x->esquerda;
            while (p->direita != NULL){
                p = p->direita;
            }
            x->info = p->info;
            p->info = no->info;
            no = p;
            y = no->pai;
        }

    }
    return arv->raiz;
}

void remover(Arv* arv, Nodo* no){
    if (no->pai->esquerda == no){
        Nodo *Pai = no->pai;
        Nodo *Irmao = no->pai->direita;
        if (Irmao->cor_no == red) {
            Irmao->cor_no = black;
            Pai->cor_no = red;
            left_rotate(arv, Irmao);
        }
        if (Irmao->cor_no == black && Pai->cor_no == black){
            Irmao->cor_no = red;
            no = Pai;
            remover(arv, no);
        }
        if (Irmao->cor_no == black && Pai->cor_no == red && Irmao->esquerda->cor_no ==black && Irmao->direita->cor_no == black){
            Irmao->cor_no = red;
            Pai->cor_no = black;
        }
        if (Irmao->cor_no == black && Irmao->esquerda->cor_no == red && Irmao->direita->cor_no == black){
            Irmao->esquerda->cor_no = black;
            Irmao->cor_no = red;
            right_rotate(arv, Irmao);
            remover(arv, no);
        }
        if (Irmao->cor_no == black && Irmao->direita->cor_no == red){
            Irmao->cor_no = Pai->cor_no;
            Pai->cor_no = black;
            Irmao->direita = black;
            left_rotate(arv, Irmao);
        }

    } else {

        Nodo *Pai = no->pai;
        Nodo *Irmao = no->pai->esquerda;
        if (Irmao->cor_no == red){
            Irmao->cor_no = black;
            Pai->cor_no = red;
            right_rotate(arv, Irmao);
        }
        if (Irmao->cor_no == black && Pai->cor_no == black){
            Irmao->cor_no = red;
            no = Pai;
            remover(arv, no);
        }
        if (Irmao->cor_no == black && Pai->cor_no == red && Irmao->direita->cor_no == Irmao->esquerda->cor_no == black){
            Irmao->cor_no = red;
            Pai->cor_no = black;
        }
        if (Irmao->cor_no == black && Irmao->direita->cor_no == red && Irmao->esquerda->cor_no == black){
            Irmao->direita->cor_no = black;
            Irmao->cor_no = red;
            right_rotate(arv, Irmao);
            remover(arv, no);
        }
        if (Irmao->cor_no == black && Irmao->esquerda->cor_no == red){
            Irmao->cor_no = Pai->cor_no;
            Pai->cor_no = black;
            Irmao->esquerda = black;
            left_rotate(arv, Irmao);
        }
    }

}

void left_rotate(Arv* arv, Nodo *x){
    Nodo *y = x->direita;
    x->direita = y->esquerda;
    if (y->esquerda != NULL){
        y->esquerda->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == NULL) {
        arv->raiz = y;
    } else if (x->pai->esquerda == x) {
        x->pai->esquerda = y;
    } else
        x->pai->direita = y;
    y->esquerda = x;
    x->pai = y;
}

void right_rotate(Arv* arv, Nodo *x) {
    Nodo *y = x->esquerda;
    x->esquerda = y->direita;
    if (y->direita != NULL) {
        y->direita->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == NULL) {
        arv->raiz = y;
    } else if (x->pai->direita == x) {
        x->pai->direita = y;
    } else
        x->pai->esquerda = y;
    y->direita = x;
    x->pai = y;
}


Nodo* buscar_no(Nodo *raiz, int valor) {
    if (raiz == NULL || raiz->info == valor) {
        return raiz;
    } else if (valor < raiz->info) {
        return buscar_no(raiz->esquerda, valor);
    } else {
        return buscar_no(raiz->direita, valor);
    }
}



int verificar(Nodo *raiz) {
    if (raiz->esquerda != NULL && raiz->direita == NULL) {
        return 1;
    }
    if (raiz->esquerda == NULL && raiz->direita != NULL) {
        return 1;
    }
    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        return 0;
    }
    if (raiz->esquerda != NULL && raiz->direita != NULL) {
        return 2;
    }
}


void imprimir(Arv* arv, int escolha){
    if (escolha == 1) {
        imprimir_PreOrdem(arv->raiz);
    } else if (escolha == 2) {
        imprimir_EmOrdem(arv->raiz);
    } else if (escolha == 3) {
        imprimir_PosOrdem(arv->raiz);
    } else
    printf("\n");
}

void imprimir_PreOrdem(Nodo *raiz){
    if (raiz != NULL) {
        printf("%d\n", raiz->info);
        imprimir_PreOrdem(raiz->esquerda);
        imprimir_PreOrdem(raiz->direita);
    }

}

void imprimir_EmOrdem(Nodo *raiz){
    if (raiz != NULL) {
        imprimir_EmOrdem(raiz->esquerda);
        printf("%d\n", raiz->info);
        imprimir_EmOrdem(raiz->direita);
    }

}

void imprimir_PosOrdem(Nodo *raiz){
    if (raiz != NULL) {
        imprimir_PosOrdem(raiz->esquerda);
        imprimir_PosOrdem(raiz->direita);
        printf("%d\n", raiz->info);
    }

}

void liberar(Arv* arv){
    liberar_no(arv->raiz);
    free(arv);
}

void liberar_no(Nodo *raiz){
    while (raiz != NULL){
        liberar_no(raiz->esquerda);
        liberar_no(raiz->direita);
        free(raiz);
    }
}
