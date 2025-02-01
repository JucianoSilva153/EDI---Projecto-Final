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

#include "TADs/utils/Ficheiros.c"

Maquinas *listaMaquinas;
Tapete *tapeteRolante;

void AdicionarMaquinas()
{
    system("cls");

    printf("1 - Adicionando Maquinas: \n\n");
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

    printf("\nMaquinas Configuradas com Sucesso\n\n");
    system("pause");
}

void AdicionarProdutosAutomaticamente()
{
    tapeteRolante = CarregarProdutos(tapeteRolante);
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

        printf("\n\nDeseja Adicionar mais produtos? (0 - Sim | 1 - Nao)\n> ");
        scanf("%d", &continuar);

    } while (continuar == 0);
}

void AdicionarProdutos()
{
    system("cls");

    int insercao;
    printf("2 - Adicionando Produtos ao Tapete Rolante: \n\n> ");
    printf("Como deseja inserir os produtos no tapete?\n1- Manual\t2- Automatica\n> ");
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

void MenuMaquinaSelecionada(Maquina *maquinaSelecionada)
{
    int opcao;
    if (maquinaSelecionada == NULL)
    {
        printf("Maquina Invalida\n");
        system("pause");
        return;
    }

    do
    {
        system("cls");

        printf("\n[ %s ]\n\nProdutos Embalados: %d\n\n", maquinaSelecionada->Nome, maquinaSelecionada->ProdutosEmbalados);
        printf("\n1 - Embalar Produto\n");
        printf("2 - Ver Fila\n");
        printf("3 - Voltar\n> ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("%s\n", EmbalarProduto(maquinaSelecionada));
            system("pause");
            break;
        case 2:
            printf("%s\n", ImprimirFila(maquinaSelecionada));
            system("pause");
            break;
        default:
            break;
        }
    } while (opcao != 3);
}

void MenuMaquinas()
{
    int opcao;
    do
    {
        system("cls");

        printf("Escolha a Maquina (0 - Voltar)\n");
        ImprimirMaquinas(listaMaquinas);
        printf("> ");
        scanf("%d", &opcao);
        system("cls");
        if (opcao != 0)
            MenuMaquinaSelecionada(SelecionarMaquina(listaMaquinas, opcao));
    } while (opcao != 0);
}

int main()
{
    listaMaquinas = InicializarMaquinas();
    tapeteRolante = InicializarTapete();

    int opcoes;

    printf("Sistema de Embalamento de Produtos\n");
    printf("1 - Iniciar simulacao\t 2 - Sair do programa\n> ");
    scanf("%d", &opcoes);
    switch (opcoes)
    {
    case 1:
        AdicionarMaquinas();
        AdicionarProdutos();
        break;
    case 2:
        printf("Saindo do programa...\n");
        return 0;
        break;

    default:
        break;
    }

    system("cls");

    int opcoesSimulacao;
    do
    {
        system("cls");

        printf("[ Menu Principal ]\n\n1 - Encaminhar Produtos\n");
        printf("2 - Ver Tapete\n");
        printf("3 - Maquinas\n");
        printf("4 - Ver Lista de Descartados\n");
        printf("5 - Terminar Simulacao\n> ");

        scanf("%d", &opcoesSimulacao);

        switch (opcoesSimulacao)
        {
        case 1:
            EncaminharProdutos(&tapeteRolante, &listaMaquinas);
            break;
        case 2:
            ImprimirTapete(tapeteRolante);
            break;
        case 3:
            MenuMaquinas();
            break;
        case 4:
            ImprimirDescartados();
            break;
        default:
            break;
        }
    } while (opcoesSimulacao != 5);

    return 0;
}