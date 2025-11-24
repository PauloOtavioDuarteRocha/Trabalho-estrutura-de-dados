#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Strutura de Item contendo todos os campos necessários
typedef struct
{
    char nome[50];
    char tipo[30];
    int quantidade;
    int prioridade;
} Item;

// func para imprimir cara item de forma para melhorar a visibilidade
void imprimirItem(Item item)
{
    printf("------------------------\n");
    printf(" Nome:       %s\n", item.nome);
    printf(" Tipo:       %s\n", item.tipo);
    printf(" Quantidade: %d\n", item.quantidade);
    printf(" Prioridade: %d\n", item.prioridade);
    printf("------------------------\n");
}

// func par adicionar cada item de forma individual
void adcionarItem(Item *mochila, int *tamMochila)
{
    if (*tamMochila >= 10) // verificacao se ainda tem espaco na mochila
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
    do  // loop para garantir que a prioridade esteja nos parametros
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
    int j, quantDeComparacoes = 0;
    Item tempItem;
    for (int i = 1; i < tamMochila; i++)
    {
        tempItem = mochila[i];
        j = i - 1;
        while (j >= 0 && mochila[j].prioridade < tempItem.prioridade){ // Verificacao se o proximo item da lista e menor que o item atual e faz a troca
            quantDeComparacoes++;
            mochila[j + 1] = mochila[j];
            mochila[j] = tempItem;
            j = j - 1;
        };
        quantDeComparacoes++;
    }
    return quantDeComparacoes;
}

// Sistema de ordenação dos itens na mochila baseado no nome
int ordenarMochilaPorNome(Item *mochila, int tamMochila)
{
    int j, quantDeComparacoes = 0;
    Item tempItem;
    for (int i = 1; i < tamMochila; i++)
    {
        tempItem = mochila[i];
        j = i - 1;
        while (j >= 0 && strcmp(mochila[j].nome, tempItem.nome) > 0){ // Verificacao se o proximo item da lista e menor que o item atual e faz a troca
            quantDeComparacoes++;
            mochila[j + 1] = mochila[j];
            mochila[j] = tempItem;
            j = j - 1;
        };
        quantDeComparacoes++;
    }
    return quantDeComparacoes;
}

// Sistema de ordenação dos itens na mochila baseado no tipo
int ordenarMochilaPorTipo(Item *mochila, int tamMochila)
{
    int j, quantDeComparacoes = 0;
    Item tempItem;
    for (int i = 1; i < tamMochila; i++)
    {
        tempItem = mochila[i];
        j = i - 1;
        while (j >= 0 && strcmp(mochila[j].tipo, tempItem.tipo) > 0){ // Verificacao se o proximo item da lista e menor que o item atual e faz a troca
            quantDeComparacoes++;
            mochila[j + 1] = mochila[j];
            mochila[j] = tempItem;
            j = j - 1;
        };
        quantDeComparacoes++;
        mochila[j + 1] = tempItem;
    }
    return quantDeComparacoes;
}

int buscaBinariaItemNome(Item *mochila, int tamMochila)
{
    int inicio = 0;
    int fim = tamMochila - 1;
    char nomeBuscado[50];
    ordenarMochilaPorNome(mochila, tamMochila); // chama func para ordernar a mochila para garantir que e possivel buscar de forma binaria
    printf("Digite o nome para buscar: ");
    scanf("%s", nomeBuscado);

    while (inicio <= fim) // loop para busca de items
    {
        int meio = inicio + (fim - inicio) / 2;

        int comparacao = strcmp(mochila[meio].nome, nomeBuscado); // compara o nome buscado com o nome dos items

        if (comparacao == 0) // verifica se o item do meio e o certo
        {
            return meio;
        }
        if (comparacao < 0) // verifica se o item e menor que o item do meio atual
        {
            inicio = meio + 1;
        }
        else // executa se o item for maior que o item do meio atual
        {
            fim = meio - 1;
        }
    }
    return -1;
}

// func para imprimir toda a mochila
void runMochila(Item *mochila, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        imprimirItem(mochila[i]);
    }
}

// func para remover um item especifico da mochila
void removerItem(Item *mochila, int *tamMochila){
    printf("Qual o nome do item que deseja remover\n");
    int indice = buscaBinariaItemNome(mochila, *tamMochila); // faz a busca do item a ser removido
    if (indice == -1){ // verifica se achou o item
        printf("Item nao encontrado na mochila.\n");
        return;
    }
    for (int i = indice; i < *tamMochila - 1; i++){ // atualiza todos os items da mochila movendo o item seleciona para o final
        mochila[i] = mochila[i + 1];
    }
    (*tamMochila)--; // remove o ultimo item
    printf("Item removido com sucesso!\n");
}


// func principal
int main()
{
    Item mochila[10];
    int tamMochila = 0;

    // items de exemplo
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
    do // loop principal do programa
    {
        printf("\n=== SISTEMA DA MOCHILA ===\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item (Nao implementado)\n");
        printf("3 - Ver itens da mochila\n");
        printf("4 - Ordenar itens \n");
        printf("5 - Buscar item por nome (Busca Binaria)\n"); 
        printf("0 - Sair\n");
        printf("Escolha: ");

        int escolha;
        scanf("%d", &escolha);

        switch (escolha) // seleciona o caso de acordo com o input do usuario
        {
        case 1:
            adcionarItem(mochila, &tamMochila);
            printf("Item adicionado com sucesso!\n");
            break;
        case 2:
            removerItem(mochila, &tamMochila);
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
            switch (tipoOrdenacao) // selecio o tipo de ordencao que o usuario inserir
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

        case 5:
            int indice = buscaBinariaItemNome(mochila, tamMochila);
            if (indice != -1)
            {
                printf("\nItem ENCONTRADO na posicao %d:\n", indice+1);
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