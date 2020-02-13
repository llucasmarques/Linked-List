/*
 * Implementação
 */




#ifndef LISTA_C
#define LISTA_C


#include <stdio.h>
#include <stdlib.h>

//Definição do tipo nó
struct estruturaLista{
    int dado;
    struct estrutura *prox;
    
};
typedef struct estruturaLista tipoLista;

//Prototipo da função
void insereFim(tipoLista **lst,int valor);
void imprimeLista(tipoLista *lst);
void uniao( tipoLista **lst1, tipoLista **lst2, tipoLista **lst3);
tipoLista* alocaNo(int valor);


//Função de inserção no fim de uma lista encadeada 
void insereFim(tipoLista **lst,int valor){
    tipoLista *novoNo,*aux;
    novoNo = NULL;
    
    //ponteiro auxiliar sera usado para percorrer a lista
    
    if(*lst == NULL){//se nao tiver nada dentro do vetor ele insere o primeiro valor
        novoNo = alocaNo(valor);//aloca esse valor
        *lst = novoNo;//lista estará apontando para esse primeiro valor
    }else{//senão
        novoNo = alocaNo(valor);//senao for o primeiro ele aloca na outra posição
        aux = *lst;
        
        
        while(aux->prox != NULL){
            aux = (tipoLista *)aux->prox;
        }
        aux->prox = (tipoLista*)novoNo;
    }
    
}


//Função para impressao da lista
void imprimeLista(tipoLista *lst){
    while(lst != NULL){
        printf("[%d]",lst->dado);
        lst = (tipoLista *) lst->prox;
        
    }
    printf("\n");
}



//Função que realiza a uniao
void uniao( tipoLista **lst1, tipoLista **lst2, tipoLista **lst3){
    tipoLista *aux1, *aux2,*aux3;
    aux1 = *lst1;
    aux2 = *lst2;
    aux3 = *lst3;
    
    //Enquanto forem diferente da ultimas posição, vai andando ate chegar na ultima posicao
    while(aux1 != NULL &&  aux2 != NULL){
        
        //se o valor de baixo for menor que de cima, coloca no aux3
        if(aux1->dado < aux2->dado){
            //se caso for nulo
            if(aux3 == NULL){
                aux3 = aux1;//aux3 passa a apontar para aux1
                *lst3 = aux3;//recebe o que aux3 aponta(aux1)
            }else{
                aux3->prox = aux1;//aux1 eh o proximo elemento para o qual aux3 tem que apontar
                aux3 = aux3->prox;//caminho com o aux3
            }
            aux1 = aux1->prox;
        }else{
             if(aux3 == NULL){
                aux3 = aux2;//aux3 passa a apontar para aux2
                *lst3 = aux3;//recebe o que aux3 aponta(aux2)
            }else{
                aux3->prox = aux2;
                aux3 = aux3->prox;
            }
            aux2 = aux2->prox;
            
        }
       
    
        
    }
    
    //Se ainda restar elementos na lista 1
    while(aux1 != NULL){
        //se caso for nulo
        if(aux3 == NULL){
                aux3 = aux1;//aux3 passa a apontar para aux1
                *lst3 = aux3;//recebe o que aux3 aponta(aux1)
        }else{
                aux3->prox = aux1;//aux1 eh o proximo elemento para o qual aux3 tem que apontar
                aux3 = aux3->prox;//caminho com o aux3
            }
            aux1 = aux1->prox;
        
    }
    //Se ainda restar elementos na lista 2
    while( aux2 != NULL){
        if(aux3 == NULL){
                aux3 = aux2;//aux3 passa a apontar para aux2
                *lst3 = aux3;//recebe o que aux3 aponta(aux2)
        }else{
                aux3->prox = aux2;
                aux3 = aux3->prox;
            }
            aux2 = aux2->prox;
            
        }
    
        
    
}

tipoLista* alocaNo(int valor){
    tipoLista *novoNo;
    
    novoNo = novoNo = (tipoLista*) malloc(sizeof(tipoLista));
    if(novoNo){
        novoNo->dado = valor;
        novoNo->prox = NULL;
        
    }
    return novoNo;
    
}
#endif