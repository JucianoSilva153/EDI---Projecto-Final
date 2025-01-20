#include "./Fila/fila.h"

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
Maquinas* InicializarMaquinas();
char* EmbalarProduto(Maquina* maquina);
char* ImprimirFila(Maquina* maquina);

Maquinas* AdicionarMaquina(Maquinas* maquinas, Maquina* maquina);