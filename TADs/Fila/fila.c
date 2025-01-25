#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

Fila* InicializaFila(){
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    if(fila){
        fila->quantidade = 0;
        fila->inicio = NULL;
        fila->fim = NULL;
        return fila;
    }
    return NULL;
}

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