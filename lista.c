#include "lista.h"

#include <stdlib.h>
#include <stdio.h>


void CriaMatriz(Matriz *m){
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
    
    // ler um valor de linha coluna e valor e adicionar na matriz na posição correta
    int linha, coluna, valor;
    scanf("%d %d %d", &linha, &coluna, &valor);
    while (linha != 0 && coluna != 0 && valor != 0) {
        // cria uma celula
        Celula *nova = (Celula *)malloc(sizeof(Celula));
        nova->item.numero = valor;
        nova->row_pos = linha;
        nova->col_pos = coluna;
        
        // percorre a linha
        Celula *aux = m->cabeca->baixo;
        while (aux->row_pos != linha) {
            aux = aux->baixo;
        }
        while (aux->prox->col_pos < coluna) {
            aux = aux->prox;
        }
        nova->prox = aux->prox;
        aux->prox = nova;
        
        // percorre a coluna
        aux = m->cabeca->prox;
        while (aux->col_pos != coluna) {
            aux = aux->prox;
        }
        while (aux->baixo->row_pos < linha) {
            aux = aux->baixo;
        }
        nova->baixo = aux->baixo;
        aux->baixo = nova;
    }
}

