#include <stdio.h>
#include <stdlib.h>

#include "TADs/Tapete/tapete.h"
#include "TADs/Tapete/tapete.c"

#include "TADs/Produto/produto.h"
#include "TADs/Produto/produto.c"

#include "TADs/Maquina/maquina.h"
#include "TADs/Maquina/maquina.c"

#include "TADs/Fila/fila.h"
#include "TADs/Fila/fila.c"

Maquinas *listaMaquinas;
Tapete *tapeteRolante;

void AdicionarMaquinas()
{
    int QuantidadeMA, QuantidadeMB, QuantidadeMC;
    printf("Quantas maquinas do tipo A: ");
    scanf("%d", &QuantidadeMA);
    printf("Quantas maquinas do tipo B: ");
    scanf("%d", &QuantidadeMB);
    printf("Quantas maquinas do tipo C: ");
    scanf("%d", &QuantidadeMC);

    for (int i = 0; i < QuantidadeMA; i++)
    {
        listaMaquinas = AdicionarMaquina(listaMaquinas, CriarMaquina("MA"));
    }

    for (int i = 0; i < QuantidadeMB; i++)
    {
        listaMaquinas = AdicionarMaquina(listaMaquinas, CriarMaquina("MB"));
    }

    for (int i = 0; i < QuantidadeMC; i++)
    {
        listaMaquinas = AdicionarMaquina(listaMaquinas, CriarMaquina("MC"));
    }

    printf("Maquinas Configuradas com Sucesso\n\n");
}

void AdicionarProdutosAutomaticamente()
{
}

void AdicionarProdutosManualmente()
{
    int continuar = 0;
    printf("Insira os produtos\n");
    do
    {
        char nome[50];
        char tipo[50];
        float peso;

        printf("Nome: ");
        scanf("%s", nome);
        
        printf("Tipo: ");
        scanf("%s", tipo);

        printf("Peso: ");
        scanf("%f", &peso);

        AdicionarProduto(tapeteRolante, CriarProduto(nome, tipo, peso));

        printf("\n\nDeseja Adicionar mais produtos? (0 - Sim | 1 - Nao)\n\n");
        scanf("%d", &continuar);

    } while (continuar == 0);
}

void AdicionarProdutos()
{
    int insercao;
    printf("Como deseja inserir os produtos no tapete?\n 1- Manual \t 2- Automatica");
    scanf("%d", &insercao);
    switch (insercao)
    {
    case 1:
        AdicionarProdutosManualmente();
        break;
    case 2:
        AdicionarProdutosAutomaticamente();
        break;
    default:
        break;
    }
}

int main()
{
    listaMaquinas = InicializarMaquinas();
    tapeteRolante = InicializarTapete();

    int opcoes;

    printf("Sistema de Embalamento de Produtos\n");
    printf("1 Iniciar simulacao\t 2 Sair do programa\n");
    scanf("%d", &opcoes);
    switch (opcoes)
    {
    case 1:
        AdicionarMaquinas();
        AdicionarProdutos();
        break;

    default:
        break;
    }
}