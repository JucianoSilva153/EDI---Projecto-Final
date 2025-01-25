#include <stdlib.h>
#include <stdio.h>

#include "tapete.h"

#include "../Utils/utils.c"

#include "../Produto/produto.h"

#include "../Fila/fila.h"

#include "../Descarte/descarte.c"

// Cria a Lista de Descarte previamente
Descartados *ListaDescarte = NULL;

// Inicializa o tapete
Tapete *InicializarTapete()
{
    Tapete *novoTapete = (Tapete *)malloc(sizeof(Tapete));
    ListaDescarte = InicializarDescartados();

    // Verifica se o tapete e a lista de descarte foram criados com sucesso
    if (novoTapete && ListaDescarte)
    {
        novoTapete->Produto = NULL;
        novoTapete->prox = novoTapete;
        return novoTapete;
    }

    return NULL;
}

// Adiciona um produto ao tapete
Tapete *AdicionarProduto(Tapete *tapete, Produto *novoProduto)
{
    Tapete *novoTapete = InicializarTapete();
    if (novoTapete == NULL){
        printf("Erro ao adicionar produto ao tapete\n");
        return tapete;
    }

    if (tapete->Produto == NULL)
    {
        tapete->Produto = novoProduto;
        printf("Produto Adicionado!!\n");
        return tapete;
    }
    else
    {
        if (tapete->prox == tapete)
        {
            novoTapete->Produto = novoProduto;
            novoTapete->prox = tapete;
            tapete->prox = novoTapete;

            printf("Produto Adicionado!!\n");
            return tapete;
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

                printf("Produto Adicionado!!\n");
                return tapete;
            }
        }
    }

    printf("Ocorreu um erro inesperado ao tentar adicionar Produto\n");
    return tapete;
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
char *EncaminharProdutos(Tapete *tapete, Maquinas *maquinas)
{
    Tapete *aux = tapete;
    while (aux->prox != tapete)
    {
        if (ValidarProduto(aux->Produto) == 0)
        {
            // Manda produto para a Lista de descarte
            DescartarProduto(ListaDescarte, aux->Produto);
            return "Produto Invalido, descartado!!";
        }

        Maquina *maquina = RetornarMaquinaPeloProduto(maquinas, aux->Produto->Tipo);
        if (maquina == NULL)
        {
            return "Nenhuma Maquina Disponivel";
        }

        return EncaminharProduto(maquina->Fila, RemoverProdutoDoTapete(&tapete));
    }
}

// Imprime os produtos no tapete
void ImprimirTapete(Tapete *tapete)
{
    if (tapete->Produto == NULL)
    {
        printf("Tapete Vazio!!\n");
        return;
    }

    int count = 1;
    Tapete *aux = tapete;
    while (aux->prox != tapete)
    {
        printf("%d - %s | Tipo %s | Peso %f\n", count, aux->Produto->Nome, aux->Produto->Tipo, aux->Produto->Peso);
        aux = aux->prox;
        count++;
    }

    printf("\n\n%d produtos no tapete!", count);
}

void ImprimirDescartados(){
    Descarte *aux = ListaDescarte->descarte;
    if (aux == NULL)
    {
        printf("Nenhum Produto Descartado\n");
        return;
    }
    printf("\nProdutos Descartados\n");
    while (aux != NULL)
    {
        printf("Nome: %s\n", aux->produto->Nome);
        printf("Tipo: %s\n", aux->produto->Tipo);
        printf("Peso: %.2f\n", aux->produto->Peso);
        printf("\n");
        aux = aux->prox;
    }
}