#include<stdio.h>
#include<stdlib.h>

#include "../Tapete/tapete.h"


Tapete* CarregarProdutos(Tapete* tapeteRolante)
{
    FILE *ficheiro;
    ficheiro = fopen("C:/Users/jucia/EDI - Projecto Final/Assets/produtos.txt", "r");
    if (ficheiro == NULL)
    {
        printf("Erro ao abrir o ficheiro\n");
        return tapeteRolante;
    }

    char nome[50];
    char tipo[50];
    float peso;
    int count = 0;

    while (fscanf(ficheiro, "%s %s %f", nome, tipo, &peso) != EOF)
    {
        tapeteRolante = AdicionarProduto(tapeteRolante, CriarProduto(nome, tipo, peso));
        count++;
    }

    printf("\n%d Produtos Carregados com Sucesso\n", count);
    fclose(ficheiro);
    return tapeteRolante;
}