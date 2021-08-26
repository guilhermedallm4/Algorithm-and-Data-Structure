#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inserir(char *aloc);
char *retirar(char *remover);


int main(){
    char *c;
    c = (char *)malloc(sizeof(char));
    if(c == NULL){
        printf("Erro na alocação da memória!!");
        exit(1);
    }
    c[0] = '\0';
    int opcao, i, w;
    do{
        printf("1- Adicionar: \n");
        printf("2- Remover: \n");
        printf("3- Listar\n");
        printf("4- Sair: \n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            c = inserir(c);
            printf("Adicionado com sucesso!\n");
            printf("%s\n", c);
            break;
        case 2:
            c = retirar(c);
            printf("%s\n", c);
            break;
        case 3:
            printf("%s\n", c);
           break;
        case 4: 
            free(c);
            break;
        }
    }while(opcao != 4);
}

char *inserir(char *aloc){
        char nome[10];
        printf("Digite o nome: ");
        scanf("%s", nome);
        int i, w;
        w = strlen(nome);
        i = strlen(aloc);
        aloc = (char *)realloc(aloc, i+w+2);
        if(aloc == NULL){
        printf("Erro de memoria!!");
        exit(1);
    }
        strcat(nome, " ");
        strcat(aloc, nome);
        return aloc;
}

char *retirar(char *remover){
    char *aux;
    char nome[15];
    int i=0, w;
    printf("Digite o nome para se remvoer da string:\n");
    scanf("%s", nome);
    strcat(nome, " ");
    aux = (char *)realloc(aux, strlen(nome));
    aux = strstr(remover, nome);
    if(!aux){
        printf("Nome não encontrado!");
    }
    else{
    w = strlen(nome);
        while(i < w){
            strcpy(aux, aux+1);
            i++;
        }

    }
   return remover;
}