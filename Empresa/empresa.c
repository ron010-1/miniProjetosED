#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const numeroMaximo = 10;

struct funcionario{
	char nome[50];
	int id;
};

void lerBD(struct funcionario vetor[], int numeroFuncionarios){
	FILE *arquivo = fopen("data.csv", "r");
	
	if(arquivo == NULL){
		perror("Houve um erro ao abrir o arquivo.");
		exit(1);
	}
	
	char linha[1024];
	numeroFuncionarios = 0;

	while(fgets(linha, sizeof(linha), arquivo) != NULL){
		char *token; //Declarando um ponteiro pra receber o conteudo da linha.
		// A LINHA IRA CONTER "NOME, ID" a ideia eh que o nome seja token[0] e o id token[1], meio que a linha fosse um vetor de strings.
		token = strtok(linha, ","); // De acordo com o raciocinio da linha anterior, esse strtok serve pra pegar a primeira posicao da linha, o que vem antes do delimitador que no caso eh uma virgula.
		
		//Uso da funcao strcpy pra pegar o que esta no token e colar no nome do funcionario dentro do vetor.
		strcpy(vetor[numeroFuncionarios].nome, token);
		
		//Agora, a funcao strtok eh usada pra acessar o que vem apos a virgula e nao mais do comeco da linha.
		token = strtok(NULL, ",");
		
		//a funcao atoi serve pra converter uma string em int antes de adicionar no vetor.
		vetor[numeroFuncionarios].id = atoi(token);
		
		numeroFuncionarios++;//Pula pra proxima posicao do vetor.
	}
	
	fclose(arquivo);
}

void salvarBD(struct funcionario vetor[], int numeroMaximoFuncionario){
	FILE *arquivo = fopen("data.csv", "w");
	int i;
	for(i=0; i<=numeroMaximoFuncionario; i++){
		printf("%s, %d\n", vetor[i].nome, vetor[i].id);
		fprintf(arquivo, "%s,%d\n", vetor[i].nome, vetor[i].id);
	}	
	
	fclose(arquivo);
	
	system("cls");
	printf("O Banco de Dados foi atualizado.");
}


void adicionar(struct funcionario vetor[], int numeroFuncionarios){
	char nomeFuncionario[50];
	fflush(stdin);
	int posNovoFuncionario = ultimoFuncionario(vetor);
	
	printf("Insira o nome do novo funcionario: ");
	gets(nomeFuncionario);
	strcpy(vetor[posNovoFuncionario].nome, nomeFuncionario); 
	vetor[posNovoFuncionario].id = posNovoFuncionario;
	printf("O funcionario %s tem id %d.", vetor[posNovoFuncionario].nome, vetor[posNovoFuncionario].id);
	
	salvarBD(vetor, posNovoFuncionario);
}

void excluir(struct funcionario vetor[]){
	int escolha;
	printf("Insira 1 para excluir pelo nome e 2 para excluir pelo id.\n");
	scanf("&escolha");
	
	char nome[50];
	int idade, pos, id;
	
	switch(escolha){
		case 1:
			printf("Insira o nome: ");
			gets("&nome");
			pos = posFuncionarioNome(vetor, nome);
			//CHAMAR FUNÇÃO
			break;
		case 2:
			printf("Insira o id: ");
			scanf("&id");
			pos = posFuncionarioId(vetor, id);
			//CHAMAR FUNÇÃO
			break;
		default:
			printf("Voce inseriu uma opcao invalida.\n");
			break;
		     	
	}
}

int posFuncionarioNome(struct funcionario vetor[], char nome[]){
	int i;
	for(i=0; i<numeroMaximo; i++){
		if(vetor[i].nome == nome){
			return i;
		}
	}
}

int posFuncionarioId(struct funcionario vetor[], int id){
	int i;
	for(i=0; i<numeroMaximo; i++){
		if(vetor[i].id == id){
			return i;
		}
	}
}

void listaFuncionarios(struct funcionario vetor[]){
	int i;
	for(i = 0; i<numeroMaximo; i++){
		printf("%s, %d\n", vetor[i].nome, vetor[i].id);
	}
}

int ultimoFuncionario(struct funcionario vetor[]){
	int i;
	for(i=0; i<numeroMaximo; i++){
		if(vetor[i].nome == ""){
			return i;
		}
	}
}


int main(){
	struct funcionario vetor[numeroMaximo]; 
	int numeroFuncionarios = 0;
	
	lerBD(vetor, numeroFuncionarios);
	listaFuncionarios(vetor);
	//CONSERTAR BANCO DE DADOS. ESTÁ DANDO ESTOURO DE MEMÓRIAS POR CAUSA QUE ARMAZENAMOS 10 POSIÇÕES
	
	return 0;
}
