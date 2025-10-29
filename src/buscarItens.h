// buscarItens.h
#ifndef BUSCARITENS_H
#define BUSCARITENS_H

#include "estrutura.h"

int buscarSequencial(MochilaVetor* m, const char* nome, int* comp);
int buscarBinaria(MochilaVetor* m, const char* nome, int* comp);
No* buscarLista(No* inicio, const char* nome, int* comp);

#endif