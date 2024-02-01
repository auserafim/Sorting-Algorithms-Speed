#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"


/**
 * @brief Bubble Sort Algorithm 
 * 
 * @param lst 
 */

void bubbleSort(tipo_lista *lst) {
    int flag_troca, i, aux;
    do {
        flag_troca = 0;
        for(i=0; i< lst->contador-1; i++) {
         if(lst->lista[i] > lst->lista[i+1]) {
            aux = lst->lista[i];
            lst->lista[i] = lst->lista[i+1];
            lst->lista[i+1] = aux;
            flag_troca++;
         }
        }
    } while(flag_troca != 0); //SE HOUVE ALGUMA TROCA, volta para o começo do laço 
}


/**
 * @brief Shell Sort Algorithm 
 * 
 * @param lst 
 */

void shellSort(tipo_lista *lst) {
    //tipo_lista lista;
    int salto, i, flag_troca, aux;
    salto = (int) lst->contador/2;

    while(salto > 1) {
        for(i=0; (i+salto) < lst->contador;i++) {
            if(lst->lista[i] > lst->lista[i+salto]) {
                aux = lst->lista[i];
                lst->lista[i] = lst->lista[i+salto];
                lst->lista[i+salto] = aux;
            }
        }
        salto = (int) salto/2;
    }
   
    // Parte equivalente do bubble sort 
    
    
    
         do {
        flag_troca = 0;
        for(i=0; i< lst->contador-1; i++) {
         if(lst->lista[i] > lst->lista[i+1]) {
            aux = lst->lista[i];
            lst->lista[i] = lst->lista[i+1];
            lst->lista[i+1] = aux;
            flag_troca++;
         }
        }void insertionSort(tipo_lista *lst);

    } while(flag_troca != 0); //SE HOUVE ALGUMA TROCA, volta para o começo do laço 
    

    //bubbleSort(&lista);
 
}

/**
 * @brief Insertion Sort Algorithm (Another implementation)
 * 
 * @param lst 
 */

void insertionSort(tipo_lista *lst) {
    int corte, i, aux; 

    corte = 1;

    while(corte < lst->contador) {

        i = corte;
        
        while((i>0) && (lst->lista[i] < lst->lista[i-1])) {
            aux = lst->lista[i];
            lst->lista[i] = lst->lista[i-1];
            lst->lista[i-1] = aux; 
            i--;
        }

        corte++;
    }

}

/**
 * @brief - Merge Sort Algorithm 
 * 
 * @param lst - ponteiro para estrutura para o tipo Lista (tipo_lista)
**/
    
void mergeSort(tipo_lista *lst){
    merge(lst->lista, lst->contador);
    
}     

void merge(int lst[], int tamanho){

    int meio, i, j, posAux, *lstAux;

    if(tamanho>1){//Verifica se é possivel dividir
        //processo de QUEBRA
        meio = (int) tamanho/2;
        merge(&(lst[0]), meio);
        merge(&(lst[meio]), tamanho - meio);
    
    
        // Processo de Merge
        //aloca um vetor auxiliar vetAux de tamanho "tamanho"
        lstAux = (int*) malloc(sizeof(int)*tamanho);
        i = 0;    
        j = meio;
        posAux = 0;
        
        //Enquanto i e j não atingiram os seus respectivos 'fins'
        while(i<meio && j<tamanho){
            if(lst[i] < lst[j]){
                lstAux[posAux++] = lst[i++];
            }else{
                lstAux[posAux++] = lst[j++];
            }
        }
                        
        // se uma das listas foi finalizada, copia o restante
        while (i < meio){
            lstAux[posAux++] = lst[i++];
            //posAux = posAux + 1;
            //i = i + 1;
        }

        while(j < tamanho){
            lstAux[posAux++] = lst[j++];
            //posAux = posAux + 1;
            //j = j + 1; 
        }

        //Copia o vetor auxiliar para o vetor original
        for(i=0; i<tamanho; i++){
            lst[i] = lstAux[i];
        }
        free(lstAux);//Desaloca da memória VetAux
    }
}






/**
 * @brief Quicksort Algorithm 
 * 
 */


void quickSort(tipo_lista *lst) {

    if(lst->contador > 1) {
        quick(lst->lista, 0, lst->contador-1);
    }
}



void quick(int lst[], int inicio, int fim) {

    int meio, pivo, i_esq, i_dir, aux;

   // Calcula o meio e define o valor do pivo

    meio = (int)((fim - inicio) / 2 ) + inicio;

    pivo = lst[meio];

    i_esq = inicio;

    i_dir = fim;

    while(i_esq < i_dir) {
        while(lst[i_esq] < pivo) {
            i_esq++;
    }

    while(lst[i_dir] > pivo) {
        i_dir--;
    }
    if(i_esq < i_dir) {
        aux = lst[i_esq];
        lst[i_esq] = lst[i_dir];
        lst[i_dir] = aux;
    }

}
    if ((i_dir > inicio) && ((i_dir-inicio) > 1 )) {
        quick(lst, inicio, i_dir);
    }

    if ((i_esq < fim ) && ((fim-i_esq) > 1 )) {
        quick(lst, i_esq, fim);
    }


}