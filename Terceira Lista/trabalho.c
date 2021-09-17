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
void *removed(void *pFirst, void *pBuffer, void *pRun);
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
            pFirst = (void *)addPerson(pBuffer, linkedlist, pFirst);
            printf("\n");
            break;

        case 2:
            if(*(int *)(pBuffer + OPTION) == 0){
                printf("Lista vazia!\n");
                printf("\n");
                break;
            }
            else{
            pFirst = (void *)removed(pFirst, pBuffer, pRun);
            *(int *)(pBuffer + OPTION) = *(int *)(pBuffer + OPTION) - 1;
            break;
            }

        case 3:
            search(pFirst, pRun, pBuffer);
            printf("\n");
            break;

        case 4:
            show(pFirst, pRun, pBuffer);
            printf("\n");
            break;

        case 5:
            printf("SAINDO!!!\n");
            break;

        default:
            printf("Opção Invalida!\n");
            break;
        }
    }while(*(int *)pBuffer != 5);
}

void *addPerson(void *pBuffer, void *linkedlist, void *pFirst){
    linkedlist = malloc(NAME + AGE + NUMBER + ANTERIOR + PROX); //Aloca um espaço pro Linkedlist
    void *aux;
    void *aux_2;

      printf("Digite o nome: ");
      scanf("%s", (char *)linkedlist); // Adicionando nome;
        printf("Digite a idade: ");
        scanf("%d", (int *)(linkedlist + NAME)); // Adicionando Idade;
        printf("Digite o numero: ");
       scanf("%d", (int *)(linkedlist + NAME + AGE)); // Adicionando numero;
      printf("\n");
    *(void **)(linkedlist + NAME + AGE + NUMBER ) = NULL; //Zera o anterior
    *(void **)(linkedlist + NAME + AGE + NUMBER + ANTERIOR ) = NULL; //Zera o Proximo
    
    if(*(int *)(pBuffer + OPTION) == 1){
        *(void **)pFirst = linkedlist;
        *(void **)(pFirst + PRIMEIRO) = linkedlist;
    }

    else if(*(int *)(pBuffer + OPTION) != 1){
        *(int *)(pBuffer) = 1;
            aux = *(void **)pFirst;
        
            while(aux != NULL){
                if(strcmp((char *)linkedlist, (char *)aux) < 0){
                    
                    if(*(int *)(pBuffer) == 1){
                        *(void **)(linkedlist + NAME + AGE + NUMBER + ANTERIOR) = aux;
                        *(void **)(aux + NAME + AGE + NUMBER) = linkedlist;
                        *(void **)(linkedlist + NAME + AGE + NUMBER) = NULL;
                        *(void **)pFirst = linkedlist;
                        return pFirst;
                   }
                    else{
                        
                            aux_2 = *(void **)(aux + NAME + AGE + NUMBER); // atribui a aux_2 o proximo que estava em aux;
                            *(void **)(aux_2 + NAME + AGE + NUMBER + ANTERIOR) = linkedlist; // atribui o proximo; A -> B
                            *(void **)(linkedlist + NAME + AGE + NUMBER) = aux_2; //atribui o anterior ao linkedlist B -> A
                            *(void **)(linkedlist + NAME + AGE + NUMBER + ANTERIOR) = aux; // atribui o proximo ao B -> C
                            *(void **)(aux + NAME + AGE + NUMBER) = linkedlist;
                            /*printf("anterior: %p\n",*(void **)(aux_2 + NAME + AGE + NUMBER));
                            printf("Atual: %p\n", linkedlist);*/
                            
                            
                            
                            return pFirst;
                        }

            }
            *(int *)(pBuffer) = *(int *)(pBuffer) + 1; 
            aux = *(void **)(aux + NAME + AGE + NUMBER + ANTERIOR);
             
            }
                if(*(int *)(pBuffer) >= *(int *)(pBuffer + OPTION)){
                        aux = *(void **)(pFirst + PRIMEIRO); // recebe o anterior
                         *(void **)(aux + (NAME + AGE + NUMBER + ANTERIOR)) = linkedlist; // Adiciona o proximo
                         *(void **)(linkedlist + NAME + AGE + NUMBER) = aux; // Adiciona o anterior
                         *(void **)(pFirst + PRIMEIRO) = linkedlist; // Adiciona o atual 
                          return pFirst;
                }
    }
    return pFirst;
}

void show(void *pFirst, void *pRun, void *pBuffer){ // Printar OK
        pRun = *(void **)pFirst;
      if(*(int *)(pBuffer + OPTION) == 0){
          printf("Lista vazia!\n");
            return;
      }
      while(pRun != NULL){
    
          printf("Nome: %s\n", pRun);
          printf("Idade: %d\n", *(int *)(pRun + NAME));
          printf("Numero: %d\n", *(int *)(pRun + NAME + AGE));
          printf("\n");
            pRun = *(void **)(pRun + NAME + AGE + NUMBER + ANTERIOR);
      }    
      return;
}

void search(void *pFirst, void *pRun, void *pBuffer){ // Procurar OK

    if(*(int *)(pBuffer + OPTION) == 0){
          printf("Lista vazia!\n");
            return;
      }
    printf("Digite o nome que queira buscar: ");
    scanf("%s", (char *)(pBuffer + OPTION + CONTADOR));
    pRun = pFirst;
    while(pRun != NULL){
        if(strcmp(pRun,(char *)(pBuffer + OPTION + CONTADOR)) == 0){
          printf("Nome: %s\n", (char *)pRun);
          printf("Idade: %d\n", *(int *)(pRun + NAME));
          printf("Telefone: %d\n", *(int *)(pRun + NAME + AGE));
          printf("%p\n", *(void **)(pRun + NAME + AGE + NUMBER + ANTERIOR));
          return ;
        }
      *(void **)pRun = *(void **)(pRun + NAME + AGE + NUMBER + ANTERIOR);
    }
    printf("Nome não encontrado!\n");
    return;
}

void *removed(void *pFirst, void *pBuffer, void *pRun){ // removendo

        pRun = pFirst;
        *(void **)pFirst = *(void **)(pRun + NAME + AGE + NUMBER + ANTERIOR);
        free(pRun);
        *(void **)(pFirst + NAME + AGE + NUMBER) = NULL;
        printf("Removido com sucesso!\n");
        return pFirst;
}

