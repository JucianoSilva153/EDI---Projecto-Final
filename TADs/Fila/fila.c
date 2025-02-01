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
Fila *EncaminharProduto(Fila *fila, Produto *produto)
{
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL)
    {
        printf("Erro ao adicionar Produto a maquina");
        return fila;
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

    printf("\nProduto '%s' Adicionado a Fila de maquina respectiva!\n", produto->Nome);
    return fila;
}