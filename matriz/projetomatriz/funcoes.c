#include <funcoes.h>
#include <stdlib.h>
#include <time.h>

int menu(void){

    int aux=0;

    //Imprimir o layout do menu
    printf("PROGRAMA DE MANIPULACAO DE MATRIZES\n");
    printf("(1) Definir o tamanho da matriz A\n");
    printf("(2) Definir o tamanho da matriz B\n");
    printf("(3) Preencher a matriz A com valores aleatórios\n");
    printf("(4) Preencher a matriz B com valores aleatórios\n");
    printf("(5) Atribuir valores manualmente para os elementos da matriz A\n");
    printf("(6) Atribuir valores manualmente para os elementos da matriz B\n");
    printf("(7) Calcular A+B\n");
    printf("(8) Calcular A-B\n");
    printf("(9) Calcular A*B\n");
    printf("(10) Imprimir matriz A\n");
    printf("(11) Imprimir matriz B\n");
    printf("(12) Imprimir matriz C\n");
    printf("(13) Ler a matriz A de um arquivo\n");
    printf("(14) Ler a matriz B de um arquivo\n");
    printf("(15) Escrever a matriz C em um arquivo\n");
    printf("(16) Sair\n");
    printf("\n");

    //Ler a funcao desejada
    printf("Digite a operacao desejada: ");
    scanf("%d",&aux);

    return aux;

}

//Adiciona tamanho de linhas e colunas no struct
struct matriz setTamanho(struct  matriz m){

    printf("informe o numero de linhas da matriz:\n");
    scanf("%d",&m.nlinhas);
    printf("informe o numero de colunas da matriz:\n");
    scanf("%d",&m.ncolunas);

    next();
    return m;
}


struct matriz setRandom(struct  matriz m){
    srand(time(NULL));
    int min, max;
    if(m.nlinhas !=0 && m.ncolunas !=0){

        printf("Informe o valor minimo (inteiro)");
        scanf("%d",&min);
        printf("Informe o valor máximo (inteiro)");
        scanf("%d",&max);

        for (int i = 0; i < m.nlinhas; ++i){
            for (int j = 0; j < m.ncolunas; ++j){
                m.dados[i][j] = /*min +*/ rand() /*% max*/;
            }
        }

    }else {
        printf("Matriz não definida\n");
        next();
        return m;
    }
    next();
    return m;
}


struct matriz setManual(struct  matriz m){

    if(m.nlinhas !=0 && m.ncolunas !=0){

        printf("Informe os valores nas posicoes:");
        int aux;
        for (int i = 0; i < m.nlinhas; ++i){
            for (int j = 0; j < m.ncolunas; ++j){
                printf("matriz na linha %d e coluna %d",i,j);
                scanf("%d",&aux);
                m.dados[i][j] = aux;
            }
        }

    }else {
        printf("Matriz não definida\n");
        next();
        return m ;
    }
    next();
    return m;
}


void imprimir(struct matriz m){
    if(m.nlinhas !=0 && m.ncolunas !=0){

    for (int i = 0; i < m.nlinhas; ++i){
        for (int j = 0; j < m.ncolunas; ++j){
            printf(" %4.2f",m.dados[i][j]);
        }
        printf("\n");
    }

    }else {
        printf("Matriz não definida\n");

    }
    next();
    return;
}

//PROTOTIPO DAS FUNÇÕES
void next(){
    printf("\n\n precione alguma coisa para continuar: ");
        //ler teclado

            char caractere;
            caractere = getchar();

        printf("\n\n\n\n\n\n\n\n\n");
}
