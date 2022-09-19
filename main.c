#include <stdlib.h>
#include <stdio.h>
#include "lista.h"


int main(){
    int row, col;
    Matriz m;
    scanf("%d %d", &row, &col);
    CriaMatriz(&m, row, col);
    LeValores(&m);
    ImprimeMatrizEsparsa(&m, row, col);
    printf("\n");
    MatrizTransposta(&m, row, col);
    LiberaMemoria(&m);
    return 0;
}