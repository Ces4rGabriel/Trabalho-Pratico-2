#include <stdlib.h>
#include <stdio.h>
#include "lista.h"


int main(){
    int row, col, n;
    char op;
    Matriz a, b;
    scanf("%d %c", &n, &op);
    switch (op)
    {
    case 'T':
        scanf("%d %d", &row, &col); // ler a linha e a coluna
        CriaMatriz(&a, row, col); // cria a moldura da matriz
        LeValores(&a); // le o numero de elementos e insere na matriz
        MatrizTransposta(&a, row, col);
        LiberaMemoria(&a, row, col); 
        break;
    case 'S':
        // soma n matrizes
        CriaMatriz(&b, row, col);
        while (n > 0){
            scanf("%d %d", &row, &col); // ler a linha e a coluna
            CriaMatriz(&a, row, col);
            LeValores(&a);
            b = SomaMatriz(&a, &b, row, col);
            n--;
        }
        printf("Soma:\n\n");
        ImprimeMatrizEsparsa(&b, row, col);
        LiberaMemoria(&a, row, col);
        LiberaMemoria(&b, row, col);
        break;
    case 'M':
        break;
    }
    //MatrizTransposta(a, row, col);
    return 0;
}