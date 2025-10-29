#include "listarItens.h"

void listarVetor(MochilaVetor* m){
    if(m->total == 0){
        printf("Mochila vazia (vetor)!\n");
        return;
    }

    for(int i = 0; i < m->total; i++){
        printf("%s (%s): %d\n", 
            m->itens[i].nome, 
            m->itens[i].tipo, 
            m->itens[i].quantidade);
    }
}

void listarLista(No* inicio){
    if(!inicio){
        printf("Mochila vazia (lista)!\n");
        return;
    }

    while(inicio){
        printf("%s (%s): %d\n",
            inicio->dados.nome,
            inicio->dados.tipo,
            inicio->dados.quantidade);
        inicio = inicio->proximo;
    }
}