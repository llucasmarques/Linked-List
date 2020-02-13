/*
 * UFMT - UNIVERSIDADE FEDERAL DE MATO GROSSO
 * Disciplina de ED1 - Prof. Ivairton
 * 
 * Realização do exercicio 1 
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#include "implemeta.c"

int main(){

    tipoLista *lst1,*lst2,*lst3;
    lst1 = NULL;
    lst2 = NULL;
    lst3 = NULL;
    
    insereFim(&lst1,0);
    insereFim(&lst1,4);
    insereFim(&lst1,6);
    insereFim(&lst1,8);
    
    
    insereFim(&lst2,1);
    insereFim(&lst2,3);
    insereFim(&lst2,5);
    insereFim(&lst2,7);
    
    printf("Valor ordenado: \n");
    uniao(&lst1,&lst2,&lst3);
    imprimeLista(lst3);
    printf("\n\n\n");
}