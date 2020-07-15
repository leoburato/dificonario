#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


//Estrutura do nodo do curso
struct nodoC{
	int codC;
	char nomeC[10];
	struct nodoC *proxC;
}curso;

struct nodoC *inicio, *ncurso;

//////////////////////////////////////////////////////////////////////////////Cursos/////////////////////////////////////////////////////////////////////////

void insere_curso(int codigC, char vetC [])
{
	ncurso=(struct nodoC*)malloc(sizeof(curso));
	ncurso->codC =codigC;
	ncurso->proxC=NULL;
	strcpy( ncurso->nomeC, vetC);
	if(inicio == NULL){
		inicio = ncurso;
	}
	else{
		ncurso->proxC=inicio;
		inicio=ncurso;

	}
}
int consulta(int valor)// Busca o valor na lista
{
	int resp = 0;
	struct nodoC *atual = inicio;
	while(atual != NULL){
		if(atual->codC == valor){
			resp = 1;
		}
		atual = atual->proxC;
	}
	return resp;
}

void exclui()
{
	struct nodoC *atual = inicio;
	if(inicio != NULL){
		inicio = inicio->proxC;
		free(atual); //libera o espaço ocupado na memória
	}
	else{
		printf("Lista Vazia\n");
	}
}

//remore curso
void remove_curso(int valor)
{
	struct nodoC *atual = inicio;
	struct nodoC *ant = NULL;

	if(inicio != NULL){ //Lista existe
		if(consulta(valor) != 1){ // Verifica se o valor existe na lista
			printf("Valor %d nao existe na lista\n",valor);
		}
		else{
			if(inicio->proxC == NULL){ //testa se a lista só possui um elemento
				// Valor existe na lista, mas a lista só possui um elemento
				free(inicio);
				inicio = NULL;
			}
			else{
				if(atual->codC == valor){ //Lista possui vários elementos e o elemento a ser excluido é o primeiro
					exclui();
				}
				else{ //acha o valor a ser excluído
					while(atual->codC != valor){
						ant = atual;
						atual = atual->proxC;
					}
					ant->proxC = atual->proxC;
					free(atual);
				}
			}
		}
	}
	else{
		printf("Lista Vazia\n");
	}
}


long int conta_lista (struct nodoC *inicio ) {

     long int count = 0;

     while( inicio != NULL ) {
    	 	inicio = inicio->proxC;
            count++;
     }
     return count;
}

struct nodoC* proximo_Elemento ( struct nodoC *inicio, int pos ){

	if( pos > conta_lista(inicio ) - 1 ) {
		return NULL;
	}

	int count = 0;
	struct nodoC *aux = inicio;

	while ( count < pos ) {
		aux = aux->proxC;
		count++;
	}

	return aux;
}

void bubbleSort( struct nodoC *inicio ) {

     register int i, j;
     char auxn [10];


     for( i = conta_lista( inicio ) - 1; i >= 0; i-- ) {
          for( j = 1; j <= i; j++ ) {
               if(  proximo_Elemento( inicio, j - 1 )->codC > proximo_Elemento( inicio, j )->codC ) {
                   	int aux = proximo_Elemento( inicio, j - 1 )->codC;
                   	strcpy( auxn , proximo_Elemento( inicio, j - 1 )->nomeC);
                    proximo_Elemento( inicio, j - 1 )->codC = proximo_Elemento( inicio, j )->codC;
                	strcpy(proximo_Elemento( inicio, j - 1 )->nomeC, proximo_Elemento( inicio, j )->nomeC );
                    proximo_Elemento( inicio, j )->codC = aux;
                    strcpy(proximo_Elemento( inicio, j )->nomeC,auxn);
               }
          }
     }
}

void bubbleSort_nome( struct nodoC *inicio ) {

     register int i, j;
     char auxn [10];


     for( i = conta_lista( inicio ) - 1; i >= 0; i-- ) {
          for( j = 1; j <= i; j++ ) {
               if(strcmp(proximo_Elemento( inicio, j - 1 )->nomeC, proximo_Elemento( inicio, j )->nomeC) > 0 ) {
            		int aux = proximo_Elemento( inicio, j - 1 )->codC;
					strcpy( auxn , proximo_Elemento( inicio, j - 1 )->nomeC);
					proximo_Elemento( inicio, j - 1 )->codC = proximo_Elemento( inicio, j )->codC;
					strcpy(proximo_Elemento( inicio, j - 1 )->nomeC, proximo_Elemento( inicio, j )->nomeC );
					proximo_Elemento( inicio, j )->codC = aux;
					strcpy(proximo_Elemento( inicio, j )->nomeC,auxn);
               }
          }
     }
}
void mostrar_lista( struct nodoC *inicio ) {

     int count = 0;
     struct nodoC  *aux = inicio;

     while( aux!= NULL ) {
            printf("%d - %s\n", aux->codC,aux->nomeC);
            aux = aux->proxC;
            count++;
     }
}

//////////////////////////////////////////////////////////////////////Alunos///////////////////////////////////////////////////////////////////

void remove_aluno (int matrizA [5][6], int codigC,  int codigA, int mtamanho [5][1]){
	int vetaux [1][6];
	for (int i = 0; i == mtamanho[codigC][0] ; i++){
		if (matrizA[codigC][i] == codigA){
			vetaux [codigC][i] = matrizA[codigC][i+1];
			matrizA[codigC][i] = vetaux [codigC][i];
		}
	}
}

void alunos_de_curso(int matrizA [5][6], int codigC, int mtamanho [5][1]){

	printf("\nCurso: %d", codigC);
	for(int i=0; i<= mtamanho[codigC][0];i++){
		printf("\nId aluno: %d", matrizA[codigC][i]);
	}
}

void ordena_alunos (int matrizA [5][6], int tamanhoCursos, int tamanho[5][1], int vetoridcurso [5]){
	int aux=0, vetunit [30], indice = 0;
	for (int j=0; j< tamanhoCursos; j++){
		for(int i=0; i<= tamanho[vetoridcurso[j]][0]; i++){
			vetunit [indice] = matrizA[vetoridcurso[j]][i];
//			printf("\n%d", vetunit[indice]);
			indice = indice + 1;

		}
	}
	for (int k = indice - 1; k > 0; k--) {

        for (int j = 0; j < k; j++) {

            if (vetunit[j] > vetunit[j + 1]) {
                aux          = vetunit[j];
                vetunit[j]     = vetunit[j + 1];
                vetunit[j + 1] = aux;
            }
        }
    }

	printf("Id dos alunos: ");

	for (int i = 0; i<indice; i++){
		printf("\n%d", vetunit[i]);
	}
}


void alunos_de_curso_6(int matrizA [5][6], int codigC, int mtamanho [5][1]){

	if (mtamanho[codigC][0] == 5){
		printf("\nCurso: %d", codigC);
		for(int i=0; i<= mtamanho[codigC][0];i++){
			printf("\nId aluno: %d", matrizA[codigC][i]);
		}
	}
	else{
		printf("\nNao a curso com 6 alunos!\n");
	}

}

////////////////////////////////////////////////////Menu//////////////////////////////////////////
void menu(){

	printf("\n-----------Centro de cursos (CCSO)-----------\n");
	printf("1 - Insere curso: \n");//ok
	printf("2 - Insere aluno no curso: \n");//ok
	printf("3 - Remove curso: \n");//ok
	printf("4 - Remove aluno no curso: \n");//ok
	printf("5 - Exibir curso em execucao em ordem de nome: \n");//ok
	printf("6 - Exibir curso em execucao em ordem de ID: \n");//ok
	printf("7 - Exibir ID de alunos de um curso: \n");//ok
	printf("8 - Exibir ID de todos os alunos: \n");//ok
	printf("9 - Exibir curso que tem 6 alunos: \n");//ok
	printf("10 - Exibir informações de um curso: \n");
	printf("0 - FIM \n");

}


int main(void) {
	setbuf(stdout, NULL);
	char adic = 's';
	int resp = 1;


	int IDcurso = 0, IDaluno = 0;
	char nomecurso [10];
	int matrizID[5][6], mTamanho[5][1], mTamanhoC = 0, vetoridcurso[5];
	int valmatriz=0;

	menu();
	printf("\nDigite sua opcao: ");
	scanf("%d", &resp);
	fflush(stdin);

	while(resp != 0 && resp < 11){
		switch(resp){

			case 1:	printf("1 - Insere curso: \n");
					printf("\nDigite o ID do curso: ");
					scanf("%d",&IDcurso);
					fflush(stdin);
					printf("\nDigite o nome do curso: ");
					gets(nomecurso);
					fflush(stdin);

					insere_curso(IDcurso, nomecurso);
					system("pause");
					break;


			case 2: printf("2 - Insere aluno no curso: \n");
					printf("\nDigite o ID do curso: ");
					scanf("%d",&IDcurso);
					int cont = 0, aux = 1;
					adic = 's';
					vetoridcurso [mTamanhoC] = IDcurso;
					mTamanhoC = mTamanhoC + 1;

					printf("%d", mTamanhoC);
					while(adic != 'n' && cont < 6 ){
						printf("\nDigite o ID do aluno: ");
						scanf("%d",&valmatriz);
						fflush(stdin);
						aux = cont;
						matrizID[IDcurso][cont] = valmatriz;
						mTamanho [IDcurso][0] = aux;
						if(cont< 6){
							printf("\n - Deseja adicionar mais um aluno (S - N): ");
							scanf("%s",&adic);
							fflush(stdin);
							cont = cont +1;
						}

					}

					system("pause");
					break;

			case 3:	printf("3 - Remove curso: \n");
					printf("\nDigite o ID do curso a ser removido: ");
					scanf("%d",&IDcurso);
					fflush(stdin);
					remove_curso(IDcurso);
					printf("\n");
					system("pause");
					break;

			case 4: printf("4 - Remove aluno no curso: \n");
					printf("\nDigite o ID do curso: ");
					scanf("%d",&IDcurso);
					fflush(stdin);
					printf("\nDigite o ID do aluno: ");
					scanf("%d",&IDaluno);
					fflush(stdin);

					remove_aluno (matrizID, IDcurso, IDaluno, mTamanho);
					printf("\n");
					system("pause");
					break;


			case 5:	printf("5 - Exibir curso em execucao em ordem de nome: \n");
					bubbleSort_nome( inicio );
					mostrar_lista(inicio);
					printf("\n");
					system("pause");
					break;

			case 6:	printf("6 - Exibir curso em execucao em ordem de ID: \n");
					bubbleSort( inicio );
					mostrar_lista(inicio);
					printf("\n");
					system("pause");
					break;

			case 7:	printf("\n7 - Exibir ID de alunos de um curso: \n");
					printf("\nDigite o ID do curso: ");
					scanf("%d",&IDcurso);
					fflush(stdin);
					alunos_de_curso(matrizID, IDcurso, mTamanho);
					printf("\n");
					system("pause");
					break;

			case 8: printf("8 - Exibir ID de todos os alunos: \n");
					ordena_alunos(matrizID, mTamanhoC, mTamanho, vetoridcurso);
					printf("\n");
					system("pause");
					break;

			case 9:printf("10 - Exibir curso que tem 6 alunos: \n");
					alunos_de_curso_6(matrizID, IDcurso, mTamanho);
					printf("\n");
					system("pause");
					break;

			case 10:printf("11 - Exibir informações de um curso: \n");
					printf("\nDigite o ID do curso: ");
					scanf("%d",&IDcurso);
					fflush(stdin);
					mostrar_lista(inicio);
					alunos_de_curso(matrizID, IDcurso, mTamanho);
					printf("\n");
					system("pause");
					break;
		}

		menu();
		fflush(stdin);
		printf("\nDigite sua opcao: ");
		scanf("%d", &resp);
	}

	system("pause");


	return EXIT_SUCCESS;
}
