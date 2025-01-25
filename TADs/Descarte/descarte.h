#ifndef DESCARTE_H
#define DESCARTE_H
#include "../Produto/produto.h"

typedef struct descarte
{
    Produto *produto;
    struct descarte *prox;
} Descarte;

typedef struct descartados
{
    int quantidade;
    int produtosPA;
    int produtosPB;
    int produtosPC;
    Descarte *descarte;
} Descartados;


Descarte *InicializarDescarte();
Descartados *InicializarDescartados();


char *DescartarProduto(Descartados *descartados, Produto *produto);
#endif