#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct nodoArv{
	char palavra [20];
	char significado [50];
	int contador;
	struct nodoArv *esq;
	struct nodoArv *dir;
}elemento;

struct nodolist{
	char letra [2];
	struct nodoArv *raiz;
	struct nodolist *prox;
}lista;

struct nodoArv *raiz;

struct nodolist *inicio, *alfa;

int totalconsulta = 0;
int contapalavras = 0;

// Procedimento para inserção no inicio da lista
void insere_letra(char dado []){

	alfa = (struct nodolist*)malloc(sizeof(lista));
	if(consulta(dado) != 1){
		alfa->prox = NULL;
		strcpy(alfa->letra, dado);
		if(inicio == NULL){
			inicio = alfa;
		}
		else{
			alfa->prox = inicio;
			inicio = alfa;
		}
	}
	else{

	}

}

int consulta(char valor [])
{
  int resp = 0;
  struct nodolist *atual = inicio;
  while(atual != NULL){
	 if(atual->letra == valor){
        resp = 1;
     }
	 atual = atual->prox;
  }
  return resp;
}


//Procedimento para criar nodo da Arvore
void insereNodo( struct nodoArv * atual, struct nodoArv * novo ){
	if( novo->palavra < atual->palavra ){
		if( atual->esq == NULL ){
			atual->esq = novo;
		}
		else
		  insereNodo( atual->esq, novo);
	}
	else{
		if( atual->dir == NULL){
			atual->dir = novo;

		}
		else
		  insereNodo( atual->dir, novo );
	 }
}

//Procedimento para inserir elemento na arvore
void insere_palavra(char pal [], char sig []){

	struct nodoArv * novo;
	novo = (struct nodoArv *) malloc(sizeof(elemento));
	strcpy( novo->palavra, pal);
	strcpy( novo->significado, sig);
	novo->esq = NULL;
	novo->dir = NULL;
	contapalavras = contapalavras + 1;

	if( raiz == NULL )
	  raiz = novo;
	else
	  insereNodo( raiz, novo );
}

struct nodoArv * pesq_arv_pal( struct nodoArv * raiz, char p []){
	struct nodoArv * res = NULL;
	if( raiz != NULL ){

		if(strcmp(raiz->palavra, p) == 0){
			res = raiz;
			printf("\nPalavra encontrada!");
			raiz->contador = raiz->contador +1;
			totalconsulta = totalconsulta + 1;
		}
		else{
			if(strcmp(raiz->palavra, p) < 0){
				res = pesq_arv_pal( raiz->esq, p );
			}
			else{
				res = pesq_arv_pal( raiz->dir, p );
			}
		}
	}
	return res;
}
struct nodoArv * pesq_palavra( char p[] ){
	struct nodoArv * res = pesq_arv_pal( raiz, p );
	return res;
}

struct nodoArv * pesq_arv_sig( struct nodoArv * raiz, char p []){
	struct nodoArv * res = NULL;
	if( raiz != NULL ){

		if(strcmp(raiz->palavra, p) == 0){
			res = raiz;
			printf("\nPalavra %s", raiz->palavra);
			printf("\nSignificado: %s", raiz->significado);
			raiz->contador = raiz->contador +1;
			totalconsulta = totalconsulta + 1;
		}
		else{
			if(strcmp(raiz->palavra, p) < 0){
				res = pesq_arv_sig( raiz->esq, p );
			}
			else{
				res = pesq_arv_sig( raiz->dir, p );
			}
		}
	}
	return res;
}
struct nodoArv * most_significado( char p[] ){
	struct nodoArv * res = pesq_arv_sig( raiz, p );
	return res;
}

struct nodoArv* menor_valor(struct nodoArv *raiz)
{
    if(raiz == NULL)
        return NULL;
    else if(raiz->esq != NULL)
        return menor_valor(raiz->esq);
    return raiz;
}


struct nodoArv* remover(struct nodoArv *raiz, char p [])
{
    if(raiz == NULL)
        return NULL;
    if (strcmp(raiz->palavra, p) > 0)
        raiz->dir = remover(raiz->dir, p);
    else if(strcmp(raiz->palavra, p) < 0)
        raiz->esq = remover(raiz->esq, p);
    else
    {

        if(raiz->esq==NULL && raiz->dir==NULL)
        {
            free(raiz);
            return NULL;
        }


        else if(raiz->esq==NULL || raiz->dir==NULL)
        {
            struct nodoArv *temp;
            if(raiz->esq==NULL)
                temp = raiz->dir;
            else
                temp = raiz->esq;
            free(raiz);
            return temp;
        }

        else
        {
            struct nodoArv *temp = menor_valor(raiz->dir);
            strcpy(raiz->palavra, temp->palavra);

            raiz->dir = remover(raiz->dir, temp->palavra);
        }
    }
    return raiz;
}

struct nodoArv * remover_palavra( char p[] ){
	struct nodoArv * res = remover( raiz, p );
	return res;
}

void total_consulta (){
	printf("Total de consulta: %d", totalconsulta);
}


struct nodoArv * pesq_arv_consulta( struct nodoArv * raiz, char p []){
	struct nodoArv * res = NULL;
	if( raiz != NULL ){

		if(strcmp(raiz->palavra, p) == 0){
			res = raiz;
			printf("\nTotal de consulta da palavra %s: %d", raiz->palavra, raiz->contador);
		}
		else{
			if(strcmp(raiz->palavra, p) < 0){
				res = pesq_arv_consulta( raiz->esq, p );
			}
			else{
				res = pesq_arv_consulta( raiz->dir, p );
			}
		}
	}
	return res;
}
struct nodoArv * total_consulta_pal( char p[] ){
	struct nodoArv * res = pesq_arv_consulta( raiz, p );
	return res;
}

void quant_palavras(){
	printf("Quantidade total de palavras: %d", contapalavras);
}

void mostra_pal_ordem( struct nodoArv * raiz){
		if( raiz == NULL )
		  return;
		printf("%s\n",raiz->palavra);

		mostra_pal_ordem( raiz->esq );
		mostra_pal_ordem( raiz->dir );
	}
void mostra_palavra_ordem(){
	mostra_pal_ordem( raiz );
}

void mostra_palavra_let(){

}

void menu(){
	printf("-----------Dicionario-----------");
	printf("\n 1 - Inserir palavra: "); //OK
	printf("\n 2 - Consultar palavra: "); //OK
	printf("\n 3 - Remover palavra: "); //OK
	printf("\n 4 - Conta total de palavras: ");//OK
	printf("\n 5 - Exibe palvras: ");//OK
	printf("\n 6 - Exibe palvras de uma letra: ");
	printf("\n 7 - Exibe significado de uma palavra: ");//OK
	printf("\n 8 - Exibe numero de consultas de uma palavra: ");//ok
	printf("\n 9 - Exibe numero total de consultas: ");//OK
	printf("\n 0 - FIM \n");
}

int main(void) {
	setbuf(stdout, NULL);
	int resp = 1;
	char palavra [20];
	char significado [100];
	char letra[15];

	insere_letra("A");
	insere_palavra("Abelha", "animal que voa");

	insere_palavra("Abelha", "animal que voa");


	menu();
	printf("\nDigite sua opcao: ");
	scanf("%d", &resp);
	fflush(stdin);

	while(resp != 0){
		switch(resp){

			case 1:	printf("\n-------- Inserir palavra --------\n");
					printf("\n Digite a letra a ser inserido a palavra: ");
					gets(letra);
					fflush(stdin);

					printf("\n Digite a palavra a ser inserida: ");
					gets(palavra);
					fflush(stdin);

					printf("\n Digite o significado da palavra %s: ", palavra);
					gets(significado);
					fflush(stdin);

					insere_letra(letra);
					insere_palavra(palavra, significado);

					system("npause");
					break;

			case 2:	printf("\n-------- Consultar palavra -------- ");
					printf("\n Digite a palavra a ser inserida: ");
					gets(palavra);
					fflush(stdin);

					pesq_palavra(palavra);

					system("npause");
					break;

			case 3:	printf("\n-------- Remover palavra -------- ");
					printf("\n Digite a palavra a ser removida: ");
					gets(palavra);
					fflush(stdin);
					remover_palavra(palavra);

					system("npause");
					break;

			case 4:	printf("\n-------- Conta total de palavras -------- ");
					quant_palavras();

					system("npause");
					break;

			case 5: printf("\n-------- Exibe palvras -------- ");
					mostra_palavra_ordem();
					system("npause");
					break;

			case 6:	printf("\n-------- Exibe palvras -------- ");
					printf("Digite a letra:");
					gets(letra);
					fflush(stdin);


					system("npause");
					break;

			case 7:	printf("\n-------- Exibe significado de uma palavra -------- ");
					printf("\n Digite a palavra:");
					gets(palavra);
					fflush(stdin);

					most_significado (palavra);

					system("\npause");
					break;


			case 8:	printf("\n-------- Exibe total de consulta de uma palavra -------- ");
					printf("\n Digite a palavra:");
					gets(palavra);
					fflush(stdin);

					total_consulta_pal(palavra);
					system("\npause");
					break;

			case 9:	printf("\n-------- Exibe total de consulta -------- ");
					total_consulta();
					system("\npause");
					break;

			case 0:	system("\npause");
					break;

		}
		menu();
		fflush(stdin);
		printf("\nDigite sua opcao: ");
		scanf("%d", &resp);
		fflush(stdin);
	}
	return EXIT_SUCCESS;
}
