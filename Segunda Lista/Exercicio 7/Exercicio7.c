#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPTION (sizeof(int))
#define TOTALPEOPLE (sizeof(int))
#define AUX_SEARCH (sizeof(char)*10)
#define AUX_CONTADOR (sizeof(int))


void *addPerson(void *pBuffer);
void list(void *pBuffer);
void *removed(void *pBuffer);
void search(void *pBuffer);

typedef struct{
    char name[10];
    int age;
    int telephone;
}Pessoa;

Pessoa pessoas[10];

int main(){

    void *pBuffer = NULL;

    pBuffer = malloc(OPTION + TOTALPEOPLE + AUX_SEARCH + AUX_CONTADOR);

    if (!pBuffer){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    *(int *)(pBuffer + OPTION) = 0;
    

    do{
        printf("\t1-) Adicionar nome:\n");
         printf("\t2-) Remover nome:\n");
          printf("\t3-) Listar nomes:\n");
           printf("\t4-) Buscar nome: \n");
            printf("\t5-) Sair do programa:\n");
           printf("\t- Opcao: ");
          scanf("%d", (int *)(pBuffer));
         getchar();
        printf("\n");

        switch (*(int *)(pBuffer)) {
            case 1:
                 pBuffer = addPerson(pBuffer);
                break;
            case 2:                
                 pBuffer = removed(pBuffer);
                break;
            case 3:               
                 list(pBuffer);
                break;
            case 4:               
                 search(pBuffer);
                break;
            case 5:               
                  free(pBuffer);
                 exit(0);
                break;
            default:
               
                 printf("\nOpcao invalida, tente novamente!\n");
                break;
        }
    } while ((*(int *)(pBuffer) >= 1) || (*(int *)(pBuffer) <= 5));
}

void *addPerson(void *pBuffer){
    if (*(int *)(pBuffer + OPTION) >= 10) {
        printf("Lista cheia!\n");
         printf("Remova alguem para insirir outra pessoa!\n");
        return pBuffer;

    } else {
        printf("Digite o nome:\n ");
         scanf("%s", &(pessoas + *(int *)(pBuffer + OPTION)) -> name);
          getchar();

        printf("\nDigite a idade:\n ");
         scanf("%d", &(pessoas + *(int *)(pBuffer + OPTION) ) -> age);
          getchar();
    
        printf("\nDigite o telefone:\n ");
         scanf("%d", &(pessoas + *(int *)(pBuffer + OPTION) ) -> telephone);
          getchar();
    }
     *(int *)(pBuffer + OPTION) = *(int *)(pBuffer + OPTION)  + 1;
 

    return pBuffer;
}

void list(void *pBuffer){
        if (*(int *)(pBuffer + OPTION) == 0) {
            printf("Agenda esta vazia, insira algo!\n\n");
             return;
        }else {
            for (*(int *)pBuffer = 0 ; *(int *)pBuffer < *(int *)(pBuffer + OPTION) ; *(int *)pBuffer = *(int *)pBuffer + 1 ){
               printf("Nname [%d]\n", *(int *)pBuffer + 1);
                printf("Nome: %s\n", (pessoas + *(int *)(pBuffer)) -> name);
                 printf("Idade: %d\n", (pessoas + *(int *)(pBuffer)) -> age);
                  printf("Numero: %d\n\n", (pessoas + *(int *)(pBuffer)) -> telephone);
            }
            *(int *)pBuffer = 0;
             return;
        }
}

void search(void *pBuffer){

    if(*(int *)(pBuffer + OPTION) == 0){
         printf("Lista esta vazia!!\n");
          return;
    }
    else{
        printf("Digite o nome que queira buscar: \n");
          scanf("%s", (char *)(pBuffer + OPTION + TOTALPEOPLE));
           getchar();
         for (*(int *)pBuffer = 0 ; *(int *)pBuffer < *(int *)(pBuffer + OPTION) ; *(int *)pBuffer = *(int *)pBuffer + 1 ){
                if(strcmp(((pessoas + *(int *)(pBuffer)) -> name), (char *)(pBuffer + OPTION + TOTALPEOPLE)) == 0){ 
                 printf("Nname [%d]\n", *(int *)pBuffer + 1);
                  printf("Nome: %s\n", (pessoas + *(int *)(pBuffer)) -> name);
                   printf("Idade: %d\n", (pessoas + *(int *)(pBuffer)) -> age);
                    printf("Numero: %d\n\n", (pessoas + *(int *)(pBuffer)) -> telephone);
                    *(int *)pBuffer = 0;
                 return;
            }   
            }
        }
             printf("Nome nao encontrado na lista!\n");
              *(int *)pBuffer = 0;
             return; 
}

void *removed(void *pBuffer){
    
    if(*(int *)(pBuffer + OPTION) == 0){
           printf("Lista esta vazia!!\n");
         return pBuffer;
}
   else{ 
           printf("Digite o nome que queira buscar: \n");
          scanf("%s", (char *)(pBuffer + OPTION + TOTALPEOPLE));
         getchar();
        for (*(int *)pBuffer = 0 ; *(int *)pBuffer < *(int *)(pBuffer + OPTION) ; *(int *)pBuffer = *(int *)pBuffer + 1 ){
                if(strcmp(((pessoas + *(int *)(pBuffer)) -> name), (char *)(pBuffer + OPTION + TOTALPEOPLE)) == 0){

     for(*(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_SEARCH) = *(int *)pBuffer; *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_SEARCH) < *(int *)(pBuffer + OPTION); *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_SEARCH) = *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_SEARCH) + 1){

        *(int *)pBuffer = *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_SEARCH) + 1;
           strcpy(((pessoas +*(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_SEARCH)) -> name), ((pessoas + *(int *)pBuffer) -> name));
          ((pessoas + *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_SEARCH)) -> age) = ((pessoas +*(int *)(pBuffer)) -> age);
        ((pessoas + *(int *)(pBuffer + OPTION + TOTALPEOPLE + AUX_SEARCH)) -> telephone) = ((pessoas +*(int *)(pBuffer)) -> telephone);
     }
        printf("Removido com sucesso!!\n");
          *(int *)(pBuffer + OPTION) = *(int *)(pBuffer + OPTION) - 1;
         *(int *)pBuffer = 0;
        return pBuffer;
    } 
   }
    
          printf("Nome nao encontrado!\n");
         return pBuffer; 
 }

}
