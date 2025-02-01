#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    if (novoTapete == NULL)
    {
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
#include <stdio.h>
#include <string.h>

int ValidarProduto(Produto *produto)
{
    if (produto->Peso < 0 || produto->Tipo == NULL)
    {
        return 0;
    }

    // Correção da validação do tipo
    if (strcmp(produto->Tipo, "PA") != 0 &&
        strcmp(produto->Tipo, "PB") != 0 &&
        strcmp(produto->Tipo, "PC") != 0)
    {
        return 0;
    }

    // Verificação do peso conforme o tipo do produto
    if (strcmp(produto->Tipo, "PA") == 0)
    {
        if (produto->Peso > MAX_PESO_A)
            return 0;
    }
    else if (strcmp(produto->Tipo, "PB") == 0)
    {
        if (produto->Peso > MAX_PESO_B)
            return 0;
    }
    else if (strcmp(produto->Tipo, "PC") == 0)
    {
        if (produto->Peso > MAX_PESO_C)
            return 0;
    }

    return 1;
}

// Executa o encaminhamento de um produto
int ExecutarEncaminhamento(Tapete *aux, Tapete **tapete, Maquinas **maquinas)
{
    if (ValidarProduto(aux->Produto) == 0)
    {
        // Manda produto para a Lista de descarte
        DescartarProduto(ListaDescarte, aux->Produto);

        printf("\nProduto Descartado!!\n");
        return 1;
    }

    Maquina *maquina = RetornarMaquinaPeloProduto(*maquinas, aux->Produto->Tipo);
    if (maquina == NULL)
    {
        printf("\nNenhuma Maquina Disponivel\n");
        return 1;
    }

    maquina->Fila = EncaminharProduto(maquina->Fila, RemoverProdutoDoTapete(tapete));
    return 0;
}

// Encaminha os produtos para as máquinas correspondentes
void EncaminharProdutos(Tapete **tapete, Maquinas **maquinas)
{
    Tapete *aux = *(tapete);
    while (aux->prox != *(tapete))
    {
        if (ExecutarEncaminhamento(aux, tapete, maquinas) == 1)
            break;
        aux = aux->prox;
        if (aux->prox == *(tapete))
        {
            if (ExecutarEncaminhamento(aux, tapete, maquinas) == 1)
                break;
        }
    }
    printf("\nProdutos Encaminhados com sucesso!!\n");
    system("pause");
}

// Imprime os produtos no tapete
void ImprimirTapete(Tapete *tapete)
{
    if (tapete->Produto == NULL)
    {
        printf("\nTapete Vazio!!\n");
        system("pause");
        return;
    }

    int count = 1;
    Tapete *aux = tapete;

    printf("\n\n---------------------------\n\n", count);
    printf("\n\nProdutos no Tapete\n\n");

    // Verifica se o tapete tem apenas um produto
    if (aux->prox == tapete)
    {
        printf("%d - %s | Tipo %s | Peso %.2f\n", count, aux->Produto->Nome, aux->Produto->Tipo, aux->Produto->Peso);
        printf("\n\n%d produtos no tapete!", count);
        return;
    }

    // Imprime os produtos no tapete
    while (aux->prox != tapete)
    {
        printf("%d - %s | Tipo %s | Peso %.2f\n", count, aux->Produto->Nome, aux->Produto->Tipo, aux->Produto->Peso);
        aux = aux->prox;
        count++;
        if (aux->prox == tapete)
        {
            printf("%d - %s | Tipo %s | Peso %.2f\n", count, aux->Produto->Nome, aux->Produto->Tipo, aux->Produto->Peso);
        }
    }

    printf("\n\n%d produtos no tapete!\n", count);
    system("pause");
}

void ImprimirDescartados()
{
    Descarte *aux = ListaDescarte->descarte;
    if (aux == NULL)
    {
        printf("Nenhum Produto Descartado!\n");
        system("pause");
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

    system("pause");
}