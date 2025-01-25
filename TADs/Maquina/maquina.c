#include <stdio.h>
#include <stdlib.h>

#include <windows.h>

#include "maquina.h"
#include "../Fila/fila.h"

#define TEMPO_EMBALAMENTO_A 3000
#define TEMPO_EMBALAMENTO_B 2000
#define TEMPO_EMBALAMENTO_C 3500

// Inicializa uma maquina
Maquina *InicializarMaquina()
{
    Maquina *maquina = (Maquina *)malloc(sizeof(Maquina));

    if (maquina)
    {
        maquina->Nome = NULL;
        maquina->Tipo = NULL;
        maquina->TempoEmbalamento = 0;
        maquina->ProdutosEmbalados = 0;
        maquina->Fila = InicializaFila();

        return maquina;
    }

    return NULL;
}

// Inicializa uma lista de maquinas
Maquinas *InicializarMaquinas()
{
    Maquinas *maquinas = (Maquinas *)malloc(sizeof(Maquinas));

    if (maquinas)
    {
        maquinas->Maquina = NULL;
        maquinas->prox = NULL;

        return maquinas;
    }

    return NULL;
}

// Cria uma maquina
Maquina *CriarMaquina(char *tipo)
{
    Maquina *maquina = InicializarMaquina();

    if (maquina)
    {

        if (tipo == "MA")
        {
            maquina->Nome = "Maquina Tipo A";
            maquina->Tipo = tipo;
            maquina->TempoEmbalamento = TEMPO_EMBALAMENTO_A;
        }
        else if (tipo == "MB")
        {
            maquina->Nome = "Maquina Tipo B";
            maquina->Tipo = tipo;
            maquina->TempoEmbalamento = TEMPO_EMBALAMENTO_B;
        }
        else if (tipo == "MC")
        {
            maquina->Nome = "Maquina Tipo C";
            maquina->Tipo = tipo;
            maquina->TempoEmbalamento = TEMPO_EMBALAMENTO_C;
        }

        maquina->ProdutosEmbalados = 0;

        return maquina;
    }

    return NULL;
}

// Adiciona uma maquina em especifico a uma lista de maquinas
Maquinas *AdicionarMaquina(Maquinas *maquinas, Maquina *maquina)
{
    Maquinas *aux = maquinas;

    if (aux->Maquina == NULL)
    {
        maquinas->Maquina = maquina;
        maquinas->prox = NULL;
    }
    else
    {
        if (aux->prox == NULL)
        {
            Maquinas *novaMaquina = InicializarMaquinas();
            novaMaquina->Maquina = maquina;
            novaMaquina->prox = NULL;

            aux->prox = novaMaquina;
            return maquinas;
        }

        while (aux->prox != NULL)
        {
            aux = aux->prox;
            if (aux->prox == NULL)
            {
                Maquinas *novaMaquina = InicializarMaquinas();
                novaMaquina->Maquina = maquina;
                novaMaquina->prox = NULL;

                aux->prox = novaMaquina;
                return maquinas;
            }
        }
    }

    return maquinas;
}

char *EmbalarProduto(Maquina *maquina)
{
    if (maquina->Fila->quantidade == 0)
    {
        return "A Fila da Maquina selecionada esta Vazia!";
    }

    char *nomeProduto = maquina->Fila->inicio->Produto->Nome;
    printf("Embalando Produto: %s...\n", nomeProduto);

    // Remove o primeiro produto da fila "para ser embalado"
    maquina->Fila->inicio = maquina->Fila->inicio->prox;
    // Simula o tempo de embalado da maquina
    Sleep(maquina->TempoEmbalamento);
    // Incrementa a quantidade de produtos embalados
    maquina->ProdutosEmbalados++;

    return "Produto Embalado";
}

void ImprimirMaquinas(Maquinas *maquinas)
{
    if (maquinas->Maquina == NULL)
    {
        printf("Nenhuma Maquina Disponivel\n");
        return;
    }

    int count = 1;
    Maquinas *aux = maquinas;
    while (aux->prox != NULL)
    {
        printf("%d - %s | Tipo %s | Produtos Embalados %d\n", count, aux->Maquina->Nome, aux->Maquina->Tipo, aux->Maquina->ProdutosEmbalados);
        count++;
        aux = aux->prox;

        if (aux->prox == NULL)
        {
            count++;
            printf("%d - %s | Tipo %s | Produtos Embalados %d\n", count, aux->Maquina->Nome, aux->Maquina->Tipo, aux->Maquina->ProdutosEmbalados);
            break;
        }
    }
}

Maquina *SelecionarMaquina(Maquinas *maquinas, int posicao)
{
    Maquinas *aux = maquinas;
    int count = 1;
    while (aux->prox != NULL)
    {
        if (count == posicao)
        {
            if (aux->Maquina == NULL)
                return NULL;
            return aux->Maquina;
        }
        count++;
        aux = aux->prox;
    }

    return NULL;
}

// Imprime a fila de uma maquina
char *ImprimirFila(Maquina *maquina)
{
    if (maquina->Fila->quantidade == 0)
    {
        return "Fila Vazia";
    }

    int count = 1;
    No *aux = maquina->Fila->inicio;
    while (aux->prox != NULL)
    {
        printf("Produto-%d | Tipo %s | Peso %f\n", count, aux->Produto->Tipo, aux->Produto->Peso);
        count++;
        aux = aux->prox;
    }

    return "Fila de espera Impressa";
}