#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AGE (sizeof(int))
#define NUMBER (sizeof(int))
#define NNAME (sizeof(int))
#define NAME (sizeof(char) * 10)

void *addPerson(void *pBuffer);
void list(void *pBuffer);
void *removed(void *pBuffer);
void search(void *pBuffer);

int main(){

    void *pBuffer = NULL;

    pBuffer = malloc(NNAME); //nNome

    *(int *)pBuffer = 0; //nNome = 0

    if (!pBuffer){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    int option;

    do{
        printf("1-) Adicionar nome:\n");
        printf("2-) Remover nome:\n");
        printf("3-) Listar agenda:\n");
        printf("4-) Buscar nomes na agenda: \n");
        printf("5-) Sair do programa:\n");
        printf("Digite sua opcao: ");
        scanf("%d", &option);
        printf("\n");
        switch (option){
        case 1:
            pBuffer = addPerson(pBuffer);
            printf("\nAdicionado com sucesso!!\n");
            printf("\n");
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
            break;
        }
    } while (option != 5);
}

void *addPerson(void *pBuffer){
    int totalPeople;

    getchar();

    totalPeople = *(int *)pBuffer; //Pega a quantidade de nomes adicionados

    pBuffer = realloc(pBuffer, NNAME + (NAME + AGE + NUMBER) * (totalPeople + 1)); //Faz uma alocação par N° de Nomes + Nome + Idade + telefone
     
    if (!pBuffer){ //Executa um teste memória para ver se foi possível alocar.
        printf("Memoria insuficiente");
        exit (1);
    }
 
    printf("Digite o nome:  ");
    scanf("%s", (char *)pBuffer + NNAME + (NAME + AGE + NUMBER) * totalPeople);
    getchar(); //Limpa a sujeira de teclado
    printf("Digite a idade:  ");
    scanf("%d", (int *)(pBuffer + NNAME + NAME + (NAME + AGE + NUMBER) * totalPeople));  
    getchar(); //Limpa a sujeira de teclado
    printf("Digite o telefone: ");
    scanf("%d", (int *)(pBuffer + NNAME + NAME + AGE + (NAME + AGE + NUMBER) * totalPeople));
    getchar(); //Limpa a sujeira de teclado
      

    *(int *)pBuffer = totalPeople + 1; //armazena o valor de contador ao N° de nomes

    return pBuffer;  // Retorna o valor
}

void list(void *pBuffer){
        int totalPeople;
        int i;
     
        totalPeople = *(int *)pBuffer;
        
        if(totalPeople == 0){
            printf("A lista esta vazia\n\n");
        } else {
            for(i = 0 ; i < totalPeople ; i++){
                printf("Contato %d:\n", i+1);
                printf("Nome: %s\n", (char *)pBuffer + NNAME + (NAME + AGE + NUMBER) * i);
                printf("Idade: %d\n", *(int *)(pBuffer + NNAME + NAME + (NAME + AGE + NUMBER) * i));
                printf("Numero: %d\n", *(int *)(pBuffer + NNAME + NAME + AGE + (NAME + AGE + NUMBER) * i));
                printf("\n");
            }
        }
}

void search(void *pBuffer){
    int totalPeople;
    int i;
    char aux_nome[10];
    
    printf("Digite o nome que queira buscar: ");
    scanf("%s", aux_nome);
    totalPeople = *(int *)pBuffer;
    if(totalPeople == 0){
        printf("\nAgenda vazia, insira algo!\n\n");
        return;
    }
    for(i = 0; i < totalPeople; i++){
        if(strcmp((char *)pBuffer + NNAME + (NAME + AGE + NUMBER) * i ,aux_nome) == 0){
            printf("\nName: %s\n", (char *)pBuffer + NNAME + (NAME + AGE + NUMBER) * i);
            printf("Idade: %d\n", *(int *)(pBuffer + NNAME + NAME + (NAME + AGE + NUMBER) * i));
            printf("Numero: %d\n", *(int *)(pBuffer + NNAME + NAME + AGE + (NAME + AGE + NUMBER) * i));
            printf("\n");
            return;
        }

    }
    printf("\nNome nao encontrado!!\n\n");
    return;

}

void *removed(void *pBuffer){
    int totalPeople, i, j;
    char aux_nome[10];

    totalPeople = *(int *)pBuffer;

    if (totalPeople == 0){
        printf("Agenda esta vazia, insira algo!\n\n");
    } else {
        printf("Digite o nome que queira remover: ");
        scanf("%s", aux_nome);

        for(i = 0; i < totalPeople; i++){
            if(strcmp((char *)pBuffer + NNAME + ((NAME + AGE + NUMBER) * i), aux_nome) == 0) {
                for(j=i;j<totalPeople;j++){ 
                strcpy((char *)pBuffer + NNAME + (NAME + AGE + NUMBER) * j, (char *)pBuffer + NNAME + (NAME + AGE + NUMBER) * (j+1));
                *(int *)(pBuffer + NNAME + NAME + (NAME + AGE + NUMBER) * j) = *(int *)(pBuffer + NNAME + NAME + (NAME + AGE + NUMBER) * (j+1));
                *(int *)(pBuffer + NNAME + NAME + AGE + (NAME + AGE + NUMBER)*j) = *(int *)(pBuffer + NNAME + NAME + AGE + (NAME + AGE + NUMBER) * (j+1));
             }   
                printf("Removido com sucesso!!\n\n");
                *(int *)pBuffer = totalPeople - 1;
                pBuffer = realloc(pBuffer, NNAME + (NAME + AGE + NUMBER) * (totalPeople - 1));
                return pBuffer;
            }
        }
        printf("Nome nao encontrado!\n\n");
    }
    return pBuffer;
}