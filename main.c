#include <stdlib.h>
#include <stdio.h>
#include "lista.h"


int main(){
    int row, col;
    Matriz m;
    CriaMatriz(&m, &row, &col);
    ImprimeMatrizEsparsa(&m, row, col);
    LiberaMemoria(&m);
    return 0;
}