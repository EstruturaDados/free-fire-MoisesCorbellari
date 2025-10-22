#include "src/inserirItem.h"
#include "src/removerItem.h"
#include "src/listarItens.h"
#include "src/buscarItens.h"

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
    }while(opcao!=0);
    return 0;
}