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
    //printf("\nDigite o numero de linhas e colunas da matriz: ");
    
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
}

void LeValores(Matriz *m){ 
    // ler um valor de linha coluna e valor e adicionar na matriz na posição correta
    int linha, coluna, valor, nElements;
    //printf("\nDigite o numero de elementos da matriz: ");
    scanf("%d", &nElements);
    do {// ler os valores e criar as celulas
        //printf("\nDigite a linha coluna e valor: ");
        scanf("%d %d %d", &linha, &coluna, &valor);
        InsereCelula(m, linha, coluna, valor);
        nElements--;
    } while (nElements > 0);
}
void InsereCelula(Matriz* m, int row, int col, int valor){
        // cria uma celula
        Celula *nova = (Celula *)malloc(sizeof(Celula));
        nova->item.numero = valor;
        nova->row_pos = row;
        nova->col_pos = col;
        
        // INSERIR CELULA
        // percorre a linha
        Celula *aux = m->cabeca;
        Celula *aux2;
        for (int i = 0; i < row; i++) {
            aux = aux->baixo;
        }
        // achar a posiçao da coluna
        aux2 = aux;
        while (aux != aux2->prox) {
            aux2 = aux->prox;
        }
        aux2->prox = nova;
        nova->prox = aux;
        // percorre a coluna
        aux = m->cabeca;
        for (int i = 0; i < col; i++) {
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

void ImprimeMatrizEsparsa(Matriz *m, int row, int col){
    int i, j;
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

void MatrizTransposta(Matriz *m, int row, int col){
    int i, j;
    Matriz t;
    CriaMatriz(&t, &col, &row);
    // passar valores da matriz m para matriz tranposta
    Celula *aux = m->cabeca->prox;
    Celula *aux2 = aux->baixo;
    for(i = 1; i <= col; i++){
        for(j = 1; j <= row; j++){
            if(aux2->row_pos == j && aux2->col_pos == i){
                InsereCelula(&t, i, j, aux2->item.numero);
                aux2 = aux2->baixo;
            }
        }
        aux = aux->prox;
        aux2 = aux->baixo;
    }
        


    ImprimeMatrizEsparsa(&t, col, row);
    LiberaMemoria(&t);
}