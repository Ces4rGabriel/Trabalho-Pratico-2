#ifndef lista_h
#define lista_h

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

void CriaMatriz(Matriz*, int*, int*);

void ImprimeMatrizEsparsa(Matriz*, int, int);

void LiberaMemoria(Matriz*);

void MatrizTransposta(Matriz*, int, int);

void InsereCelula(Matriz*, int, int, int);

void LeValores(Matriz *m);


#endif // lista_h