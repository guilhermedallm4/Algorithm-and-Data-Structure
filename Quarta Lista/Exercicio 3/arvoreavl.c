#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int key;
} Registry;

typedef struct Nodo {
    Registry reg;
    struct Nodo *pLeft;
    struct Nodo *pRight;
} Nodo;

int insert (Nodo **ppSource, Registry reg);
void listTree (Nodo *pSource);
void cleanTree (Nodo *pSource);

int balancing(Nodo **ppSource);
int balancingLeft (Nodo **ppSource);
int balancingRight (Nodo **ppSource);
void RSE (Nodo **ppSource);
void RSD (Nodo **ppSource);
int FB (Nodo *pSource);
int height (Nodo *pSource);
int verificationAVL (Nodo *pSource);

int main () {
    int i, nNodos, random;
    Nodo *pSource = NULL;
    Registry reg;

    printf("Digite o numero de nodos: ");
    scanf("%d", &nNodos);
    getchar();
    
    srand(time(0));

    for (i=0; i < nNodos; i++){
        random = rand() % 40;
        reg.key = random;
        insert(&pSource, reg);
    }

    printf("\n\n--PRIMEIRO CENARIO--\n\n");

    printf("\n");
    listTree(pSource);
    printf("\n");

    if(verificationAVL(pSource)) {
        printf("\nA arvore eh AVL!\n");
    } else {
        printf("\nA arvore nao eh AVL!\n");
    }

    cleanTree(pSource);

    secondScenery();

    return 0;
}

void cleanTree (Nodo *pSource) {
    if (pSource == NULL) {
        return;
    }

    cleanTree(pSource -> pLeft);
    cleanTree(pSource -> pRight);

    free(pSource);
}

void listTree (Nodo *pSource) {
    if (pSource != NULL) {
        printf("%d(", pSource -> reg.key);
        listTree(pSource -> pLeft);
        listTree(pSource -> pRight);
        printf(")");
    }
}

void secondScenery(){
    Nodo *pSource = NULL;
    Registry reg;

    printf("\n\n--SEGUNDO CENARIO--\n\n");

    printf("Primeiro caso: Inserir 15");
    reg.key = 20;
    insert(&pSource, reg);
    reg.key = 4;
    insert(&pSource, reg);
    printf("\n- Antes de inserir o 15\n");
    listTree(pSource);
    printf("\n");
    reg.key = 15;
    insert(&pSource, reg);
    printf("- Depois de inserir o 15\n");
    listTree(pSource);
    printf("\n\n");
    cleanTree(pSource);
    pSource = NULL;

    printf("Segundo caso: Inserir 15");
    reg.key = 20;
    insert(&pSource, reg);
    reg.key = 4;
    insert(&pSource, reg);
    reg.key = 26;
    insert(&pSource, reg);
    reg.key = 3;
    insert(&pSource, reg);
    reg.key = 9;
    insert(&pSource, reg);
    printf("\n- Antes de inserir o 15\n");
    listTree(pSource);
    printf("\n");
    reg.key = 15;
    insert(&pSource, reg);
    printf("- Depois de inserir o 15\n");
    listTree(pSource);
    printf("\n\n");
    cleanTree(pSource);
    pSource = NULL;

    printf("Terceiro caso: Inserir 15");
    reg.key = 20;
    insert(&pSource, reg);
    reg.key = 4;
    insert(&pSource, reg);
    reg.key = 26;
    insert(&pSource, reg);
    reg.key = 3;
    insert(&pSource, reg);
    reg.key = 9;
    insert(&pSource, reg);
    reg.key = 2;
    insert(&pSource, reg);
    reg.key = 7;
    insert(&pSource, reg);
    reg.key = 11;
    insert(&pSource, reg);
    reg.key = 21;
    insert(&pSource, reg);
    reg.key = 30;
    insert(&pSource, reg);
    printf("\n- Antes de inserir o 15\n");
    listTree(pSource);
    printf("\n");
    reg.key = 15;
    insert(&pSource, reg);
    printf("- Depois de inserir o 15\n");
    listTree(pSource);
    printf("\n\n");
    cleanTree(pSource);
    pSource = NULL;

    printf("Quarto caso: Inserir 8");
    reg.key = 20;
    insert(&pSource, reg);
    reg.key = 4;
    insert(&pSource, reg);
    printf("\n- Antes de inserir o 8\n");
    listTree(pSource);
    printf("\n");
    reg.key = 8;
    insert(&pSource, reg);
    printf("- Depois de inserir o 8\n");
    listTree(pSource);
    printf("\n\n");
    cleanTree(pSource);
    pSource = NULL;
    
    printf("Quinto caso: Inserir 8");
    reg.key = 20;
    insert(&pSource, reg);
    reg.key = 4;
    insert(&pSource, reg);
    reg.key = 26;
    insert(&pSource, reg);
    reg.key = 3;
    insert(&pSource, reg);
    reg.key = 9;
    insert(&pSource, reg);
    printf("\n- Antes de inserir o 8\n");
    listTree(pSource);
    printf("\n");
    reg.key = 8;
    insert(&pSource, reg);
    printf("- Depois de inserir o 8\n");
    listTree(pSource);
    printf("\n\n");
    cleanTree(pSource);
    pSource = NULL;

    printf("Sexto caso: Inserir 8");
    reg.key = 20;
    insert(&pSource, reg);
    reg.key = 4;
    insert(&pSource, reg);
    reg.key = 26;
    insert(&pSource, reg);
    reg.key = 3;
    insert(&pSource, reg);
    reg.key = 9;
    insert(&pSource, reg);
    reg.key = 21;
    insert(&pSource, reg);
    reg.key = 30;
    insert(&pSource, reg);
    reg.key = 2;
    insert(&pSource, reg);
    reg.key = 7;
    insert(&pSource, reg);
    reg.key = 11;
    insert(&pSource, reg);
    printf("\n- Antes de inserir o 8\n");
    listTree(pSource);
    printf("\n");
    reg.key = 8;
    insert(&pSource, reg);
    printf("- Depois de inserir o 8\n");
    listTree(pSource);
    printf("\n\n");
    cleanTree(pSource);
    pSource = NULL;

}

int insert (Nodo **ppSource, Registry nReg) {
    if (*ppSource == NULL) {
        *ppSource = (Nodo*)malloc(sizeof(Nodo));
        (*ppSource) -> reg = nReg;
        (*ppSource) -> pLeft = NULL;
        (*ppSource) -> pRight = NULL;

        return 1;
    } else if ( nReg.key < (*ppSource) -> reg.key ) {
        if (insert( &(*ppSource) -> pLeft, nReg )){
            if (balancing(ppSource)) {
                return 0;
            } else {
                return 1;
            }
        }
    } else if (nReg.key > (*ppSource) -> reg.key) {
        if (insert (&(*ppSource) -> pRight, nReg)) {
            if (balancing(ppSource)) {
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        return 0;
    }
    return 0;
}

int FB(Nodo *pSource) { 
    if (pSource == NULL) {
        return 0;
    }

    return height(pSource -> pLeft) - height(pSource -> pRight);
}

int height(Nodo *pSource) {
    int iLeft, iRight;

    if (pSource == NULL) {
        return 0;
    }

    iLeft = height(pSource -> pLeft);
    iRight = height(pSource -> pRight);

    if (iLeft > iRight){
        return iLeft + 1;
    } else {
        return iRight + 1;
    }
}

int balancing(Nodo **ppSource) { 
    int fb = FB(*ppSource);

    if (fb > 1) {
        return balancingLeft(ppSource);
    } else if (fb < -1){
        return balancingRight(ppSource);
    } else {
        return 0;
    }
}

int balancingLeft(Nodo **ppSource) {
    int FBL = FB( (*ppSource) -> pLeft );

    if (FBL >= 0) {
        RSD(ppSource);
        return 1;
    } else if (FBL < 0) { 
        RSE ( &((*ppSource) -> pLeft) );
        RSD (ppSource);
        return 1;
    }
    return 0;
}

int balancingRight (Nodo **ppSource) {
    int FBR = FB( (*ppSource) -> pRight );
    
    if (FBR <= 0) {
        RSE (ppSource);
        return 1;
    } else if (FBR > 0) {
        RSD ( &((*ppSource) -> pRight) );
        RSE (ppSource);
        return 1;
    }
    return 0;
}

void RSE (Nodo** ppSource) {
    Nodo *pAux;

    pAux = (*ppSource) -> pRight;
    (*ppSource)->pRight = pAux -> pLeft;
    pAux -> pLeft = (*ppSource);
    (*ppSource) = pAux;
}

void RSD (Nodo **ppSource) {
    Nodo *pAux;

    pAux = (*ppSource) -> pLeft;
    (*ppSource) -> pLeft = pAux -> pRight;
    pAux -> pRight = (*ppSource);
    (*ppSource) = pAux;
}

int verificationAVL (Nodo *pSource) {
    int fb;
    fb = FB (pSource);

    if (pSource == NULL) {
        return 1;
    }

    if (!verificationAVL(pSource -> pLeft)) {
        return 0;
    }

    if (!verificationAVL(pSource -> pRight)) {
        return 0;
    }

    if ((fb > 1) || (fb < -1)) {
        return 0;
    } else {
        return 1;
    }
}