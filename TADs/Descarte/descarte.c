#include<stdlib.h>
#include "descarte.h"

Descarte *InicializarDescarte()
{
    Descarte *novoDescarte = (Descarte *)malloc(sizeof(Descarte));
    if (novoDescarte)
    {
        novoDescarte->produto = NULL;
        novoDescarte->prox = NULL;
        return novoDescarte;
    }
    return NULL;
}
Descartados *InicializarDescartados()
{
    Descartados *novoDescartados = (Descartados *)malloc(sizeof(Descartados));
    if (novoDescartados)
    {
        novoDescartados->quantidade = 0;
        novoDescartados->descarte = NULL;
        return novoDescartados;
    }
    return NULL;
}

char *DescartarProduto(Descartados *descartados, Produto *produto)
{
    Descarte *novoDescarte = InicializarDescarte();

    if (novoDescarte == NULL)
        return "Erro ao descartar Produto";

    if (descartados->descarte == NULL)
    {
        novoDescarte->produto = produto;
        descartados->descarte = novoDescarte;
        descartados->quantidade++;

        if (produto->Tipo == "PA")
        {
            int pa = descartados->produtosPA + 1;
            descartados->produtosPA = pa;
        }
        else if (produto->Tipo == "PB")
        {
            int pb = descartados->produtosPB + 1;
            descartados->produtosPB = pb;
        }
        else if (produto->Tipo == "PC")
        {
            int pc = descartados->produtosPC + 1;
            descartados->produtosPC = pc;
        }

        return "Produto Descartado!!";
    }
    else
    {
        Descarte *aux = descartados->descarte;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novoDescarte;
        descartados->quantidade++;
        return "Produto Descartado!!";
    }
}