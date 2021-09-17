#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Variaveis contador
#define OPTION (sizeof(int))
#define CONTADOR (sizeof(int))
#define AUX_CHAR (sizeof(char)*20)

//Variaveis Aux
#define ULTIMO (sizeof(void **))
#define PRIMEIRO (sizeof(void **))

//Variaveis linkedlist
#define NAME (sizeof(char)*20)
#define AGE (sizeof(int))
#define NUMBER (sizeof(int))
#define ANTERIOR (sizeof(void **))
#define PROX (sizeof(void **))

void *addPerson(void *pBuffer, void *linkedlist,  void *pFirst);
void *removed(void *pFirst, void *pRun);
void *exitprogam(void *pFirst, void *pRun);
void show(void *pFirst, void *pRun);
void search(void *pFirst, void *pRun, void *pBuffer);

int main(){
    void *linkedlist;
    void *pRun;
    
    void *pFirst = malloc(PRIMEIRO + ULTIMO);
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
            pFirst = (void *)removed(pFirst, pRun);
            *(int *)(pBuffer + OPTION) = *(int *)(pBuffer + OPTION) - 1;
            break;
            }

        case 3:
        if(*(int *)(pBuffer + OPTION) == 0){
          printf("Lista vazia!\n");
            break;
        }
        else{
                search(pFirst, pRun, pBuffer);
                printf("\n");
                break;
        }

        case 4:
              if(*(int *)(pBuffer + OPTION) == 0){
              printf("Lista vazia!\n");
              break;
      }
      else{
            show(pFirst, pRun);
            printf("\n");
            break;
      }

        case 5:
            printf("SAINDO!!!\n");
            pFirst = exitprogam(pFirst, pRun);
            free(pFirst);
            free(pBuffer);
            exit(0);
            break;

        default:
            printf("Opção Invalida!\n");
            break;
        }
    }while(*(int *)pBuffer != 5);
}

void *addPerson(void *pBuffer, void *linkedlist, void *pFirst){ // Ordenar OK
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
                        *(int *)(pBuffer) = 1;
                        return pFirst;
                   }
                    else{
                        
                            aux_2 = *(void **)(aux + NAME + AGE + NUMBER); // atribui a aux_2 o proximo que estava em aux;
                            *(void **)(aux_2 + NAME + AGE + NUMBER + ANTERIOR) = linkedlist; // atribui o proximo; A -> B
                            *(void **)(linkedlist + NAME + AGE + NUMBER) = aux_2; //atribui o anterior ao linkedlist B -> A
                            *(void **)(linkedlist + NAME + AGE + NUMBER + ANTERIOR) = aux; // atribui o proximo ao B -> C
                            *(void **)(aux + NAME + AGE + NUMBER) = linkedlist;              
                            *(int *)(pBuffer) = 1;
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
                         *(int *)(pBuffer) = 1;
                          return pFirst;
                }
    }
    return pFirst;
}

void show(void *pFirst, void *pRun){ // Printar OK
        pRun = *(void **)pFirst;
      while(pRun != NULL){
    
          printf("Nome: %s\n", (char *)pRun);
          printf("Idade: %d\n", *(int *)(pRun + NAME));
          printf("Numero: %d\n", *(int *)(pRun + NAME + AGE));
          printf("\n");
            pRun = *(void **)(pRun + NAME + AGE + NUMBER + ANTERIOR);
      }    
      return;
}

void search(void *pFirst, void *pRun, void *pBuffer){ // Procurar OK

    printf("Digite o nome que queira buscar: ");
    scanf("%s", (char *)(pBuffer + OPTION + CONTADOR));
    pRun = *(void **)pFirst;
    while(pRun != NULL){
        if(strcmp(pRun,(char *)(pBuffer + OPTION + CONTADOR)) == 0){
          printf("Nome: %s\n", (char *)pRun);
          printf("Idade: %d\n", *(int *)(pRun + NAME));
          printf("Telefone: %d\n", *(int *)(pRun + NAME + AGE));
          return ;
        }
      pRun = *(void **)(pRun + NAME + AGE + NUMBER + ULTIMO);
    }
    printf("Nome não encontrado!\n");
    return;
}

void *removed(void *pFirst, void *pRun){ // Removendo OK

        pRun = *(void **)pFirst;
        *(void **)pFirst = *(void **)(pRun + NAME + AGE + NUMBER + ANTERIOR);
        free(pRun);
        *(void **)(pFirst + NAME + AGE + NUMBER) = NULL;
        printf("Removido com sucesso!\n");
        return pFirst;
}

void *exitprogam(void *pFirst, void *pRun){ // LIBERAR MEMÓRIA OK
    pRun = *(void **)pFirst;
    while(pRun != NULL){
        *(void **)pFirst = *(void **)(pRun + NAME + AGE + NUMBER + ANTERIOR);
        free(pRun);
        pRun = *(void **)pFirst;
    }
    free(pRun);

    return pFirst;
}