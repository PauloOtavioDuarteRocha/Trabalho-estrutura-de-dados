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
    scanf("%d", novoItem.quantidade);
    printf("Qual a prioridade do item que deseja adcionar\n");
    scanf("%d", novoItem.prioridade);  
    mochila[*tamMochila] = novoItem;
    *tamMochila = *tamMochila + 1;
}

// Sistema de ordenação dos itens na mochila baseado na prioridade
void ordenarMochila(Item* mochila, int tam_mochila) {
    for (int i = 0; i < tam_mochila - 1; i++) {
        for (int j = 0; j < tam_mochila - i - 1; j++) {
            if (mochila[j].prioridade < mochila[j + 1].prioridade) {
                Item temp = mochila[j];
                mochila[j] = mochila[j + 1];
                mochila[j + 1] = temp;
            }
        }
    }
}

// Sistema de ordenação dos itens na mochila baseado no nome
void ordenarMochilaPorNome(Item* mochila, int tam_mochila) {
    for (int i = 0; i < tam_mochila - 1; i++) {
        for (int j = 0; j < tam_mochila - i - 1; j++) {
            if (strcmp(mochila[j].nome, mochila[j + 1].nome) > 0) {
                Item temp = mochila[j];
                mochila[j] = mochila[j + 1];
                mochila[j + 1] = temp;
            }
        }
    }
}

void limpaTerminal() {
}




int main() {
    Item mochila[10]; 
    int tam_mochila = 0;
    printf("incializando mochila\n");
    for (int i = 0; i < 3; i++) {
        adcionarItem(mochila, &tam_mochila);
    }
    bool continua = true;
    do{
        printf("O que deseja fazer?\n");
        printf("1 - Adcionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Ver itens da mochila\n");
        printf("4 - Ordenar itens por prioridade\n");
        printf("5 - Ordenar itens por nome\n");
        printf("0 - Sair\n");
        int escolha;
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            adcionarItem(mochila, &tam_mochila);
            limpaTerminal();
            printf("Item adcionado com sucesso!\n");
            break;
        case 2:
            //removerItem(mochila, &tam_mochila);
            limpaTerminal();
            printf("Funcao de remover item ainda nao implementada\n");
            break;
        case 3:
            limpaTerminal();
            printf("Itens na mochila:\n");
            for (int i = 0; i < tam_mochila; i++) {
                imprimirItem(mochila[i]);
            }
            break;
        case 4:
            ordenarMochila(mochila, tam_mochila);
            limpaTerminal();
            printf("Mochila ordenada por prioridade com sucesso!\n");
            break;
        case 5:
            ordenarMochilaPorNome(mochila, tam_mochila);
            limpaTerminal();
            printf("Mochila ordenada por nome com sucesso!\n");
            break;
        case 0:
            continua = false;
            limpaTerminal();
            printf("Saindo do programa...\n");
            break;
        
        default:
            limpaTerminal();
            printf("Opcao invalida\n");
            printf("Tente novamente\n");
            break;
        }
    }while (continua == true);
        
    
    
}