#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Variaveis contador
#define OPTION (sizeof(int))
#define CONTADOR (sizeof(int))
#define AUX_CHAR (sizeof(char)*10)

//Variaveis linkedlist
#define NAME (sizeof(char)*10)
#define AGE (sizeof(int))
#define NUMBER (sizeof(int))
#define PROX (sizeof(void **))
#define ANTERIOR (sizeof(void **))

void *addPerson(void *pBuffer, void *linkedlist,  void *pFirst);
void show(void *pFirst, void *pRun);
void search(void *pFirst, void *pRun, void *pBuffer);


int main(){
    void *linkedlist;
    void *pFirst;
    void *pRun;
    void *pBuffer = malloc(OPTION + CONTADOR + AUX_CHAR);
     if(!pBuffer){
                printf("Erro de memória!");
                exit(0);
            }
    pFirst = NULL;
    *(int *)(pBuffer + OPTION) = 0;
    do{
        printf("Digite a opção: \n");
        printf("1 - Adicionar\n2-Remover\n3-Buscar\n4-Listar\n5-Sair\n");
        scanf("%d", (int *)pBuffer);
        getchar();
        printf("\n");
       switch (*(int *)pBuffer)
        {
        case 1:
            *(int *)(pBuffer + OPTION) = *(int *)(pBuffer + OPTION) + 1;
            pFirst = addPerson(pBuffer, linkedlist, pFirst);
            printf("\n");
            break;
        
        case 3:
            search(pFirst, pRun, pBuffer);
            break;
        case 4:
            show(pFirst, pRun);
            break;
        default:
            printf("Opção Invalida!\n");
            break;
        }
    }while(*(int *)pBuffer != 5);

}

void *addPerson(void *pBuffer, void *linkedlist, void *pFirst){
    linkedlist = malloc(NAME + AGE + NUMBER + ANTERIOR + PROX); 
    *(void **)(linkedlist + NAME + AGE + NUMBER ) = NULL;
    *(void **)(linkedlist + NAME + AGE + NUMBER + ANTERIOR ) = NULL;
    void *aux;

     if(*(int *)(pBuffer + OPTION) == 1){
        pFirst = linkedlist;
        *(void **)(linkedlist + NAME + AGE + NUMBER) = linkedlist;
    }

   else if(*(int *)(pBuffer + OPTION) != 1){
       *(int *)((pFirst + (NAME + AGE + NUMBER + ANTERIOR) * (*(int *)(pBuffer + OPTION) - 1))) = linkedlist;  
        *(void **)(linkedlist + NAME + AGE + NUMBER) = linkedlist - 40;
        
        printf("%p\n", *(void **)(linkedlist + NAME + AGE + NUMBER));
    }
    printf("%p\n", linkedlist);
    printf("Digite o nome: ");
     scanf("%s", (char *)(linkedlist)); // Adicionando nome;
      printf("Digite a idade: ");
       scanf("%d", (int *)(linkedlist + NAME)); // Adicionando Idade;
       printf("Digite o numero: ");
       scanf("%d", (int *)(linkedlist + NAME + AGE)); // Adicionando numero;
      printf("\n");
    return pFirst;

}


void show(void *pFirst, void *pRun){
        pRun = pFirst;
        
      while(pRun != NULL){
          printf("%s\n", pRun);
          printf("%d\n", *(int *)(pRun + NAME));
          printf("%d\n", *(int *)(pRun + NAME + AGE));
          printf("\n");
         pRun = *(int *)(pRun + NAME + AGE + NUMBER + ANTERIOR);
      }    
      return 0;
}


void search(void *pFirst, void *pRun, void *pBuffer){
    printf("Digite o nome que queira buscar: ");
    scanf("%s", (char *)(pBuffer + OPTION + CONTADOR));
    pRun = pFirst;
    while(pRun != NULL){
        if(strcmp(pRun,(char *)(pBuffer + OPTION + CONTADOR)) == 0){
          printf("%s\n", pRun);
          printf("%d\n", *(int *)(pRun + NAME));
          printf("%d\n", *(int *)(pRun + NAME + AGE));
          return ;
        }
      pRun = *(int *)(pRun + NAME + AGE + NUMBER + ANTERIOR);
    }
    printf("Nome não encontrado!\n");
    return;
}