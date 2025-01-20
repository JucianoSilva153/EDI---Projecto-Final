#include "./Produto/produto.h"

typedef struct fila
{
    int quantidade;
    No *inicio;
    No *fim;
} Fila;

typedef struct no
{
    Produto *Produto;
    struct no *prox;
} No;

char* EncaminharProduto(Fila* fila, Produto* produto);