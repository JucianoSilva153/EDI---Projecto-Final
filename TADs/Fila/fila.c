#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

// Encaminha produto para uma determinada fila de uma maquina
char *EncaminharProduto(Fila *fila, Produto *produto)
{
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL)
    {
        return "Erro ao adicionar Produto";
    }

    novoNo->Produto = produto;
    novoNo->prox = NULL;

    if (fila->inicio == NULL)
    {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    }
    else
    {
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }

    fila->quantidade++;
    return "Produto Adicionado!!";
}