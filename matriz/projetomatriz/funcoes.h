#ifndef FUNCOES_H
#define FUNCOES_H

struct matriz {
    int nlinhas;
    int ncolunas;
    float dados[50][50];
};

int menu(void);
struct matriz setTamanho(struct  matriz m);
struct matriz printMatriz(struct matriz m);
struct matriz setManual(struct  matriz m);
struct matriz setRandom(struct  matriz m);
void imprimir(struct matriz m);


#endif // FUNCOES_H
