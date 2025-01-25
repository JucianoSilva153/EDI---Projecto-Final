#ifndef FILA_H
#define FILA_H

#include "../Produto/produto.h"

typedef struct no
{
    Produto *Produto;
    struct no *prox;
} No;

typedef struct fila
{
    int quantidade;
    No *inicio;
    No *fim;
} Fila;

char *EncaminharProduto(Fila *fila, Produto *produto);
Fila* InicializaFila();

#endif