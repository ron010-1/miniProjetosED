#ifndef BIBLIOTECALISTAS_H
#define BIBLIOTECALISTAS_H

#endif
//O bloco acima, verifica se a biblioteca já foi definida, caso não, ele define, caso sim, só continua.

//Incluindo a biblioteca de entrada e saída, e a biblioteca de alocação de memória dinâmica.
#include<stdio.h>
#include<stdlib.h>

// Criando a estrutura do tipo Lista
struct TipoLista{
		int valor;
		struct TipoLista *proximo;
};

// Definindo do tipo "lista".
typedef struct TipoLista lista;

//Função que calcula o número de objetos da TipoLista.
int contaElementos(struct TipoLista *p){
	if(p == NULL){
		return 0;
	}
	return 1 + contaElementos(p->proximo);
}

//Função que calcula a altura de um objeto da TipoLista. Altura é a distância de um elemento c ao fim da TipoLista.
int altura(struct TipoLista *c){
	if(c == NULL){
		return 0;
	}return 1 + altura(c->proximo);
}

//Função que calcula a profundidade de um objeto na TipoLista. Profundidade é o número de passos que vai da primeira célula atá a célula c.
int profundidade(struct TipoLista *p, struct TipoLista *c){
	if(p == c){
		return 1;
	}return 1 + profundidade(p->proximo, c);
}

//Procedimento que adiciona elementos a minha Lista Encadeada de acordo com o numero digitado pelo usuario.
void lerCelulas(int num, struct TipoLista *p){
	int i, variavelAuxiliar;
	for(i=0; i<num; i++){
		struct TipoLista *NovoNo = malloc(sizeof(lista));
		printf("Insira um numero para a celula %d: ", i+1);
		scanf("%d", &variavelAuxiliar);
		NovoNo->valor = variavelAuxiliar;// Atribui um valor ao nó
		NovoNo->proximo = p->proximo;// Insere o novo nó no início da lista
		p->proximo = NovoNo;// Atualiza a cabeça da lista
	}
}

//Procedimento que imprime todos os elementos da TipoLista.
void imprimeLista(struct TipoLista *p){
	int i;
	struct TipoLista *temp = p->proximo;//Criando um novo ponteiro que recebe o endereço de memória do início da TipoLista, ou seja, o elemento 1.
	printf("\nElementos da Lista: ");
	while(temp != NULL){//O loop acaba no ultimo termo, já que ele irá apontar para um endereço de memória do tipo NULL.
		printf("%d ", temp->valor);
		temp = temp->proximo;
	} printf("\n");//Adiciona um quebra de linha ao fim da impressão.
}

//Procedimento que insere novas células na Lista Encadeada
void insere(int x, struct TipoLista *p){
	struct TipoLista *nova; //Declarando uma nova estrutura lista com o nome nova, de nova celula
	nova = malloc(sizeof(lista));//Alocando memória de acordo com o tamanho da estrutura.
	nova->valor = x;//Recebendo o valor da celula.
	nova->proximo = p->proximo;//Insere o novo nó no início da lista.
	p->proximo = nova;//Alterando a cabeça da lista.
}

//Função que copia a lista e retorna uma nova lista com as mesmas células.
void copiaLista(struct TipoLista *p, struct TipoLista *c){
	if(p == NULL){
		return;
	}else{
		//A estrutura abaixo é quase a mesma do procedimeno insere.
		struct TipoLista *nova; //Declarando uma nova estrutura lista com o nome nova, de nova celula
	    nova = malloc(sizeof(lista));//Alocando memória de acordo com o tamanho da estrutura.
	    nova->valor = p->valor;//Recebendo o valor da celula.
	    nova->proximo = c->proximo;//Insere o novo nó no início da lista.
	    c->proximo = nova;//Alterando a cabeça da lista.
	    copiaLista(p->proximo, c);
	}
}

//Procedimento para remover celula com valor x, mas sem cabe�a. POINTER TO POINTER FUNCTION.
void removeCelula(struct TipoLista *p, int x){
	struct TipoLista *anterior = NULL;
	struct TipoLista *atual = p;
	
	//Laço para encontrar o anterior da célula com valor x.
	while(atual != NULL && atual->valor != x){
		anterior = atual;//Atualizando o ponteiro anterior.
		atual = atual->proximo;//Atualiza o ponteiro p pra próxima célula.
	}
	//Se encontrou o valor x.
	if(atual != NULL){
		//Se o nó não é primeiro
		if(anterior !=NULL){
			anterior->proximo = atual->proximo;
		}else{ //Se o nó é o primeiro
			p = atual->proximo;
		}
	}
	free(atual);
}

//Procedimento que busca uma celula e remove.
// Função que busca e remove um elemento da lista
void buscaERemove(int y, struct TipoLista *p) {
   struct TipoLista *anterior = NULL;
   struct TipoLista *atual = p->proximo; // Avança para o primeiro nó da lista
   while (atual != NULL && atual->valor != y) {
      anterior = atual;
      atual = atual->proximo;
   }
   if (atual != NULL) {
      anterior->proximo = atual->proximo;
      free(atual);
   }
}

// Procedimento que busca e insere uma célula antes de y
void buscaEInsere(int x, int y, struct TipoLista *p) {
   struct TipoLista *anterior = NULL;
   struct TipoLista *atual = p->proximo; // Avança para o primeiro nó da lista
   struct TipoLista *nova = malloc(sizeof(struct TipoLista));
   if (nova == NULL) {
      // Tratar erro de alocação de memória, se necessário
      return;
   }
   nova->valor = x;

   while (atual != NULL && atual->valor != y) {
      anterior = atual;
      atual = atual->proximo;
   }
   nova->proximo = atual;
   anterior->proximo = nova;
}

//Função que retorna se um valor está na lista ou não.
int procuraValor(int num, struct TipoLista *p){
	int i, contador=0;
	while(p->proximo != NULL && p->valor != num){
		p = p->proximo;
		contador++;
	}
	if(p->valor == num){
		return contador;
	}else{
	    return 0; //False, nao encontrou o valor.
	}
}