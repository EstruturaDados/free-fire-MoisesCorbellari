// ordenarItens.c
#include "ordenarItens.h"

void ordenarVetor(MochilaVetor* m) {
    Item temp;
    for (int i = 0; i < m->total - 1; i++) {
        for (int j = 0; j < m->total - i - 1; j++) {
            if (strcmp(m->itens[j].nome, m->itens[j + 1].nome) > 0) {
                temp = m->itens[j];
                m->itens[j] = m->itens[j + 1];
                m->itens[j + 1] = temp;
            }
        }
    }
}
