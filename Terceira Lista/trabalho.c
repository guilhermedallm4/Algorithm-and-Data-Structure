#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Variaveis contador
#define OPTION (sizeof(int))
#define CONTADOR (sizeof(int))
#define AUX_CHAR (sizeof(char)*20)

//Variaveis Aux
#define ANTERIOR (sizeof(void **))
#define PRIMEIRO (sizeof(void **))

//Variaveis linkedlist
#define NAME (sizeof(char)*20)
#define AGE (sizeof(int))
#define NUMBER (sizeof(int))
#define PROX (sizeof(void **))

void *addPerson(void *pBuffer, void *linkedlist,  void *pFirst);
void show(void *pFirst, void *pRun, void *pBuffer);
void search(void *pFirst, void *pRun, void *pBuffer);

int main(){
    void *linkedlist;
    void *pRun;
    void *pFirst = malloc(PRIMEIRO + ANTERIOR);
    if(!pFirst){
        printf("Erro de memória!");
                exit(0);
    }
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
            printf("%p\n", pFirst);
            printf("\n");
            break;
        
        case 3:
            search(pFirst, pRun, pBuffer);
            break;
        case 4:
            show(pFirst, pRun, pBuffer);
            break;
        case 5:
            printf("SAINDO!!!\n");
            exit(0);
        default:
            printf("Opção Invalida!\n");
            break;
        }
    }while(*(int *)pBuffer != 5);

    
}

void *addPerson(void *pBuffer, void *linkedlist, void *pFirst){
    linkedlist = malloc(NAME + AGE + NUMBER + ANTERIOR + PROX); //Aloca um espaço pro Linkedlist
    *(void **)(linkedlist + NAME + AGE + NUMBER ) = NULL; //Zera o anterior
    *(void **)(linkedlist + NAME + AGE + NUMBER + ANTERIOR ) = NULL; //Zera o Proximo
    void *aux;
    

    if(*(int *)(pBuffer + OPTION) == 1){
        pFirst = linkedlist;
        *(void **)(pFirst + PRIMEIRO) = linkedlist;
    }
   else if(*(int *)(pBuffer + OPTION) != 1){ 
        aux = *(void **)(pFirst + PRIMEIRO);
        *(void **)(aux + (NAME + AGE + NUMBER + ANTERIOR)) = linkedlist;
        *(void **)(linkedlist + NAME + AGE + NUMBER) = aux;
        *(void **)(pFirst + PRIMEIRO) = linkedlist;
         
    }
        printf("Digite o nome: ");
     scanf("%s", (char *)(linkedlist)); // Adicionando nome;
      printf("Digite a idade: ");
       scanf("%d", (int *)(linkedlist + NAME)); // Adicionando Idade;
       printf("Digite o numero: ");
       scanf("%d", (int *)(linkedlist + NAME + AGE)); // Adicionando numero;
      printf("\n");
    
    return pFirst;

}


void show(void *pFirst, void *pRun, void *pBuffer){
        pRun = pFirst;
        *(int *)(pBuffer) = 1;
      while(pRun != NULL){
          printf("Nome: %s\n", pRun);
          printf("Idade: %d\n", *(int *)(pRun + NAME));
          printf("Numero: %d\n", *(int *)(pRun + NAME + AGE));
          printf("\n");
          *(int *)(pBuffer) += 1;
            pRun = *(void **)(pRun + NAME + AGE + NUMBER + ANTERIOR);
            printf("%p\n", pRun);
      }    
      return;
}


void search(void *pFirst, void *pRun, void *pBuffer){
    printf("Digite o nome que queira buscar: ");
    scanf("%s", (char *)(pBuffer + OPTION + CONTADOR));
    pRun = pFirst;
    while(pRun != NULL){
        if(strcmp(pRun,(char *)(pBuffer + OPTION + CONTADOR)) == 0){
          printf("Nome: %s\n", pRun);
          printf("Idade: %d\n", *(int *)(pRun + NAME));
          printf("Telefone: %d\n", *(int *)(pRun + NAME + AGE));
          printf("%p\n", *(void **)(pRun + NAME + AGE + NUMBER + ANTERIOR));
          return ;
        }
      pRun = *(void **)(pRun + NAME + AGE + NUMBER + ANTERIOR);
    }
    printf("Nome não encontrado!\n");
    return;
}