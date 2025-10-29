#include <stdio.h>
#include "src/inserirItem.h"
#include "src/removerItem.h"
#include "src/listarItens.h"
#include "src/buscarItens.h"
#include "src/ordenarItens.h"

MochilaVetor mochila = {.total = 0};
No* lista = NULL;

// Função auxiliar para cadastrar um novo item
Item criarItem() {
    Item novo;
    printf("\nNome: ");
    scanf("%s", novo.nome);
    printf("Tipo: ");
    scanf("%s", novo.tipo);
    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);
    return novo;
}

// ---------------------------
// Funções chamadas pelo menu
// ---------------------------
void menuInserir() {
    Item novo = criarItem();

    printf("\nInserir em:\n");
    printf("1. Mochila Vetor\n");
    printf("2. Mochila Lista\n");
    printf("Escolha: ");
    int opc;
    scanf("%d", &opc);

    if (opc == 1)
        inserirVetor(&mochila, novo);
    else if (opc == 2)
        inserirLista(&lista, novo);
    else
        printf("Opção inválida!\n");
}

void menuRemover() {
    char nome[30];
    printf("\nNome do item a remover: ");
    scanf("%s", nome);

    printf("\nRemover de:\n");
    printf("1. Mochila Vetor\n");
    printf("2. Mochila Lista\n");
    printf("Escolha: ");
    int opc;
    scanf("%d", &opc);

    if (opc == 1)
        removerVetor(&mochila, nome);
    else if (opc == 2)
        removerLista(&lista, nome);
    else
        printf("Opção inválida!\n");
}

void menuListar() {
    printf("\nListar itens de:\n");
    printf("1. Mochila Vetor\n");
    printf("2. Mochila Lista\n");
    printf("Escolha: ");
    int opc;
    scanf("%d", &opc);

    if (opc == 1)
        listarVetor(&mochila);
    else if (opc == 2)
        listarLista(lista);
    else
        printf("Opção inválida!\n");
}

void menuBuscar() {
    char nome[30];
    printf("\nNome do item a buscar: ");
    scanf("%s", nome);

    printf("\nBuscar em:\n");
    printf("1. Mochila Vetor (sequencial)\n");
    printf("2. Mochila Vetor (binária)\n");
    printf("3. Mochila Lista\n");
    printf("Escolha: ");
    int opc;
    scanf("%d", &opc);

    int comp = 0;
    int pos;
    No* encontrado;

    switch (opc) {
        case 1:
            pos = buscarSequencial(&mochila, nome, &comp);
            if (pos != -1)
                printf("Item encontrado (pos %d) - comparações: %d\n", pos, comp);
            else
                printf("Item não encontrado - comparações: %d\n", comp);
            break;
        case 2:
            ordenarVetor(&mochila);
            pos = buscarBinaria(&mochila, nome, &comp);
            if (pos != -1)
                printf("Item encontrado (pos %d) - comparações: %d\n", pos, comp);
            else
                printf("Item não encontrado - comparações: %d\n", comp);
            break;
        case 3:
            encontrado = buscarLista(lista, nome, &comp);
            if (encontrado)
                printf("Item encontrado na lista - comparações: %d\n", comp);
            else
                printf("Item não encontrado - comparações: %d\n", comp);
            break;
        default:
            printf("Opção inválida!\n");
    }
}

// ---------------------------
// Função principal
// ---------------------------
int main() {
    int opcao;
    do {
        printf("\n ==== MENU MOCHILA ====\n");
        printf("1. Inserir item (ex: arma, munição, cura e etc)\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar itens\n");
        printf("0. Sair\n");
        printf("=======================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: menuInserir(); break;
            case 2: menuRemover(); break;
            case 3: menuListar(); break;
            case 4: menuBuscar(); break;
            case 0: printf("\nEncerrando sistema de inventário...\n"); break;
            default: printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
