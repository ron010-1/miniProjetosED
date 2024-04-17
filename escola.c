//1 - Transformar o programa "Escola", utilizando Listas Dinâmicas Encadeadas;

//------------------ CONCLUÍDO--------------------

//Chamando bibliotecas.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bibliotecaAlunos.h"

int main(){
    //Iniciando a estrutura lista.
    struct TipoLista *le;
    le = malloc(sizeof(lista));//Alocação dinâmica de tamanho.
    le->proximo = NULL;//Criando a cabeça da lista apontando pra NULL, pois a lista inicia vazia.
    lerCSV(le, 32, "datasetAlunos.csv");
    imprimeLista(le);

    return 1;
}