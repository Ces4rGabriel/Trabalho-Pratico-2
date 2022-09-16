#include <stdlib.h>
#include <stdio.h>
#include "lista.h"


int main(){
    Matriz m;
    CriaMatriz(&m);
    ImprimeMatrizEsparsa(&m);
    LiberaMemoria(&m);
    return 0;
}