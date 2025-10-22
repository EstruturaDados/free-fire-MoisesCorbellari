#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEM 10


typedef struct{
    char nome[30];
    char tipo[20];
    int quantidade;
}Item;

// vetor armazena itens e contador global
Item mochila[MAX_ITEM];
int itensTotal=0;

#endif