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
    Celula *ini;
    Celula *fim;
} Matriz;

Matriz* ListaInicia();


#endif // lista_h