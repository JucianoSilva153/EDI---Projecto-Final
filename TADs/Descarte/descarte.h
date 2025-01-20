#include "./Produto/produto.h"
#include "./Produto/produto.c"

typedef struct descarte
{
    Produto *produto;
    struct descarte *prox;
} Descarte;

typedef struct descartados
{
    int quantidade;
    Descarte *descarte;
} Descartados;


Descarte *InicializarDescarte();
Descartados *InicializarDescartados();

Descartados *DescartarProduto(Descartados *descartados, Produto *produto);
