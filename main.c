#include <stdlib.h>
#include <stdio.h>
#include "lista.h"


int main(){
    int row, col, n;
    char op;
    Matriz a, b, c;
    scanf("%d %c", &n, &op);
    switch (op)
    {
    case 'T':
        scanf("%d %d", &row, &col);
        CriaMatriz(&a, row, col);
        LeValores(&a);
        MatrizTransposta(&a, row, col);
        LiberaMemoria(&a, row, col);
        break;
    case 'S':
        // soma n matrizes
        while (n > 0){
            
            n--;
        }
        

        break;
    case 'M':
        break;
    }
    //MatrizTransposta(a, row, col);
    return 0;
}