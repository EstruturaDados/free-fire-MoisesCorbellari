#include "src/estrutura.h"

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
