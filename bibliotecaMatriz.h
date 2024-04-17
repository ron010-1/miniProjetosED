#ifndef BIBLIOTECALISTAS_H
#define BIBLIOTECALISTAS_H

#endif
// O bloco acima, verifica se a biblioteca já foi definida, caso não, ele define, caso sim, só continua.

// Incluindo a biblioteca de entrada e saída, e a biblioteca de alocação de memória dinâmica.
#include <stdio.h>
#include <stdlib.h>

//Iremos declarar uma matriz 3 por 3 (ORDEM 3x3).
const int n = 3; //Variável n da fórmula. k = i * n + j;

// Criando a estrutura do tipo Lista
struct TipoLista{
    int valor;
    struct TipoLista *proximo;
};

// Definindo do tipo "lista".
typedef struct TipoLista lista;

// Função que calcula o número de objetos da TipoLista.
int contaElementos(struct TipoLista *p){
    if (p == NULL)
    {
        return 0;
    }
    return 1 + contaElementos(p->proximo);
}

int posicaoMemoria(int i, int j){
    int k = i * n + j;
    return k;
}
// Procedimento que adiciona elementos a minha Lista Encadeada de acordo com o numero digitado pelo usuario.
void lerCelulas(int num, struct TipoLista *p){
    int i, variavelAuxiliar;
    for (i = 0; i < num; i++){
        struct TipoLista *NovoNo = malloc(sizeof(lista));
        printf("Insira um numero para a celula %d: ", i + 1);
        scanf("%d", &variavelAuxiliar);
        NovoNo->valor = variavelAuxiliar; // Atribui um valor ao nó
        NovoNo->proximo = p->proximo;     // Insere o novo nó no início da lista
        p->proximo = NovoNo;              // Atualiza a cabeça da lista
    }
}

// Procedimento que imprime todos os elementos do TipoLista em forma de Matriz.
void imprimeLista(struct TipoLista *p){
    int i, contador = 0;
    struct TipoLista *temp = p->proximo; // Criando um novo ponteiro que recebe o endereço de memória do início da TipoLista, ou seja, o elemento 1.
    printf("\nElementos da Lista: \n");
    while (temp != NULL){ // O loop acaba no ultimo termo, já que ele irá apontar para um endereço de memória do tipo NULL.
        if (contador == 3){ // 3 por causa da ordem da matriz que é 3, imprime 3 elementos e quebra a linha.
            printf("\n");
            contador = 0;
        }
        printf("%d ", temp->valor);
        temp = temp->proximo;
        contador++;
    }
    printf("\n\n"); // Adiciona um quebra de linha ao fim da impressão.
}

// Procedimento que insere nova célula de valor x na Lista Encadeada.
void insere(int x, struct TipoLista *p){
    struct TipoLista *nova;       // Declarando uma nova estrutura lista com o nome nova, de nova celula.
    nova = malloc(sizeof(lista)); // Alocando memória de acordo com o tamanho da estrutura.
    nova->valor = x;              // Recebendo o valor da celula.
    nova->proximo = p->proximo;   // Insere o novo nó no início da lista.
    p->proximo = nova;            // Alterando a cabeça da lista.
}

// Procedimento para remover celula com valor x, mas sem cabeça. POINTER TO POINTER FUNCTION.
void removeCelula(struct TipoLista *p, int x){
    struct TipoLista *anterior = NULL;
    struct TipoLista *atual = p;

    // Laço para encontrar o anterior da célula com valor x.
    while (atual != NULL && atual->valor != x){
        anterior = atual;       // Atualizando o ponteiro anterior.
        atual = atual->proximo; // Atualiza o ponteiro p pra próxima célula.
    }
    // Se encontrou o valor x.
    if (atual != NULL){
        // Se o nó não é primeiro
        if (anterior != NULL){
            anterior->proximo = atual->proximo;
        }
        else{ // Se o nó é o primeiro
            p = atual->proximo;
        }
    }
    free(atual);
}

////AJEITARR FUNÇÃOOOOOOO
// Procedimento que busca uma celula antes de y e remove.
void buscaERemove(int y, struct TipoLista *p){
    int num;
    struct TipoLista *anterior = NULL;
    struct TipoLista *atual = p->proximo; // Avança para o primeiro nó da lista
    while (atual != NULL && atual->valor != y){
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual != NULL){
        anterior->proximo = atual->proximo;
        free(atual);
    }
}

// Procedimento que busca e insere uma célula com valor x antes de y
void buscaEInsere(int x, int y, struct TipoLista *p){
    int num = posicaoMemoria(1, 2), i;
    struct TipoLista *anterior = NULL;
    struct TipoLista *atual = p->proximo; // Avança para o primeiro nó da lista
    struct TipoLista *nova = malloc(sizeof(struct TipoLista));
    for(i=0; i<num; i++){
        if(i-1==num){
                nova->proximo = atual;
                anterior->proximo = nova;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

//Procura uma célula com valor == num.
int busca(int num, struct TipoLista *p){
    if(p->proximo == NULL){
        if(p->valor == num){
            return 1;
        }
        return 0;
    }if(p->valor==num){
        return 1;
    }
    return busca(num, p->proximo);
}