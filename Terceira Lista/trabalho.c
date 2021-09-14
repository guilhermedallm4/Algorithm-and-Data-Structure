#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPTION (sizeof(int))
#define CONTADOR (sizeof(int))


#define NAME (sizeof(char)*10)
#define AGE (sizeof(int))
#define NUMBER (sizeof(int))
#define PROX (sizeof(int))

void *addPerson(void *linkedlist, void *pBuffer);

int main(){
    void *pBuffer = malloc(OPTION + CONTADOR);
     if(!pBuffer){
                printf("Erro de memória!");
                exit(0);
            }
    void *linkedlist = malloc(NAME + AGE + NUMBER + PROX);
     if(!linkedlist){
                printf("Erro de memória!");
                exit(0);
            }
    int *pFirst;
    pFirst = (int *)malloc(sizeof(int));
    if(!pBuffer){
        printf("Erro de memória!");
        exit(1);
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
            *(int *)(pBuffer + OPTION) += 1;
            if(*(int *)(pBuffer + OPTION) == 1){
                pFirst = linkedlist;
            }
            linkedlist = addPerson(linkedlist, pBuffer);
            *(int *)(linkedlist + NAME + AGE + NUMBER + (NAME + AGE + NUMBER + PROX) * (*(int *)(pBuffer + OPTION) - 1)) = (char *)(linkedlist + (NAME + AGE + NUMBER + PROX) * (*(int *)(pBuffer + OPTION)));
            printf("%s", (char *)(linkedlist + (NAME + AGE + NUMBER + PROX) * (*(int *)(pBuffer + OPTION) -1)));
            break;
        
        default:
            printf("Opção Invalida!\n");
            break;
        }
    }while(*(int *)pBuffer != 5);

}

 void *addPerson(void *linkedlist, void *pBuffer){
     linkedlist = realloc(linkedlist, (NAME + AGE + NUMBER + PROX) * (*(int *)(pBuffer + OPTION)));
        if(!linkedlist){
            printf("Erro de memória!");
            exit(1);
        }
    printf("Digite o nome: ");
    scanf("%s", (char *)(linkedlist + (NAME + AGE + NUMBER + PROX) * (*(int *)(pBuffer + OPTION) -1)));
    printf("\n");
    printf("Digite a idade: ");
    scanf("%d", (int *)(linkedlist + NAME + (NAME + AGE + NUMBER + PROX) * (*(int *)(pBuffer + OPTION) -1))); // Adiciona a idade
    printf("\n");
    printf("Digite o numero: ");
    scanf("%d", (int *)(linkedlist + NAME + AGE + (NAME + AGE + NUMBER + PROX) * (*(int *)(pBuffer + OPTION) -1))); // Adiciona o numero
    printf("\n");
    *(int *)(linkedlist + NAME + AGE + NUMBER + (NAME + AGE + NUMBER + PROX) * (*(int *)(pBuffer + OPTION)-1)) = NULL; // Adiciona NULL AO PROX

    return linkedlist;
 }
