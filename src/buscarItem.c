// buscarItens.c
#include "buscarItens.h"

int buscarSequencial(MochilaVetor* m, const char* nome, int* comp) {
    *comp = 0;
    for (int i = 0; i < m->total; i++) {
        (*comp)++;
        if (strcmp(m->itens[i].nome, nome) == 0)
            return i;
    }
    return -1;
}

int buscarBinaria(MochilaVetor* m, const char* nome, int* comp) {
    int inicio = 0, fim = m->total - 1;
    *comp = 0;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        (*comp)++;
        int cmp = strcmp(m->itens[meio].nome, nome);
        if (cmp == 0) return meio;
        if (cmp < 0) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

No* buscarLista(No* inicio, const char* nome, int* comp) {
    *comp = 0;
    while (inicio) {
        (*comp)++;
        if (strcmp(inicio->dados.nome, nome) == 0)
            return inicio;
        inicio = inicio->proximo;
    }
    return NULL;
}
