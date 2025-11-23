#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char nome[50];
    char tipo[30];
    int quantidade;
    int prioridade;
}Item;

void imprimirItem(Item item) {
    printf("------------------------\n");
    printf(" Nome:       %s\n", item.nome);
    printf(" Tipo:       %s\n", item.tipo);
    printf(" Quantidade: %d\n", item.quantidade);
    printf(" Prioridade: %d\n", item.prioridade);
    printf("------------------------\n");
}

void adcionarItem(Item *mochila,int *tamMochila) {
    if (*tamMochila >= 10) {
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
    scanf("%d", &novoItem.prioridade);
    mochila[*tamMochila] = novoItem;
    *tamMochila = *tamMochila + 1;
}

// Sistema de ordenação dos itens na mochila baseado na prioridade
void ordenarMochila(Item* mochila, int tamMochila) {
    int i, j;
    Item key;
    for (i = 1; i < tamMochila; i++) {
        key = mochila[i];
        j = i - 1;

        while (j >= 0 && mochila[j].prioridade < key.prioridade) {
            mochila[j + 1] = mochila[j];
            j = j - 1;
        }
        mochila[j + 1] = key;
    }
}

// Sistema de ordenação dos itens na mochila baseado no nome
void ordenarMochilaPorNome(Item* mochila, int tamMochila) {
    int i, j;
    Item tempItem;
        for (i = 1; i < tamMochila; i++) {
        tempItem = mochila[i];
        j = i - 1;
        while (j >= 0 && strcmp(mochila[j].nome, mochila[j + 1].nome) > 0) {
            mochila[j + 1] = mochila[j];
            j = j - 1;
        }
        mochila[j + 1] = tempItem;
    }
}

int buscaBinariaItemNome(Item *mochila, int tamMochila) {
    int inicio = 0;
    int fim = tamMochila - 1;
    char nomeBuscado[50];

    printf("Digite o nome para buscar: ");
    scanf("%s", nomeBuscado);

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        int comparacao = strcmp(mochila[meio].nome, nomeBuscado);

        if (comparacao == 0) {
            return meio;
        } else if (comparacao < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main() {
    Item mochila[10]; 
    int tamMochila = 0;
    
    printf("--- Inicializando mochila (adicione 3 itens iniciais) ---\n");
    for (int i = 0; i < 3; i++) {
        printf("Item %d/3:\n", i + 1);
        adcionarItem(mochila, &tamMochila);
    }

    bool continua = true;
    do {
        printf("\n=== SISTEMA DA MOCHILA ===\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item (Nao implementado)\n");
        printf("3 - Ver itens da mochila\n");
        printf("4 - Ordenar itens por prioridade\n");
        printf("5 - Ordenar itens por nome (Necessario para busca)\n");
        printf("6 - Buscar item por nome (Busca Binaria)\n"); // Nova opção
        printf("0 - Sair\n");
        printf("Escolha: ");

        int escolha;
        scanf("%d", &escolha);

        switch (escolha) {
        case 1:
            adcionarItem(mochila, &tamMochila);
            printf("Item adicionado com sucesso!\n");
            break;
        case 2:
            printf("Funcao de remover item ainda nao implementada\n");
            break;
        case 3:
            printf("Itens na mochila (%d itens):\n", tamMochila);
            for (int i = 0; i < tamMochila; i++) {
                imprimirItem(mochila[i]);
            }
            break;
        case 4:
            ordenarMochila(mochila, tamMochila);
            printf("Mochila ordenada por prioridade com sucesso!\n");
            break;
        case 5:
            ordenarMochilaPorNome(mochila, tamMochila);
            printf("Mochila ordenada por nome com sucesso!\n");
            break;
        case 6:
            int indice = buscaBinariaItemNome(mochila, tamMochila);
            if (indice != -1) {
                printf("\nItem ENCONTRADO na posicao %d:\n", indice);
                imprimirItem(mochila[indice]);
            } else {
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

// Limitar prioridade entre 1 e 5
// ordenar pro tipo
// sistema de remoção de itens
// contador de comparações na ordenação

// sla que porra é enum
// daonde tiraram bool nessa porra
