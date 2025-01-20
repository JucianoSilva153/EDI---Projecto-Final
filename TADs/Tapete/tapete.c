#include <stdlib.h>
#include <stdio.h>

#include "tapete.h"

#include "../Produto/produto.c";
#include "../Produto/produto.h";

#include "../Fila/fila.c";
#include "../Fila/fila.h";

#include "../Descarte/descarte.c";
#include "../Descarte/descarte.h";

// Inicializa o tapete
Tapete *InicializarTapete()
{
    Tapete *novoTapete = (Tapete *)malloc(sizeof(Tapete));
    if (novoTapete)
    {
        novoTapete->Produto = NULL;
        novoTapete->prox = novoTapete;
        return novoTapete;
    }

    return NULL;
}

// Adiciona um produto ao tapete
char *AdicionarProduto(Tapete *tapete, Produto *novoProduto)
{
    Tapete *novoTapete = InicializarTapete();
    if (novoTapete == NULL)
        return "Erro ao adicionar Produto";

    if (tapete->Produto == NULL)
    {
        tapete->Produto = novoProduto;
        return "Produto Adicionado!!";
    }
    else
    {
        if (tapete->prox == tapete)
        {
            novoTapete->Produto = novoProduto;
            novoTapete->prox = tapete;
            tapete->prox = novoTapete;

            return "Produto Adicionado!!";
        }

        Tapete *aux = tapete;
        while (aux->prox != tapete)
        {
            aux = aux->prox;
            if (aux->prox == tapete)
            {
                novoTapete->Produto = novoProduto;
                novoTapete->prox = tapete;
                aux->prox = novoTapete;

                return "Produto Adicionado!!";
            }
        }
    }

    return "Ocorreu um erro inesperado ao tentar adicionar Produto";
}

// Verifica a existencia de algum produto fora do padrao
//[ 0 - Produto Invalido | 1 - Produto Valido ]
int ValidarProduto(Produto *produto)
{
    if (produto->Peso < 0 || produto->Tipo == NULL)
    {
        return 0;
    }
    else if (produto->Tipo != "PA" || produto->Tipo != "PB" || produto->Tipo != "PC")
    {
        return 0;
    }

    if (produto->Tipo == "PA")
    {
        if (produto->Peso > MAX_PESO_A)
            return 0;
    }
    else if (produto->Tipo == "PB")
    {
        if (produto->Peso > MAX_PESO_B)
            return 0;
    }
    else if (produto->Tipo == "PC")
    {
        if (produto->Peso > MAX_PESO_C)
            return 0;
    }

    return 1;
}

// Encaminha os produtos para as máquinas correspondentes
char *EncaminharProdutos(Tapete *tapete, Maquinas maquinas)
{
    Tapete *aux = tapete;
    while (aux->prox != tapete)
    {
        if (ValidarProduto(aux->Produto) == 0)
        {
            // Manda produto para a Lista de descarte
            return "Produto Invalido, descartado!!";
        }

        Maquina *maquina = RetornarMaquinaPeloProduto(maquinas, aux->Produto->Tipo);
        if (maquina == NULL)
        {
            return "Nenhuma Maquina Disponivel";
        }

        return EncaminharProduto(maquina->Fila, aux->Produto);
    }
}

// Imprime os produtos no tapete
void ImprimirTapete(Tapete *tapete)
{
    if (tapete->Produto == NULL)
    {
        return "Tapete Vazio";
    }

    int count = 1;
    Tapete *aux = tapete;
    while (aux->prox != tapete)
    {
        printf("Produto-%d | Tipo %s | Peso %f\n", count, aux->Produto->Tipo, aux->Produto->Peso);
        aux = aux->prox;
    }

    printf("\n\n%d produtos no tapete!", count);
}