#include <stdio.h>;
#include "maquina.h";

// Adiciona uma maquina em especifico a uma lista de maquinas
Maquinas *AdicionarMaquina(Maquinas *maquinas, Maquina *maquina)
{
    Maquinas *aux = maquinas;

    while (aux->prox != NULL)
    {
        if (aux->Maquina == NULL)
        {
            maquinas->Maquina = maquina;
            maquinas->prox = NULL;
        }else{
            Maquinas *novaMaquina = InicializarMaquina();
            novaMaquina->Maquina = maquina;
            novaMaquina->prox = NULL;

            aux->prox = novaMaquina;
            return maquinas;
        }
        aux = aux->prox;
    }
}