#include "src/estrutura.h"

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