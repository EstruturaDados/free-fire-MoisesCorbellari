#include "src/estrutura.h"

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
