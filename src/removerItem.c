// removerItem.c
#include "removerItem.h"

void removerVetor(MochilaVetor* m, const char* nome) {
    for (int i = 0; i < m->total; i++) {
        if (strcmp(m->itens[i].nome, nome) == 0) {
            for (int j = i; j < m->total - 1; j++)
                m->itens[j] = m->itens[j + 1];
            m->total--;
            printf("Item '%s' removido.\n", nome);
            return;
        }
    }
    printf("Item '%s' não encontrado.\n", nome);
}

void removerLista(No** inicio, const char* nome) {
    No* atual = *inicio;
    No* anterior = NULL;

    while (atual && strcmp(atual->dados.nome, nome) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (!atual) {
        printf("Item '%s' não encontrado.\n", nome);
        return;
    }

    if (anterior == NULL)
        *inicio = atual->proximo;
    else
        anterior->proximo = atual->proximo;

    free(atual);
    printf("Item '%s' removido.\n", nome);
}
