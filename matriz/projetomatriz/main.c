#include <stdio.h>
#include <funcoes.h>



struct matriz arquivo(struct matriz m){// ajeitar

    FILE *file;

    char diretorio[100];
    printf("informe o diretório do arquvo: ");
    scanf("%s",diretorio);
    printf("%s\n",diretorio);


    // /home/williammcn/testeqt/numeros.txt
    file = fopen(diretorio, "r");

    //ler valor das linha e colunas, respecticamente
    fscanf(file,"%d %d",&m.nlinhas, &m.ncolunas);
    printf("Linhas: %d\nColunas:%d\n\n",m.nlinhas,m.ncolunas);

    //limpa a matriz
    for (int i = 0; i < m.nlinhas; ++i) {
        for (int j = 0; j < m.ncolunas; ++j) {
            m.dados[i][j] = 0;
        }
    }
    //pega os valores do arquivo e joga na matriz
    for (int i = 0; i < m.nlinhas; ++i) {
        for (int j = 0; j < m.ncolunas; ++j) {
             fscanf(file," %f ",&m.dados[i][j]);
        }
    }
    return m;
}


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
            A = arquivo(A);
            break;
        case 14:
            arquivo(B);
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
