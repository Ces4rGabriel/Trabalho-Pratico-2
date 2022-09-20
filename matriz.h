#ifndef matriz_h
#define matriz_h

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

void CriaMatriz(Matriz*, int, int);

void ImprimeMatrizEsparsa(Matriz*, int, int);

void LiberaMemoria(Matriz*, int, int);

void MatrizTransposta(Matriz*, int, int);

void InsereCelula(Matriz*, int, int, int);

void LeValores(Matriz *m);

Matriz SomaMatriz(Matriz*, Matriz *, int, int);


#endif // lista_h