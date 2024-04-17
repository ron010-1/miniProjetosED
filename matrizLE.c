//3 - Implementar o TAD  Matriz, utilizando a Estrutura Matriz já implementada;

//Matriz:
// 9  8  7
// 6  5  4
// 3  2  1

#include<stdio.h>
#include "bibliotecaMatriz.h"


int main(){
    struct TipoLista *le;
    le = malloc(sizeof(lista));

    lerCelulas(9, le);
    imprimeLista(le);
    int i = busca(10, le);
    i>0 ? printf("O valor está na matriz.\n") : printf("O valor não está na matriz.\n");

    buscaEInsere(10, 9, le);
    imprimeLista(le);


    return 1;
}