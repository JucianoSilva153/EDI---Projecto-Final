#ifndef PRODUTO_H
#define PRODUTO_H

#define MAX_PESO_A 100
#define MAX_PESO_B 200
#define MAX_PESO_C 250

typedef struct produto
{
    char* Nome;
    char *Tipo;
    float Peso;
} Produto;


Produto* InicializarProduto();
Produto* CriarProduto(char* nome ,char* tipo, float peso);
#endif