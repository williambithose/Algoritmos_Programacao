#ifndef FUNCOES_H
#define FUNCOES_H

struct matriz {
    int nlinhas;
    int ncolunas;
    float dados[50][50];
};

int menu(void);
void setTamanho(struct matriz m);
void printMatriz(struct matriz m);
void setManual(struct  matriz m);
void printMatriz(struct matriz m);



#endif // FUNCOES_H
