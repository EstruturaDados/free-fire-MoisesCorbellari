#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEM 10

// Estrutura base
typedef struct{
    char nome[30];
    char tipo[20];
    int quantidade;
}Item;

// Estrutura encadeada
typedef struct No {
    Item dados;
    struct No* proximo;
}No;

// Mochila sequencial
typedef struct{
    Item itens[MAX_ITEM];
    int total;
} MochilaVetor;

#endif