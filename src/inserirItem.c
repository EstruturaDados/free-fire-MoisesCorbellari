// inserirItem.c
#include "inserirItem.h"

void inserirVetor(MochilaVetor* m, Item novo) {
    if (m->total < MAX_ITEM) {
        m->itens[m->total++] = novo;
        printf("Item '%s' inserido na mochila (vetor).\n", novo.nome);
    } else {
        printf("Mochila cheia!\n");
    }
}

void inserirLista(No** inicio, Item novo) {
    No* novoNo = (No*) malloc(sizeof(No));
    if (!novoNo) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    novoNo->dados = novo;
    novoNo->proximo = *inicio;
    *inicio = novoNo;

    printf("Item '%s' inserido na mochila (lista).\n", novo.nome);
}
