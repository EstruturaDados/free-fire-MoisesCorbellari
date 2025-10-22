#include "src/estrutura.h"

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