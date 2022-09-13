#include "lista.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int numero;
} Item;

typedef struct celula{
    struct celula *prox;
    struct celula *baixo;
    int row_pos;
    int col_pos;
    Item item;
}Celula;

typedef struct {
    Celula *cabeca;
    Celula *cauda;
} Matriz;

Matriz *CriaMatriz(Matriz *m){
    //Cria uma cabeça e faz a cauda apontar para ela
    m->cabeca = (Celula *)malloc(sizeof(Celula));
    m->cauda = m->cabeca;
    m->cabeca->prox = NULL;
    
    // valores de linhas e colunas
    int row, col;
    scanf("%d %d", &row, &col);

    // cria as celulas da coluna
    for (int i = 1; i <= col; i++) {
        m->cauda->prox = (Celula *)malloc(sizeof(Celula));
        m->cauda = m->cauda->prox;
        m->cauda->prox = m->cabeca;
        m->cauda->col_pos = -1;

    }
    // cria as celulas da linha
    m->cauda = m->cabeca;
    for (int i = 1; i <= row; i++) {
        m->cauda->baixo = (Celula *)malloc(sizeof(Celula));
        m->cauda = m->cauda->baixo;
        m->cauda->baixo = m->cabeca;
        m->cauda->row_pos = -1;
    }
}