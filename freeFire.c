#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEM 10

typedef struct{
    char nome[30];
    char tipo[20];
    int quantidade;
}Item;

// vetor armazena itens e contador global
Item mochila[MAX_ITEM];
int itensTotal=0;

// ---------------------------
// função: inserirItem()
// ---------------------------
void inserirItem(){
    if(itensTotal >= MAX_ITEM){
        printf("Mochila cheia!\n");
        return;
    }

    Item novo;

    printf("\n==== Cadastrar itens ====\n");
    printf("Nome: ");
    scanf(" %[^\n]", novo.nome);

    printf("Tipodos itens (ex: arma, munição, cura e etc): ");
    scanf(" %[^\n]", novo.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[itensTotal] = novo;
    itensTotal++;

    printf("\nCadastrado com sucesso!\n");
}

// ---------------------------
// função: removerItem()
// ---------------------------
void removerItem(){
    if (itensTotal == 0){
        printf("\nNão há itens para remover!\n");
        return;
    }
    char nomeItemRemover[30];
    printf("Digite o nome do itens para remover: ");
    scanf(" %[^\n]", nomeItemRemover);

    int encontrar = 0;
    for(int i=0; i < itensTotal; i++){
        if (strcmp(mochila[i].nome, nomeItemRemover) == 0){
            encontrar=1;
            for (int j = i; j<itensTotal - 1; j++){
                mochila[j] = mochila[j + 1];
            }
            itensTotal--;

            printf("\nItem '%s' removido com sucesso!\n", nomeItemRemover);
            break;
        }
    }
    if(!encontrar){
        printf("Item não encontrado!\n");
    }
}

// ---------------------------
// função: listarItens()
// ---------------------------
void listarItens(){
    printf("\n ==== Itens da mochila ====\n");

    if (itensTotal == 0){
        printf("Mochila vazia!\n");
        return;
    }

    for (int i = 0; i < itensTotal; i++){
        printf("\nItem %d:\n", i + 1);
        printf("  Nome: %s\n", mochila[i].nome);
        printf("  Tipo: %s\n", mochila[i].tipo);
        printf("  Quantidade: %d\n", mochila[i].quantidade);
    }
}

// ---------------------------
// função: buscarItens()
// ---------------------------
void buscarItens(){
    if (itensTotal == 0){
        printf("\n Nenhum item para buscar!\n");
        return;
    }
    char nomeBusca[30];
    printf("Nome do item para buscar: ");
    scanf(" %[^\n]", nomeBusca);

    int encontrado = 0;
    for (int i =0; i < itensTotal; i++){
        if (strcmp(mochila[i].nome, nomeBusca) == 0){
            printf("\nItem %d:\n", i + 1);
            printf("  Nome: %s\n", mochila[i].nome);
            printf("  Tipo: %s\n", mochila[i].tipo);
            printf("  Quantidade: %d\n", mochila[i].quantidade);
            encontrado =1;
            break;
        }
    }
    if(!encontrado){
        printf("\nItem não encontrado!\n");
    }
}

// ---------------------------
// função principal
// ---------------------------
int main(){
    int opcao;
    do{
        printf("\n ==== Menu Mochila ====\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar itens\n");
        printf("0. Sair\n");
        printf("\n =======================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1: inserirItem(); break;
            case 2: removerItem(); break;
            case 3: listarItens(); break;
            case 4: buscarItens(); break;
            case 0: printf("\nEncerrando sistema de inventário...\n"); break;
            default: printf("\nOpção inválida!\n");
        }
        if(opcao != 0) listarItens();
    }while(opcao!=0);
    return 0;
}