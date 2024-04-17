#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Variaveis de ambiente
const int numeroAlunos = 50;


//Declarando a estrutura Aluno com seus respectivos campos.
struct aluno {
    int matricula;
    char nome[50];
    char cidade[20];
    float nota1;
    float nota2;
    float nota3;
};
// Tentando mudar tamanho do vetor


struct aluno* aumentarVetor(struct aluno vetorOriginal[], int tamanhoOriginal, int adicionarMatricula) {
    int novoTamanho = tamanhoOriginal + 1;
    int k;
    
    struct aluno *novoVetor = (struct aluno *)malloc(novoTamanho * sizeof(struct aluno));

    for (k = 0; k < tamanhoOriginal; k++) {
        novoVetor[k] = vetorOriginal[k];
    }
    
    novoVetor[novoTamanho - 1].matricula = adicionarMatricula;
    
    // Libera a memória do vetor original
    free(vetorOriginal);

    return novoVetor;
}

void novoAluno(struct aluno vetor[]) {
    int i;

    for (i = 0; i < numeroAlunos; i++) {
        if (vetor[i].matricula == 0) {
            printf("Informe a matricula: ");
            scanf("%d", &vetor[i].matricula);

            printf("Informe o Nome: ");
            scanf("%s", vetor[i].nome);

            printf("Informe a Cidade: ");
            scanf("%s", vetor[i].cidade);

            printf("Informe a Nota 1: ");
            scanf("%f", &vetor[i].nota1);

            printf("Informe a Nota 2: ");
            scanf("%f", &vetor[i].nota2);

            printf("Informe a Nota 3: ");
            scanf("%f", &vetor[i].nota3);
            
            break;  // Interrompe o loop depois de adicionar um aluno
        }
    }
}

void escreverCSV(struct aluno aluno, FILE *arquivo) {
    fprintf(arquivo, "%d,%s,%s,%.2f,%.2f,%.2f\n", aluno.matricula, aluno.nome, aluno.cidade, aluno.nota1, aluno.nota2, aluno.nota3);
}

void salvarDadosCSV(struct aluno vetor[], int quantidade, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Houve um erro ao procurar o caminho do dataset, reinicie o programa.\n");
        return;
    }

    int i;
    for (i = 0; i < quantidade; i++) {
        escreverCSV(vetor[i], arquivo);
    }

    fclose(arquivo);
}

void lerCSV(struct aluno vetor[], int numeroAlunos, const char *nomeArquivo) {
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

        char *token = strtok(linha, ",");
        vetor[numeroAlunos].matricula = atoi(token);

        token = strtok(NULL, ",");
        strcpy(vetor[numeroAlunos].nome, token);

        token = strtok(NULL, ",");
        strcpy(vetor[numeroAlunos].cidade, token);

        token = strtok(NULL, ",");
        vetor[numeroAlunos].nota1 = atof(token);

        token = strtok(NULL, ",");
        vetor[numeroAlunos].nota2 = atof(token);

        token = strtok(NULL, ",");
        vetor[numeroAlunos].nota3 = atof(token);

        (numeroAlunos)++;
    }

    fclose(arquivo);
}

void imprimirVetor(struct aluno vetor[]) {
    int i;
    for (i = 0; i < numeroAlunos; i++) {
        if (vetor[i].matricula == 0) {
            break;
        }
        printf("Matricula: %d\nNome: %s\nCidade: %s\nNota 1: %.2f\nNota 2: %.2f\nNota 3: %.2f\n",
               vetor[i].matricula, vetor[i].nome, vetor[i].cidade,
               vetor[i].nota1, vetor[i].nota2, vetor[i].nota3);
    }
}

void removerAluno(struct aluno aluno[], int matricula){
    int i;
    for(i=0; i<numeroAlunos; i++){
        if(aluno[i].matricula == matricula){
            aluno[i].matricula = 0;
            aluno[i].nome = " ";
            aluno[i].cidade = " ";
            aluno[i].nota1 = 0.0;
            aluno[i].nota2 = 0.0;
            aluno[i].nota3 = 0.0;
            break;
        }
    }
    return i;
}
int retornaPosicao(struct aluno aluno[], int matricula) {
    int i;
    for (i = 0; i < numeroAlunos; i++) {
        if (aluno[i].matricula == matricula) {
            break;
        }
    }
    return i;
}
struct aluno substituirAluno(struct aluno aluno[], int posicao){
    int i;
    for(i=0; i<numeroAlunos; i++){
        if(i == posicao){
            printf("Informe a matricula: ");
            scanf("%d", &vetor[i].matricula);

            printf("Informe o Nome: ");
            scanf("%s", vetor[i].nome);

            printf("Informe a Cidade: ");
            scanf("%s", vetor[i].cidade);

            printf("Informe a Nota 1: ");
            scanf("%f", &vetor[i].nota1);

            printf("Informe a Nota 2: ");
            scanf("%f", &vetor[i].nota2);

            printf("Informe a Nota 3: ");
            scanf("%f", &vetor[i].nota3);
            
            break;  // Interrompe o loop depois de adicionar um aluno
        }
    }
    return aluno;
}

int main() {
    //Declaração de Variáveis
    int varAuxiliar; //Variavel para o loop, os campos.
    struct aluno vetorAluno[numeroAlunos];

    //-------------- SEÇÃO PROGRAMA -----------------
    while(varAuxiliar != 0){


        printf("Seja bem-vindo ao meno de Alunos, abaixo estao as opcoes que voce manipular: \n\n");
        printf("1 - Adicionar aluno no vetor: /n");
        printf("2 - Remover aluno do vetor: /n");
        printf("3 - Imprimir todos os alunos cadastrados no sistema.\n");
        printf("4 - Retorna posicao do aluno no sistema pela matricula. \n");
        printf("5 - Substituir posicao do vetor. \n");
        printf("6 - Imprimir o numero de alunos cadastrados no sitema. \n");
        printf("7 - Salvar alterações no dataset. ");
        scanf("%d", &varAuxiliar);
        switch(varAuxiliar){
            case 1: novoAluno(vetorAluno);
                    break;
            case 2: 
                    printf("Digite a matricula: ");
                    int matricula;
                    scanf("%d", &matricula);
                    int pos = removerAluno(vetorAluno, matricula);
                    printf("Foi removida o aluno da posicao %d.", pos + 1);
                    break;
            case 3: lerCSV(vetorAluno, numeroAlunos, "dataset.csv");  
                    break;
            case 4: printf("Insira a matricula no vetor do aluno que deseja: ");
                    int matricula;
                    scanf("%d", &matricula); 
                    int pos = retornaPosicao(vetorAluno, matricula);
                    printf("A posicao da matricula %d eh %d.\n", matricula, pos);
                    break;
            case 5:
                    printf("Insira a posicao do aluno que deseja substituir: ");
                    int pos;
                    scanf("%d", &pos); 
                    vetorAluno = substituirAluno(vetorAluno, pos);
                    printf("A troca teve exito.");
                    break;
            case 6: 
                             

        }
    }
    return 0;
}
