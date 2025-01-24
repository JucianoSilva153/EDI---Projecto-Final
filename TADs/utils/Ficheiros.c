#include<stdio.h>
#include<stdlib.h>

#include "../TADs/Tapete/tapete.h";


Tapete* CarregarProdutos(Tapete* tapeteRolante)
{
    FILE *ficheiro;
    ficheiro = fopen("produtos.txt", "r");
    if (ficheiro == NULL)
    {
        printf("Erro ao abrir o ficheiro\n");
        return tapeteRolante;
    }

    char nome[50];
    char tipo[50];
    float peso;

    while (fscanf(ficheiro, "%s %s %f", nome, tipo, &peso) != EOF)
    {
        tapeteRolante = AdicionarProduto(tapeteRolante, CriarProduto(nome, tipo, peso));
    }

    fclose(ficheiro);
    return tapeteRolante;
}