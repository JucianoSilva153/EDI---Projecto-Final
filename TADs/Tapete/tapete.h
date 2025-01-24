#ifndef TAPETE_H
#define TAPETE_H

#include "../Produto/produto.h"
#include "../Maquina/Maquina.h"
#include "../Fila/fila.h"

typedef struct tapete
{
    Produto* Produto;
    struct tapete* prox;
} Tapete;


Tapete* InicializarTapete();

char* AdicionarProduto(Tapete* tapete, Produto* produto);
int ValidarProduto( Produto* produto);
char* EncaminharProdutos(Tapete* tapete, Maquinas *maquinas);
char* ImprimirTapete(Tapete* tapete);
#endif