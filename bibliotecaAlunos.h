#ifndef BIBLIOTECALISTAS_H
#define BIBLIOTECALISTAS_H

#endif
// O bloco acima, verifica se a biblioteca já foi definida, caso não, ele define, caso sim, só continua.

// Incluindo a biblioteca de entrada e saída, e a biblioteca de alocação de memória dinâmica.
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

// Criação da estrutura aluno.
struct TipoAluno{
    int matricula;
    char nome[50];
    char cidade[20];
    float nota1;
    float nota2;
    float nota3;
};
// Definindo a estrutura "Aluno"
typedef struct TipoALuno aluno;

// Criando a estrutura do tipo Lista
struct TipoLista{
    struct TipoAluno estudante;
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

// Função que calcula a altura de um objeto da TipoLista. Altura é a distância de um elemento c ao fim da TipoLista.
int altura(struct TipoLista *c){
    if (c == NULL){
        return 0;
    }
    return 1 + altura(c->proximo);
}

// Função que calcula a profundidade de um objeto na TipoLista. Profundidade é o número de passos que vai da primeira célula atá a célula c.
int profundidade(struct TipoLista *p, struct TipoLista *c){
    if (p == c){
        return 1;
    }
    return 1 + profundidade(p->proximo, c);
}

// Procedimento que imprime elementos da minha Lista Encadeada de acordo com o numero digitado pelo usuario.
void lerCelulas(int num, struct TipoLista *p){
    int i;
    for (i = 1; i <= num; i++){
        if (i == num){
            printf("Matricula: %d/nNome: %s/nCidade: %s/nNota 1: %.1f/nNota2: %.1f/nNota3: %.1f/n.", p->estudante.matricula, p->estudante.nome, p->estudante.cidade, p->estudante.nota1, p->estudante.nota2, p->estudante.nota3);
            return;
        }
        p = p->proximo; // Mudando pro próximo nó, até que i = num.
    }
}

// Procedimento que imprime todos os elementos da TipoLista.
void imprimeLista(struct TipoLista *p){
    int i;
    struct TipoLista *temp = p->proximo; // Criando um novo ponteiro que recebe o endereço de memória do início da TipoLista, ou seja, o elemento 1.
    printf("\nElementos da Lista: \n");
    while (temp != NULL){ // O loop acaba no ultimo termo, já que ele irá apontar para um endereço de memória do tipo NULL.
        printf("Matricula: %d Nome: %s Cidade: %s Nota 1: %.1f Nota2: %.1f Nota3: %.1f\n\n.", temp->estudante.matricula, temp->estudante.nome, temp->estudante.cidade, temp->estudante.nota1, temp->estudante.nota2, temp->estudante.nota3);
        temp = temp->proximo;
    }
    printf("\n"); // Adiciona um quebra de linha ao fim da impressão.
    free(temp);   // Limpando a memória alocada pra variável temp.
}

void lerCSV(struct TipoLista *le, int numeroAlunos, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Houve um erro na leitura do arquivo, reinicie o programa.");
        return;
    }

    numeroAlunos = 0;
    char linha[1024];

    // Ignorar cabeçalho, se houver
    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';

        struct TipoLista *NovoNo = malloc(sizeof(struct TipoLista));
        if (NovoNo == NULL) {
            printf("Erro ao alocar memória.\n");
            fclose(arquivo);
            return;
        }

        char *token = strtok(linha, ",");
        NovoNo->estudante.matricula = atoi(token);

        token = strtok(NULL, ",");
        strcpy(NovoNo->estudante.nome, token);

        token = strtok(NULL, ",");
        strcpy(NovoNo->estudante.cidade, token);

        token = strtok(NULL, ",");
        NovoNo->estudante.nota1 = atof(token);

        token = strtok(NULL, ",");
        NovoNo->estudante.nota2 = atof(token);

        token = strtok(NULL, ",");
        NovoNo->estudante.nota3 = atof(token);

        NovoNo->proximo = le->proximo; // O novo nó aponta para o antigo início da lista
        le->proximo = NovoNo; // Atualiza o início da lista para o novo nó

        (numeroAlunos)++;
    }

    fclose(arquivo);
}

// Procedimento que insere nova célula no fim da Lista Encadeada
void insere(int x, struct TipoLista *p){
    struct TipoLista *nova =  NULL;// Declarando uma nova estrutura lista com o nome nova, de nova celula
    nova = malloc(sizeof(struct TipoLista));// Alocando memória de acordo com o tamanho da estrutura.
    printf("Informe a matricula: ");
    scanf("%d", &nova->estudante.matricula);

    printf("Informe o Nome: ");
    scanf("%s", &nova->estudante.nome[0]);

    printf("Informe a Cidade: ");
    scanf("%s", &nova->estudante.cidade[0]);

    printf("Informe a Nota 1: ");
    scanf("%f", &nova->estudante.nota1);

    printf("Informe a Nota 2: ");
    scanf("%f", &nova->estudante.nota2);

    printf("Informe a Nota 3: ");
    scanf("%f", &nova->estudante.nota3);
    nova->proximo = p->proximo; // Insere o novo nó no início da lista.
    p->proximo = nova;          // Alterando a cabeça da lista.
}

// Procedimento para remover celula com matricula x, mas sem cabe�a. POINTER TO POINTER FUNCTION.
void buscaERemove(struct TipoLista *p, int x){
    struct TipoLista *anterior = NULL;
    struct TipoLista *atual = p;

    // Laço para encontrar o anterior da célula com valor x.
    while (atual != NULL && atual->estudante.matricula != x){
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

// Procedimento que busca e insere uma célula antes de matricula y.
void buscaEInsere(int y, struct TipoLista *p){
    struct TipoLista *anterior = NULL;
    struct TipoLista *atual = p->proximo; // Avança para o primeiro nó da lista
    struct TipoLista *nova = malloc(sizeof(struct TipoLista));

    printf("Informe a matricula: ");
    scanf("%d", &nova->estudante.matricula);

    printf("Informe o Nome: ");
    scanf("%s", &nova->estudante.nome[0]);

    printf("Informe a Cidade: ");
    scanf("%s", &nova->estudante.cidade[0]);

    printf("Informe a Nota 1: ");
    scanf("%f", &nova->estudante.nota1);

    printf("Informe a Nota 2: ");
    scanf("%f", &nova->estudante.nota2);

    printf("Informe a Nota 3: ");
    scanf("%f", &nova->estudante.nota3);

    while (atual != NULL && atual->estudante.matricula != y){
        anterior = atual;
        atual = atual->proximo;
    }
    nova->proximo = atual;
    anterior->proximo = nova;
}

// Função que retorna se uma matricula está na lista ou não.
int procuraValor(int num, struct TipoLista *p){
    int i, contador = 0;
    while (p->proximo != NULL && p->estudante.matricula != num){
        p = p->proximo;
        contador++;
    }
    if (p->estudante.matricula == num){
        return contador;
    }
    else{
        return 0; // False, nao encontrou o valor.
    }
}