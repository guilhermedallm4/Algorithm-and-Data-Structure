#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NNAME (sizeof(int))
#define NOME (sizeof(char)*10)
#define IDADE (sizeof(int))
#define ALTURA (sizeof(float))

void *inserir(void *adicionar_pessoas);
void list(void *exit);

int main(){
    void *info;
    info = malloc(NNAME);
    
    if(!info){
        printf("Erro de memória!");
        exit(1);
    }
    *(int *)info = 0;

    int opcao;
    do{
        printf("1- Adicionar\n");
        printf("2- Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            info = inserir(info);
            break;
        
        case 2:
            list(info);
            free(info);
            break;
        }
    }while(opcao != 2);
}

void *inserir(void *adicionar_pessoas){
    getchar();
    int totalpessoas;
    totalpessoas = *(int *)adicionar_pessoas;

    adicionar_pessoas = realloc(adicionar_pessoas, NNAME + (NOME + IDADE + ALTURA) * (totalpessoas + 1));
    if(!adicionar_pessoas){
        printf("Erro de memoria!");
        exit(1);
    }
    printf("Digite o nome:  ");
    scanf("%s", (char *)(adicionar_pessoas + NNAME + (NOME + IDADE + ALTURA) * totalpessoas));
    getchar();
    printf("Digite a idade:  ");
    scanf("%d", (int *)(adicionar_pessoas + NNAME + NOME + (NOME + IDADE + ALTURA) * totalpessoas));
    getchar();
    printf("Digite a altura:  ");
    scanf("%f", (float *)(adicionar_pessoas + NNAME + NOME + IDADE + (NOME + IDADE + ALTURA) * totalpessoas));
    getchar();

    *(int *)adicionar_pessoas = totalpessoas + 1;
    return adicionar_pessoas;

}

void list(void *exit){
    int totalpessoas;
    totalpessoas = *(int *)exit;

    if(totalpessoas != 0){
        for(int i = 0; i < totalpessoas; i++){
            printf("Pessoa %d\n", i+1);
            printf("Nome: %s\n", (char *)(exit + NNAME + (NOME + IDADE + ALTURA) * i));
            printf("Idade: %d\n", *(int *)(exit + NNAME + NOME + (NOME + IDADE + ALTURA) * i));
            printf("Altura: %.2f\n\n", *(float *)(exit + NNAME + NOME + IDADE + (NOME + IDADE + ALTURA) * i));
        }
    }else{
        printf("Não existe ninguém na lista!\n\n");
    }
}