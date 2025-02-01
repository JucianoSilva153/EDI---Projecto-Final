#ifndef PRODUTO_H
#define PRODUTO_H

#define MAX_PESO_A 300
#define MAX_PESO_B 400
#define MAX_PESO_C 450

typedef struct produto
{
    char* Nome;
    char *Tipo;
    float Peso;
} Produto;


Produto* InicializarProduto();
Produto* CriarProduto(char* nome ,char* tipo, float peso);
#endif