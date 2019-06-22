/**
 * @file main.c
 * @author William Nascimento e Helio Jales
 * @date 26 jun 2019
 * @brief ALgoritmo de Manipulação de Matrizes
 *
 * @see https://github.com/williambithose/Algoritmos_Programacao/tree/master/matriz/projetomatriz
 */

#include <stdio.h>
#include <funcoes.h>

int main(){

    struct matriz A,B,C;    /**< Structs das matrizes que serao manipuladas no programa */
    int aux,                /**< Varaivel auxiliar: indic a funcão desejada             */
        isOn = 1;           /**< Indica se o programa deve continuar rodando ou nao     */

    while (isOn) {

        printf("\n\n");
        aux = menu();

        switch (aux) {
        case 1:
            A = setTamanho(A);
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
        case 7:
            C = soma(A,B);
            break;
        case 8:
            C = subtracao(A,B);
            break;
        case 9:
            //C = multiplicacao(A,B);
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
            isOn = 0;
            break;
        default:
            printf("Funcao indisponivel ou comando invalido :(\n");
            break;
        }

    }

    return 0;
}
