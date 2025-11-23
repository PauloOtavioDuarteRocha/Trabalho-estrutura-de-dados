#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char nome[50];
    char tipo[30];
    int quantidade;
    int prioridade;
} Item;

void imprimirItem(Item item)
{
    printf("------------------------\n");
    printf(" Nome:       %s\n", item.nome);
    printf(" Tipo:       %s\n", item.tipo);
    printf(" Quantidade: %d\n", item.quantidade);
    printf(" Prioridade: %d\n", item.prioridade);
    printf("------------------------\n");
}

void adcionarItem(Item *mochila, int *tamMochila)
{
    if (*tamMochila >= 10)
    {
        printf("Mochila cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }
    Item novoItem;
    printf("Qual o nome do item que deseja adcionar\n");
    scanf("%s", novoItem.nome);
    printf("Qual o tipo do item que deseja adcionar\n");
    scanf("%s", novoItem.tipo);
    printf("Qual a quantidade do item que deseja adcionar\n");
    scanf("%d", &novoItem.quantidade);
    printf("Qual a prioridade do item que deseja adcionar\n");
    int i;
    do
    {
        printf("Digite um numero entre 1 e 5:\n");
        scanf("%d", &i);
        if (i < 1 || i > 5)
        {
            printf("Numero invalido \n");
        }
    } while (i < 1 || i > 5);
    novoItem.prioridade = i;
    mochila[*tamMochila] = novoItem;
    *tamMochila = *tamMochila + 1;
}

// Sistema de ordenação dos itens na mochila baseado na prioridade
int ordenarMochilaPorPrioridade(Item *mochila, int tamMochila)
{
    int i, j, quantDeComparacoes = 0;
    Item key;
    for (i = 1; i < tamMochila; i++)
    {
        key = mochila[i];
        j = i - 1;

        do
        {
            quantDeComparacoes++;
            mochila[j + 1] = mochila[j];
            j = j - 1;
        }while (j >= 0 && mochila[j].prioridade < key.prioridade);
        mochila[j + 1] = key;
    }
    return quantDeComparacoes;
}

// Sistema de ordenação dos itens na mochila baseado no nome
int ordenarMochilaPorNome(Item *mochila, int tamMochila)
{
    int i, j, quantDeComparacoes = 0;
    Item tempItem;
    for (i = 1; i < tamMochila; i++)
    {
        tempItem = mochila[i];
        j = i - 1;
        do{
            quantDeComparacoes++;
            mochila[j + 1] = mochila[j];
            j = j - 1;
        }while (j >= 0 && strcmp(mochila[j].nome, mochila[j + 1].nome) > 0);
        mochila[j + 1] = tempItem;
    }
    return quantDeComparacoes;
}

// Sistema de ordenação dos itens na mochila baseado no tipo
int ordenarMochilaPorTipo(Item *mochila, int tamMochila)
{
    int i, j, quantDeComparacoes = 0;
    Item tempItem;
    for (i = 1; i < tamMochila; i++)
    {
        tempItem = mochila[i];
        j = i - 1;
        do
        {
            quantDeComparacoes++;
            mochila[j + 1] = mochila[j];
            j = j - 1;
        }while (j >= 0 && strcmp(mochila[j].tipo, mochila[j + 1].tipo) > 0);
        mochila[j + 1] = tempItem;
    }
    return quantDeComparacoes;
}

int buscaBinariaItemNome(Item *mochila, int tamMochila)
{
    int inicio = 0;
    int fim = tamMochila - 1;
    char nomeBuscado[50];

    printf("Digite o nome para buscar: ");
    scanf("%s", nomeBuscado);

    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        int comparacao = strcmp(mochila[meio].nome, nomeBuscado);

        if (comparacao == 0)
        {
            return meio;
        }
        else if (comparacao < 0)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
        for (int i = 0; i < tamMochila; i++)
        {
            imprimirItem(mochila[i]);
        }
    }
    return -1;
}

void runMochila(Item *mochila, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        imprimirItem(mochila[i]);
    }
}

int main()
{
    Item mochila[10];
    int tamMochila = 0;

    printf("Incializando mochila...\n");
    Item item_inicial = {"Corda", "Ferramenta", 1, 5};
    mochila[tamMochila++] = item_inicial;
    Item item_inicial2 = {"Lanterna", "Ferramenta", 1, 3};
    mochila[tamMochila++] = item_inicial2;
    Item item_inicial3 = {"Agua", "Consumivel", 3, 2};
    mochila[tamMochila++] = item_inicial3;
    Item item_inicial4 = {"Comida", "Consumivel", 5, 4};
    mochila[tamMochila++] = item_inicial4;  
    Item item_inicial5 = {"Mapa", "Ferramenta", 1, 1};
    mochila[tamMochila++] = item_inicial5;
    Item item_inicial6 = {"Faca", "Arma", 1, 5};
    mochila[tamMochila++] = item_inicial6;

    bool continua = true;
    do
    {
        printf("\n=== SISTEMA DA MOCHILA ===\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item (Nao implementado)\n");
        printf("3 - Ver itens da mochila\n");
        printf("4 - Ordenar itens \n");
        printf("6 - Buscar item por nome (Busca Binaria)\n"); // Nova opção
        printf("0 - Sair\n");
        printf("Escolha: ");

        int escolha;
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            adcionarItem(mochila, &tamMochila);
            printf("Item adicionado com sucesso!\n");
            break;
        case 2:
            printf("Funcao de remover item ainda nao implementada\n");
            break;
        case 3:
            printf("Itens na mochila (%d itens):\n", tamMochila);
            runMochila(mochila,tamMochila);
            break;
        case 4:
            int quantDeComparacoes = 0;
            printf("Qual tipo de ordenacao deseja?\n");
            printf("1 - Por Prioridade\n");
            printf("2 - Por Nome\n");
            printf("3 - Por Tipo\n");
            int tipoOrdenacao;
            scanf("%d", &tipoOrdenacao);
            while (tipoOrdenacao < 1 || tipoOrdenacao > 3)
            {
                printf("Opcao invalida! Tente novamente.\n");
                scanf("%d", &tipoOrdenacao);
            };
            switch (tipoOrdenacao)
            {
            case 1:
                quantDeComparacoes = ordenarMochilaPorPrioridade(mochila, tamMochila);
                printf("Mochila ordenada por prioridade com sucesso!\n");
                break;
            case 2:
                quantDeComparacoes = ordenarMochilaPorNome(mochila, tamMochila);
                printf("Mochila ordenada por nome com sucesso!\n");
                break;
            case 3:
                quantDeComparacoes = ordenarMochilaPorTipo(mochila, tamMochila);
                printf("Mochila ordenada por tipo com sucesso!\n");
                break;
            default:
                break;
            }
                runMochila(mochila,tamMochila);
                printf("Quantidade de comparacoes executadas: %d\n", quantDeComparacoes);
            break;

        case 6:
            int indice = buscaBinariaItemNome(mochila, tamMochila);
            if (indice != -1)
            {
                printf("\nItem ENCONTRADO na posicao %d:\n", indice);
                imprimirItem(mochila[indice]);
            }
            else
            {
                printf("\nItem NAO encontrado.\n");
            }
            break;
        case 0:
            continua = false;
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
            break;
        }
    } while (continua);

    return 0;
}

// sistema de remoção de itens

// sla que porra é enum
// daonde tiraram bool nessa porra