#include "lista.h"

#include <stdlib.h>
#include <stdio.h>


void CriaMatriz(Matriz *m, int *row, int *col){
    //Cria uma cabeça e faz a cauda apontar para ela
    m->cabeca = (Celula *)malloc(sizeof(Celula));
    m->cauda = m->cabeca;
    m->cabeca->prox = m->cabeca;
    m->cabeca->baixo = m->cabeca;
    
    // valores de linhas e colunas
    printf("\nDigite o numero de linhas e colunas da matriz: ");
    scanf("%d %d", row, col);

    // cria as celulas da coluna
    for (int i = 0; i < *col; i++) {
        m->cauda->prox = (Celula *)calloc(1, sizeof(Celula));
        m->cauda = m->cauda->prox;
        m->cauda->prox = m->cabeca;
        m->cauda->baixo = m->cauda;
        m->cauda->col_pos = -1;
    }
    
    // cria as celulas da linha
    m->cauda = m->cabeca;
    for (int i = 0; i < *row; i++) {
        m->cauda->baixo = (Celula *)calloc(1, sizeof(Celula));
        m->cauda = m->cauda->baixo;
        m->cauda->baixo = m->cabeca;
        m->cauda->prox = m->cauda;
        m->cauda->row_pos = -1;
    }
    
    // ler um valor de linha coluna e valor e adicionar na matriz na posição correta
    int linha, coluna, valor, nElements;
    printf("\nDigite o numero de elementos da matriz: ");
    scanf("%d", &nElements);
    do {// ler os valores e criar as celulas
        printf("\nDigite a linha: ");
        scanf("%d", &linha);
        printf("\nDigite a coluna: ");
        scanf("%d", &coluna);
        printf("\nDigite a valor: ");
        scanf("%d", &valor);
        // cria uma celula
        Celula *nova = (Celula *)malloc(sizeof(Celula));
        nova->item.numero = valor;
        nova->row_pos = linha;
        nova->col_pos = coluna;
        
        // INSERIR CELULA
        // percorre a linha
        Celula *aux = m->cabeca;
        Celula *aux2;
        for (int i = 0; i < linha; i++) {
            aux = aux->baixo;
        }
        // achar a posiçao da coluna
        aux2 = aux;
        while (aux != aux2->prox) {
            aux = aux->prox;
        }
        aux2->prox = nova;
        nova->prox = aux;
        // percorre a coluna
        aux = m->cabeca;
        for (int i= 0; i < coluna; i++) {
            aux = aux->prox;
        }
        // achar a posiçao da linha
        aux2 = aux;
        while (aux != aux2->baixo) {
            aux = aux->baixo;
        }
        aux2->baixo = nova;
        nova->baixo = aux;
        // FIM INSERIR CELULA

        //printf("\nrow_pos: %d - col_pos: %d - valor: %d\n", nova->row_pos, nova->col_pos, nova->item.numero);
        nElements--;
    } while (nElements > 0);
}

void ImprimeMatrizEsparsa(Matriz *m, int row, int col){
    int i= 1, j = 1;
    Celula *aux = m->cabeca->baixo;
    Celula *aux2 = aux->prox;
    for(i = 1; i <= row; i++){
        for(j = 1; j <= col; j++){
            if(aux2->row_pos == i && aux2->col_pos == j){
                printf("%d ", aux2->item.numero);
                aux2 = aux2->prox;
            }else{
                printf("0 ");
            }
        }
        printf("\n");
        aux = aux->baixo;
        aux2 = aux->prox;
    }
}

void LiberaMemoria(Matriz *m){
    Celula *aux = m->cabeca->baixo;
    Celula *aux2;
    while (aux->row_pos != -1) {
        aux2 = aux->prox;
        while (aux2->col_pos != -1) {
            free(aux2);
            aux2 = aux2->prox;
        }
        aux = aux->baixo;
    }
    free(m->cabeca);
}