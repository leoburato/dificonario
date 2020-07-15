//#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

   struct nodoArv{
     int info;
     struct nodoArv *esq;
     struct nodoArv *dir;
     struct nodoArv *pai;
   }elemento;
   
   struct nodoArv * raiz; 
   
//-------------------------------------------------------------                  
	void insereNodo( struct nodoArv * atual, struct nodoArv * novo ){
	  	if( novo->info < atual->info ){
	  		if( atual->esq == NULL ){
	  			atual->esq = novo;
	  			atual->esq->pai = atual; //seta o pai
	  		}
	  		else
	  		  insereNodo( atual->esq, novo);
	  	}
	  	else{	  
	  		if( atual->dir == NULL){
	  			atual->dir = novo;
	  			atual->dir->pai = atual;
	  		}
	  		else
	  		  insereNodo( atual->dir, novo );
	     }
	  }	   
   void insere(int dado){
        struct nodoArv * novo;
        novo = (struct nodoArv *) malloc(sizeof(elemento));
        novo->info = dado;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->pai = NULL;
        
		if( raiz == NULL )
		  raiz = novo;
		else
		  insereNodo( raiz, novo );
	}
	
//-------------------------------------------------------------
	void preFix( struct nodoArv * raiz){
		if( raiz == NULL )
		  return;
		printf("%d\n",raiz->info);

		preFix( raiz->esq );
		preFix( raiz->dir );
	}
	void preFixado(){
		preFix( raiz );
	}	
//-------------------------------------------------------------	
	void inFix( struct nodoArv * raiz){
		if( raiz == NULL )
		  return;
		
		inFix( raiz->esq );
		printf("%d\n",raiz->info);
		inFix( raiz->dir );
	}
	void central(){
		inFix( raiz );
	}
//-------------------------------------------------------------		
	void posFix( struct nodoArv * raiz){
		if( raiz == NULL )
		  return;

		posFix( raiz->esq );
		posFix( raiz->dir );
	    printf("%d\n",raiz->info);	
	}
	void posFixado(){
		posFix( raiz );
	}
//-------------------------------------------------------------	
//pesquisa um dado de forma recursiva	
	struct nodoArv * pesq_arv_rec( struct nodoArv * raiz, int d ){		
        struct nodoArv * res = NULL;
		if( raiz != NULL ){
            
		  if(raiz->info == d){
             res = raiz;
          }
          else{
               if(d < raiz->info){
                    res = pesq_arv_rec( raiz->esq, d );
               }
               else{
                    res = pesq_arv_rec( raiz->dir, d );
               }
          }
        }
        return res;
	}
	struct nodoArv * pesquisaRec( int d ){
		struct nodoArv * res = pesq_arv_rec( raiz, d );
		return res;
	}
//-------------------------------------------------------------
// Remoção
    void removeFolha( struct nodoArv * atual){
	// Remove uma folha da árvore - Nodo folha não possui filhos
		struct nodoArv * pai = atual->pai;
		if(pai==NULL){ //o nodo a ser excluído é a raíz da árvore
			raiz = NULL;
		}
		else{
			if(pai->esq == atual){
				pai->esq = NULL;
			}
			else{
				pai->dir=NULL;
			}
		}
		free(atual);
	}
	void removeUmFilho( struct nodoArv * atual ){
	//Remove um nodo que possui um filho
		struct nodoArv * pai = atual->pai;
		if(pai==NULL){//o nodo a ser excluído é a raíz da árvore
			if(atual->esq != NULL){
				raiz = atual->esq;
			}
			else{
				raiz = atual->dir;
			}
			raiz->pai=NULL;
		}
		else{
			if(atual->esq == NULL){
				if(pai->dir == atual){
					pai->dir = atual->dir;
				}
				else{ //pai->esq==atual
					pai->esq=atual->dir;
				}
				atual->dir->pai = pai;
			}
			else{ //atual->dir==null
				if(pai->dir==atual){
					pai->dir=atual->esq;
				}
				else{ //pai.getEsq()==atual
					pai->esq=atual->esq;
				}
				atual->esq->pai = pai;
			}
            free(atual);	
		}
	} // fim da função remove com 1 filho
	
    void removeDoisFilhos( struct nodoArv * atual ){
	//Remove um nodo que possui dois filhos
		struct nodoArv * aux=atual->esq;
		struct nodoArv * pai = NULL;
				
		while(aux->dir!= NULL){//Busca o elemento mais da direita (desce a esq. e depois a direita)
			aux = aux->dir;
		}
		atual->info = aux->info; //atribui o novo valor
		
		//Nodo Folha
		if((aux->esq == NULL) && (aux->dir == NULL)){
            removeFolha(aux);
		}
		else{
            removeUmFilho(aux);
		}				
	}// fim do método
    void remove(int d){
    	struct nodoArv * atual;
    	
    	atual = pesquisaRec( d ); // Verifica se o nodo existe
    	if(atual == NULL){
    		printf("O Elemento %d Nao Esta Presente na Arvore\n",d);
		}
		// Chamada de Funções
		if((atual->esq == NULL) && (atual->dir == NULL))
    		removeFolha(atual);
    	else{
			if((atual->esq != NULL) && (atual->dir != NULL))
    			removeDoisFilhos( atual );
    		else
    			removeUmFilho( atual );
    	}		
    }    	
//-------------------------------------------------------------


int main(){
                          
   insere(100);
   insere(50);
   insere(150);
   insere(35);
   insere(75);
   insere(40);
   insere(45);
   insere(43);
   
   printf("Pre-Fixado\n");
   preFixado();
   
   printf("Central\n");
   central();
   
   printf("Pos-Fixado\n");
   posFixado();
   
   remove(50);
   printf("Central após a remoção\n");
   central();
   
   getch();
   return 0;
}  //end main()
