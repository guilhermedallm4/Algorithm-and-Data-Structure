#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Variaveis contador
#define OPTION (sizeof(int))
#define CONTADOR (sizeof(int))

//Variaveis linkedlist
#define NAME (sizeof(char)*10)
#define AGE (sizeof(int))
#define NUMBER (sizeof(int))
#define PROX (sizeof(void **))
#define ANTERIOR (sizeof(void **))

void addPerson(void *pBuffer, void *linkedlist,  void *pFirst);

int main(){
    void *linkedlist;
    void *pFirst;
    void *pBuffer = malloc(OPTION + CONTADOR);
     if(!pBuffer){
                printf("Erro de memória!");
                exit(0);
            }
    
    *(int *)(pBuffer + OPTION) = 0;
    do{
        printf("Digite a opção: \n");
        printf("1 - Adicionar\n2-Remover\n3-Buscar\n4-Listar\n5-Sair\n");
        scanf("%d", (int *)pBuffer);
        getchar();

       switch (*(int *)pBuffer)
        {
        case 1:
            *(int *)(pBuffer + OPTION) = *(int *)(pBuffer + OPTION) + 1;
           addPerson(pBuffer, linkedlist, pFirst);
        
            break;
        default:
            printf("Opção Invalida!\n");
            break;
        }
    }while(*(int *)pBuffer != 5);

}

void addPerson(void *pBuffer, void *linkedlist, void *pFirst){
    linkedlist = malloc(NAME + AGE + NUMBER + ANTERIOR + PROX); 
    *(void **)(linkedlist + NAME + AGE + NUMBER ) = NULL;
    *(void **)(linkedlist + NAME + AGE + NUMBER + ANTERIOR ) = NULL;
    void *aux;
    if(*(int *)(pBuffer + OPTION) == 1){
        pFirst = linkedlist;
        
    }

    printf("Digite o nome: ");
    scanf("%s", (char *)(linkedlist)); // Adicionando nome;
    printf("Digite a idade: ");
    scanf("%d", (int *)(linkedlist + NAME)); // Adicionando Idade;
    printf("Digite o numero: ");
    scanf("%d", (int *)(linkedlist + NAME + AGE)); // Adicionando numero;
    aux = pFirst;  // Aux para percorrer o vetor;
    printf("%p", *(void **)(linkedlist + NAME + AGE + NUMBER + ANTERIOR )); // valor de memória proximo.
    printf("\n");
    printf("%s\n", linkedlist);
    printf("%d\n", *(int *)(linkedlist + NAME));
    printf("%d\n", *(int *)(linkedlist + NAME + AGE));
    printf("\n");
    printf("%p\n", linkedlist);
    do{ // Percorrer toda lista encadeada
                aux = *(void **)(linkedlist + NAME + AGE + NUMBER + ANTERIOR );
                printf("%p\n", aux); // Printa o proximo espaço de memória
                getchar();
    }while(*(void **)(linkedlist + NAME + AGE + NUMBER + ANTERIOR ) != NULL);
    



}