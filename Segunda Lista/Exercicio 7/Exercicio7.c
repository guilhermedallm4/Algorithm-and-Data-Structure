#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME (sizeof(char)*10)
#define IDADE (sizeof(int))
#define ALTURA (sizeof(float))
#define OPCAO (sizeof(int))
#define NNOME (sizeof(int))

void *inserir(void *pBuffer);
void list(void *pBuffer);
int pessoa = 10;

int main(){
    void *pBuffer;
    pBuffer = malloc(OPCAO + NNOME);
        if(!pBuffer){
            printf("Erro de memória!");
            exit(1);
        }
        *(int *)(pBuffer + OPCAO) = 0;
    
    do{
        printf("1- Adicionar Pessoa: \n");
        printf("2- Sair: \n");
        scanf("%d", (int *)(pBuffer));
        switch (*(int *)(pBuffer))
        {
        case 1:
            pBuffer = inserir(pBuffer);
            printf("\n");
            pessoa--;
            break;
        case 2:
            list(pBuffer);
            *(int *)(pBuffer) = 2;
            break;
        default:
            printf("Opcao incorreta!\n\n");
            break;
        }
    }while(*(int *)(pBuffer) != 2 && pessoa != 0);
    free(pBuffer);
    if(pessoa == 0){
            list(pBuffer);
            free(pBuffer);
    }
}


void *inserir(void *pBuffer){
        pBuffer = realloc(pBuffer, OPCAO + NNOME + (NOME + IDADE + ALTURA) * (*(int *)(pBuffer + OPCAO) + 1));

        printf("Digite o nome: \n");
        scanf("%s",(char *)(pBuffer + OPCAO + NNOME + (NOME + IDADE + ALTURA) * (*(int *)(pBuffer + OPCAO))));
        getchar();
        printf("Digite a idade: \n");
        scanf("%d", (int *)(pBuffer + OPCAO + NNOME + NOME + (NOME + IDADE + ALTURA) * (*(int *)(pBuffer + OPCAO))));
        getchar();
        printf("Digite a altura: \n");
        scanf("%f", (float *)(pBuffer + OPCAO + NNOME + NOME + IDADE + (NOME + IDADE + ALTURA) * (*(int *)(pBuffer + OPCAO))));
        getchar();
        *(int *)(pBuffer + OPCAO) = (*(int *)(pBuffer + OPCAO) + 1);
        return pBuffer;
}

void list(void *pBuffer){
    if(*(int *)(pBuffer + OPCAO) == 0){
        printf("A lista está vazia!\n");
    }
    else{
        for(*(int *)(pBuffer) = 0; *(int *)(pBuffer) < *(int *)(pBuffer + OPCAO); *(int *)(pBuffer) = *(int *)(pBuffer) + 1){
            printf("Pessoa %d:\n", *(int *)(pBuffer)+1);
            printf("Nome: %s\n", (char *)(pBuffer + OPCAO + NNOME + (NOME + IDADE + ALTURA) * (*(int *)(pBuffer))));
            printf("Idade: %d\n", *(int *)(pBuffer + OPCAO + NNOME + NOME + (NOME + IDADE + ALTURA) * (*(int *)(pBuffer))));
            printf("Nome: %.2f\n", *(float *)(pBuffer + OPCAO + NNOME + NOME + IDADE + (NOME + IDADE + ALTURA) * (*(int *)(pBuffer))));
            printf("\n");
        }
    }
}