
#include<stdio.h>


//Variaveis de ambiente
int const n = 3;//constante n da fórmula para buscar indice na memória.

int *zeraMatriz(int vet[], int ordem){
    if(ordem < 0){
        return vet;
    }vet[ordem] = 0; 
    return zeraMatriz(vet, ordem-1);
}
int* dimensionaMatriz(int vet, int i, int j){
    int ordemMatriz = i*j;
    int vet[ordemMatriz];
    return vet;
}
void imprimeMatriz(int vet[]){
    int i, contador = 0;
    for(i=0; i<num; i++){
        if(contador == 3){
            printf("\n");
            contador = 0;
        }
        printf("%d ", vet[i]);
        contador++;
    }
    printf("\n\n");
}
void adicionaElemento(int vet[], int valor, int i, int j){
    int k = i * n + j;
    vet[k] = valor;
    imprimeMatriz(vet);
}
void buscarElemento(int vet[], int i, int j){
    int k = i * n + j;
    printf("O valor da posicao %dx%d eh %d.\n", i, j, vet[k]);
}
void removeElemento(int vet[], int i, int j){
    int k = i * n + j;
    vet[k] = 0;
    printf("O valor da posicao %dx%d eh %d.\n", i, j, vet[k]);
}

int* produtoMatriz(int vet1[], int vet2[], int m, int n){
    
}
int main(){
    //Declarando variaveis.
    int vet[ordem];

    //Chamada da função para zerar a matriz inteira, todos os campos terão valor zero.
    zeraMatriz(vet, ordem-1);
    imprimeMatriz(vet);
    adicionaElemento(vet, 15, 1, 1);
    buscarElemento(vet, 2, 2);
    removeElemento(vet, 1, 1);


    return 0;
}