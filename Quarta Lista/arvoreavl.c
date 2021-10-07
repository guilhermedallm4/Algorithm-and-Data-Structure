#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct Nodo{
    int key;
    struct Nodo *pRight, *pLeft;
}Nodo;



void *addNodo(int number, Nodo *pRaiz);
void insert(Nodo *pRaiz, Nodo *pNodo);
void listThree(Nodo *pRaiz);
void cleanThree(Nodo *pRaiz);


int main(){
    Nodo *pRaiz = NULL;
    int nNodos;
    printf("Digite a quantidade de nodos: ");
    scanf("%d", &nNodos);
    pRaiz = addNodo(nNodos, pRaiz);
    printf("\n");
    listThree(pRaiz);
    printf("\n");
    cleanThree(pRaiz);

}

// Add Ok
void *addNodo(int number, Nodo *pRaiz){
    int i;

    srand(time(0));

    for(i = 0;i<number;i++){ 
        Nodo *pNodo = (Nodo *)malloc(sizeof(Nodo));
        
        if(!pNodo){
            printf("Erro de alocação de memória!");
            exit(0);
         }
        
        pNodo->key = (rand());
        pNodo->pRight = NULL;
        pNodo->pLeft = NULL;
        
    if(i == 0){
        pRaiz = pNodo;

    }
    else{
        insert(pRaiz, pNodo);
        
    }
    
}
    return pRaiz;
}
//Inserir OK
void insert(Nodo *pRaiz, Nodo *pNodo){
    Nodo *pInsert;
    pInsert = pRaiz;
 
    while(pInsert != NULL){

        if(pInsert->key >= pNodo->key){
            if(pInsert->pLeft == NULL){
                pInsert->pLeft = pNodo;
               
                return ;
            }
                pInsert = pInsert->pLeft;
        }

        else if(pInsert->key < pNodo->key){
            if(pInsert->pRight == NULL){
                pInsert->pRight = pNodo;
                return;
            }
            pInsert = pInsert->pRight;
        }
    }
}

//Listar ok
void listThree(Nodo *pRaiz) {
    Nodo *pRun = pRaiz;
    
    if(pRun != NULL) {
       printf("%d(", pRun->key);
        listThree(pRun->pLeft);
        listThree(pRun->pRight);
        printf(")");
    }

}

void cleanThree(Nodo *pRaiz){
    if(pRaiz == NULL){
        return 0;
    }
    cleanThree(pRaiz->pLeft);
    cleanThree(pRaiz->pRight);
    free(pRaiz);

}