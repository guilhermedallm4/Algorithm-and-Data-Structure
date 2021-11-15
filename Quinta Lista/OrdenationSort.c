/*Exercício:
1- Implementar os algoritmos de ordenação Insertion Sort, Selection Sort, Quick Sort e Merge Sort.
2- O programa deve solicitar o tamanho do vetor de números (n) que será ordenado (OK)
3- O programa deve preencher um vetor de tamanho n com números aleatórios. Usar srand(time(NULL)); no inicio do programa. (OK)
4- Faça um código que verifica se o resultado dado por cada algoritmo de ordenação está correto.
5- Use a melhor lib (defina a melhor no item 7) para calcular quanto tempo cada algoritmo de ordenação levou para terminar:
 https://levelup.gitconnected.com/8-ways-to-measure-execution-time-in-c-c-48634458d0f9
6- No 1:1 vou perguntar sobre questões de desempenho relacionadas a esse exercício, então pense sobre desempenho, otimizações, avaliação de tempo, 
complexidade, hardware, etc
7- Faça teste de leaks de memória.
8- Faça um vídeo explicando todos os pontos. Por favor, não faça o vídeo mais longo do que o necessário e não esqueça das regras de envio de material.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int *vectorInsert, int end); 
void selectionSort(int *vectorSelection, int end);
void quickSort(int *vectorQuick, int left, int right);
void merge(int *vectorMerge, int inicio, int final);
void mergeSort(int *vectorMerge, int left, int right);
void liberarMemory(int *vectorInsert, int *vectorSelection, int *vectorQuick, int *vectorMerge);
void verifyVector(int *vector, int variavel);

int main(){
    struct timespec begin, end; 
    
    int nIndex; //Tamanho do vetor;
    int *vectorInsert, *vectorSelection, *vectorQuick, *vectorMerge, *pAux; //Vetores para cada função
    srand(time(NULL));
    printf("Escolha a quantidade de valores: ");
    scanf("%d", &nIndex);
    printf("\n");
    //Alocando espaço de memória dos vetores de acordo com o tamanho especificado
    vectorInsert = (int *)malloc(sizeof(int) * nIndex);
    vectorSelection = (int *)malloc(sizeof(int) * nIndex);
    vectorQuick = (int *)malloc(sizeof(int) * nIndex);
    vectorMerge = (int *)malloc(sizeof(int) * nIndex);
   
        if(!vectorInsert || !vectorSelection || !vectorQuick || !vectorMerge){
        printf("Erro de alocacao de memoria!");
        printf("\n");
        exit(1);
    }
    //Adicionando os valores randons ao vetor;
    for(int i = 0; i<nIndex;i++){
        vectorInsert[i] = rand() % 40;
        vectorSelection[i] = vectorInsert[i];
        vectorQuick[i] = vectorInsert[i];
        vectorMerge[i] = vectorInsert[i];
    }

    printf("\n");
    printf("\n");
    //CHAMADA DAS FUNÇÕES
    clock_gettime(CLOCK_REALTIME, &begin);
    insertionSort(vectorInsert, nIndex);
    clock_gettime(CLOCK_REALTIME, &end);
    verifyVector(vectorInsert, nIndex);

    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    double elapsed = seconds + nanoseconds*1e-9;

    printf("Vetor ordenado pelo InsertionSort:");
    printf("\nInsertionSort tempo de execucao: %.6f", elapsed);
    printf("\n");
    for(int i =0;i<nIndex;i++){
        printf(" %d ", vectorInsert[i]);
    }
    printf("\n");
    printf("\n");
    
    
    clock_gettime(CLOCK_REALTIME, &begin);
    selectionSort(vectorSelection, nIndex);
    clock_gettime(CLOCK_REALTIME, &end);
    verifyVector(vectorSelection, nIndex);

    seconds = end.tv_sec - begin.tv_sec;
    nanoseconds = end.tv_nsec - begin.tv_nsec;
    elapsed = seconds + nanoseconds*1e-9;

    printf("Vetor ordenado pelo SelectionSort:");
    printf("\nSelectioSort tempo de execução: %.6f", elapsed);
    printf("\n");
    for(int i =0;i<nIndex;i++){
        printf(" %d ", vectorSelection[i]);
    }
    printf("\n");
    printf("\n");
   
    clock_gettime(CLOCK_REALTIME, &begin);
    quickSort(vectorQuick, 0, nIndex - 1);
    clock_gettime(CLOCK_REALTIME, &end);
    verifyVector(vectorQuick, nIndex);

    seconds = end.tv_sec - begin.tv_sec;
    nanoseconds = end.tv_nsec - begin.tv_nsec;
    elapsed = seconds + nanoseconds*1e-9;

    printf("Vetor ordenado pelo QuickSort:");
    printf("\nQuickSort tempo de execucao: %.6f", elapsed);
    printf("\n");
    for(int i =0;i<nIndex;i++){
        printf(" %d ", vectorQuick[i]);
    }
    printf("\n");
    printf("\n");
    
    
    clock_gettime(CLOCK_REALTIME, &begin);
    merge(vectorMerge, 0, nIndex - 1);
    clock_gettime(CLOCK_REALTIME, &end);
    verifyVector(vectorMerge, nIndex);

    seconds = end.tv_sec - begin.tv_sec;
    nanoseconds = end.tv_nsec - begin.tv_nsec;
    elapsed = seconds + nanoseconds*1e-9;

    printf("Vetor ordenado pelo MergeSort:");
    printf("\n");
    for(int i =0;i<nIndex;i++){
        printf(" %d ", vectorMerge[i]);
    }
    printf("\nMegeSort tempo: %.6f", elapsed);
   printf("\n");
   
   liberarMemory(vectorInsert, vectorSelection, vectorQuick, vectorMerge);
   exit(1);
}

void insertionSort(int *vectorInsert, int end){
    int auxVar, counter;
    for(int i = 1;i<end;i++){
        auxVar = vectorInsert[i]; // Armazena o valor que está no indice 1 do vetor em auxVar
          for(counter = i-1; counter >= 0 && auxVar < vectorInsert[counter]; counter--) //Counter recebe o valor anterior a I e compara se auxVar é menor que o valor anterior
        {
            vectorInsert[counter+1] = vectorInsert[counter];
        }
         vectorInsert[counter+1] = auxVar;
         }
}

void selectionSort(int *vectorSelection, int end){
    int i = 0, varAux, w, p;
    int temp;
    do{

    for(w = i;w<end;w++){
        if(w == 0){
            varAux = vectorSelection[w];
        }
        if(varAux >= vectorSelection[w]){
            varAux = vectorSelection[w];
            p = w;
        }
    }
        temp = vectorSelection[i];
        vectorSelection[i] = varAux;
        vectorSelection[p] = temp;
        i++;
        varAux = vectorSelection[i];
    }while(i < end);
    
}

void quickSort(int *vectorQuick, int left, int right){
   
   int pPivo, auxVar, auxLeft, auxRight, middle;
   
   auxLeft = left;
   auxRight = right;
   middle = left;
   pPivo = vectorQuick[middle];
   
   do{
      while (vectorQuick[auxLeft] < pPivo){
          auxLeft++;
      }
      while (vectorQuick[auxRight] > pPivo){
         auxRight--;
      }
      if(auxLeft <= auxRight){
         auxVar = vectorQuick[auxLeft];
         vectorQuick[auxLeft] = vectorQuick[auxRight];
         vectorQuick[auxRight] = auxVar;
         auxLeft++;
         auxRight--;
      }
   }while(auxRight > auxLeft);
   
   if(left < auxRight) quickSort(vectorQuick, left, auxRight);
   if(auxLeft < right) quickSort(vectorQuick, auxLeft, right);   

}

void merge(int *vectorMerge, int left, int right){
    int meio = right / 2;
    int inicio = left;
    mergeSort(vectorMerge, inicio, meio);
    mergeSort(vectorMerge, meio, right + 1);
    mergeSort(vectorMerge, left, right + 1);
    

}

void mergeSort(int *vectorMerge, int inicio, int final){
    int counter = inicio;
    int temp, varAux, i, indice, w;
  do{
    for(w = counter;w<final;w++){
        if(w == inicio){
            varAux = vectorMerge[counter];
        }
        
            if(varAux >= vectorMerge[w]){
            varAux = vectorMerge[w];
            indice = w;
    }
}
        temp = vectorMerge[counter];
        vectorMerge[counter] = varAux;
        vectorMerge[indice] = temp;
        counter++;
        varAux = vectorMerge[counter];
    }while(counter < final);

}

void liberarMemory(int *vectorInsert, int *vectorSelection, int *vectorQuick, int *vectorMerge){
   free(vectorInsert);
   free(vectorSelection);
   free(vectorQuick);
   free(vectorMerge);
   printf("\n");
   printf("Saindo do programa!");
   
}

void verifyVector(int *vector, int variavel){
    int auxVar, i;
    int first = 0;
    int verify = 0;
    for(i = 1;i<variavel;i++){
        auxVar = vector[i];
        if(vector[first] <= auxVar){
            verify = 0;
        }
        else{
            verify = 1;
            break;
        }
    }
    if(verify == 0){
        printf("Esta ordenado!");
        printf("\n");
        }
    else{
        printf("Nao esta ordenado!");
        printf("\n");
    }
}