#include <stdio.h>
#include <funcoes.h>


int main(){

    struct matriz A,B,C;
    int aux, ison = 1;

    while (ison) {

        printf("\n\n");
        aux = menu();

        switch (aux) {
        case 1:
            A = setTamanho(A);
            printf("%d %d",A.nlinhas, A.ncolunas);
            break;
        case 2:
            B = setTamanho(B);
            break;
        case 3:
            A = setRandom(A);
            break;
        case 4:
            B = setRandom(B);
            break;
        case 5:
            A = setManual(A);
            break;
        case 6:
            B = setManual(B);
            break;

        case 10:
            imprimir(A);
            break;
        case 11:
            imprimir(B);
            break;
        case 12:
            imprimir(C);
            break;
        case 13:
            A = import_matriz(A);
            break;
        case 14:
            B = import_matriz(B);
            break;
        case 15:
            export_matriz(A);
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
