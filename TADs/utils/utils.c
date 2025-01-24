#include <stdio.h>
#include <stdlib.h>

#include "../Tapete/tapete.h"
#include "../Maquina/maquina.h"

// Retorna a maquina que tenha a menor fila dado um determinado tipo de produto
Maquina *RetornarMaquinaPeloProduto(Maquinas *maquinas, char *tipoProduto)
{
    Maquinas *listaMaquinas = InicializarMaquinas();
    Maquinas *aux = maquinas;

    // Verifica o tipo de produto e dado esse tipo de produto, filtra as maquina correspentes em listaMaquinas declarado acima
    if (tipoProduto == "PA")
    {
        while (aux->prox != NULL)
        {
            if (aux->Maquina->Tipo == "MA")
            {
                listaMaquinas = AdicionarMaquina(listaMaquinas, aux->Maquina);
            }
            aux = aux->prox;
        }
    }
    else if (tipoProduto == "PB")
    {
        while (aux->prox != NULL)
        {
            if (aux->Maquina->Tipo == "MB")
            {
                listaMaquinas = AdicionarMaquina(listaMaquinas, aux->Maquina);
            }
            aux = aux->prox;
        }
    }
    else if (tipoProduto == "PC")
    {
        while (aux->prox != NULL)
        {
            if (aux->Maquina->Tipo == "MC")
            {
                listaMaquinas = AdicionarMaquina(listaMaquinas, aux->Maquina);
            }
            aux = aux->prox;
        }
    }

    // Retorna a maquina com a menor fila, apartir da lista de maquinas filtradas
    Maquinas *aux2 = listaMaquinas;
    Maquina *maquinaMenorFila = InicializarMaquina();
    maquinaMenorFila->Fila->quantidade = INT_MAX;

    while (aux2->prox != NULL)
    {
        if (maquinaMenorFila->Fila->quantidade > aux2->Maquina->Fila->quantidade)
        {
            maquinaMenorFila = aux2->Maquina;
        }
        aux2 = aux2->prox;
    }

    return maquinaMenorFila;
}

// Remove um produto do tapete e retorna ele
Produto *RemoverProdutoDoTapete(Tapete **tapete)
{
    if ((*tapete)->Produto == NULL)
    {
        return NULL; // Tapete vazio
    }

    Produto *produtoRemovido = (*tapete)->Produto;

    if ((*tapete)->prox == (*tapete))
    {
        Produto *produtoRemovido = (*tapete)->Produto; // Salva o produto
        free(tapete);                               // Libera a memória
        tapete = NULL;                              // Atualiza o ponteiro para NULL
        return produtoRemovido;                     // Retorna o produto
    }
    else
    {
        Tapete *ultimo = (*tapete);
        while (ultimo->prox != (*tapete))
        {
            ultimo = ultimo->prox; // Encontra o último nó
        }

        produtoRemovido = (*tapete)->Produto; // Salva o produto removido
        Tapete *temp = (*tapete);             // Nó atual a ser removido

        ultimo->prox = (*tapete)->prox; // Atualiza o próximo do último nó
        (*tapete) = (*tapete)->prox;       // Move o início do tapete para o próximo nó
        free(temp);                  // Libera o nó atual
    }

    return produtoRemovido;
}