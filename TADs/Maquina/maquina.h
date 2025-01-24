#ifndef MAQUINA_H
#define MAQUINA_H

#include "../Fila/fila.h"

typedef struct maquina
{
    char *Nome;
    char *Tipo;
    int TempoEmbalamento;
    int ProdutosEmbalados;
    Fila *Fila;
} Maquina;

typedef struct maquinas
{
    Maquina *Maquina;
    struct maquinas *prox;
} Maquinas;


Maquina* InicializarMaquina();
Maquina* CriarMaquina(char* tipo);

Maquinas* InicializarMaquinas();
Maquinas* AdicionarMaquina(Maquinas* maquinas, Maquina* maquina);

char* EmbalarProduto(Maquina* maquina);
char* ImprimirFila(Maquina* maquina);

#endif