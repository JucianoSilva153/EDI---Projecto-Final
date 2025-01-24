#include <stdio.h>
#include <stdlib.h>

#include "produto.h"



// Inicializa um produto
Produto *InicializarProduto()
{
    Produto *produto = (Produto *)malloc(sizeof(Produto));

    if (produto)
    {
        produto->Tipo = NULL;
        produto->Peso = 0;

        return produto;
    }

    return NULL;
}

// Cria um produto
Produto *CriarProduto(char* nome ,char *tipo, float peso)
{
    Produto *produto = InicializarProduto();

    if (produto)
    {
        produto->Nome = nome;
        produto->Tipo = tipo;
        produto->Peso = peso;

        return produto;
    }

    return NULL;
}