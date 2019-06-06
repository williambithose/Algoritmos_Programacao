#include <stdio.h>
#include <funcoes.h>

void arquivo(struct matriz m){// ajeitar

    FILE *file;

    int x,y, z;
    int matriz[50][50];


    file = fopen("/home/williammcn/testeqt/numeros.txt", "r");

    //ler valor das linha e colunas, respecticamente
    fscanf(file,"%d %d",&x, &y);
    printf("Linhas: %d\nColunas:%d\n\n",x,y);

    //limpa a matriz
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            matriz[i][j] = 0;
        }
    }
    //pega os valores do arquivo e joga na matriz
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
             fscanf(file," %d ",&matriz[i][j]);
        }
    }
}

int main(){

    struct matriz A,B,C;
    int aux, ison = 1;
    while (ison) {

        aux = menu();

        switch (aux) {
        case 1:
            setTamanho(A);
            break;
        case 2:
            setTamanho(B);
            break;
        case 3:
            setRandom(A);
            break;
        case 4:
            setRandom(B);
            break;
        case 5:
            setManual(A);
            break;
        case 6:
            setManual(B);
            break;

        case 10:
            printMatriz(A);
            break;
        case 11:
            printMatriz(B);
            break;
        case 12:
            printMatriz(C);
            break;

        case 16:
            ison = 0;
            break;
        default:
            printf("funcao indisponivel ou comando invalido\n");
            break;
        }

    }


    return 0;
}
