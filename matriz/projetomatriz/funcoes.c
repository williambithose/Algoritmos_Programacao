/**
 * @file funcoes.c
 * @author William Nascimento e Helio Jales
 * @date 26 jun 2019
 * @brief Guarda as funções usadas no main.c
 *
 * @see https://github.com/williambithose/Algoritmos_Programacao/tree/master/matriz/projetomatriz
 */


#include <funcoes.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/**
************************* FUNCOES VISUAIS ***********************************************
*/

int menu(void){

    int aux;        /**< Struct que recebera a matriz resultado da operacao */

    /**
     * Imprimir o layout do menu
     */
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

    /**
     * Ler a funcao desejada
     */
    printf("Digite a operacao desejada: ");
    scanf("%d",&aux);

    return aux;
}

void printMatriz(struct matriz m){

    /**
     * Caso a Matriz já exista
     * Imprime seus valores na tela
     *
     * Caso a Matriz não exista
     * Sai da função
     */
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

    return;
}

/**
************************* FUNCOES DE ATRIBUICAO DE VALORES ******************************
*/

struct matriz setTamanho(struct  matriz m){

    /**
     * Faz leitura dos tamanhos desejados
    */
    printf("informe o numero de linhas da matriz:\n");
    scanf("%d",&m.nlinhas);
    printf("informe o numero de colunas da matriz:\n");
    scanf("%d",&m.ncolunas);

    /**
    * Confere se o tamanho da matriz é superior ao tamanho maximo
    * Se Sim: Zera os valores e exibe uma mensagem
    * Se Nao: Continua normalmente
    */
    if(m.nlinhas >100 || m.ncolunas > 100){
        printf("O Tamanho de linhas da matriz está além do tamanho máximo permitido (100)\n");
        printf("tente novamente com tamanhos menores\n");
        m.nlinhas = 0;
        m.ncolunas= 0;
    }

    return m;
}

struct matriz setRandom(struct  matriz m){

    /**
     * Adiciona a um srando um valor baseado na hora
     * para que os valores aleatórios sejam mais variados
     */
    srand(time(NULL));

    int min, max;       /**< Valores minimo e maximos do intervalo de valores aleatorios */

    /**
     * Caso a Matriz já exista
     * Recebe os limites do usuário e add os valores aleatorios na matriz
     *
     * Caso a Matriz não exista
     * Sai da função
     */
    if(m.nlinhas !=0 && m.ncolunas !=0){

        printf("Informe o valor minimo (valor inteiro): ");
        scanf("%d",&min);
        printf("Informe o valor máximo (valor inteiro): ");
        scanf("%d",&max);

        for (int i = 0; i < m.nlinhas; ++i){
            for (int j = 0; j < m.ncolunas; ++j){
                m.dados[i][j] = min + (rand() % (min-max+1));
            }
        }

    }else {
        printf("Matriz não definida\n");
    }

    return m;
}

struct matriz setManual(struct  matriz m){

    /**
     * Caso a Matriz já exista
     * Recebe os valores do usuario e insere na matriz
     *
     * Caso a Matriz não exista
     * Sai da função
     */
    if(m.nlinhas !=0 && m.ncolunas !=0){

        printf("Informe os valores nas posicoes:\n");
        int aux;
        for (int i = 0; i < m.nlinhas; ++i){
            for (int j = 0; j < m.ncolunas; ++j){
                printf("matriz na linha %d e coluna %d : ",i+1,j+1);
                scanf("%d",&aux);
                m.dados[i][j] = aux;
            }
        }

    }else {
        printf("Matriz não definida\n");

        return m ;
    }

    return m;
}

/**
************************* FUNCOES DE OPERACOES ******************************************
*/

struct matriz soma(struct matriz A, struct matriz B){

    struct matriz C; /**< Struct que recebera a matriz resultado da operacao */

    /**
     * Caso as Matrizes tenham tamanhos iguais
     * Realiza a operacao e o resultado e gravado na matriz C
     *
     * Caso as Matrizes não tenham tamanhos iguas
     * Sai da função
     */
    if((A.nlinhas == B.nlinhas) && (A.ncolunas == B.ncolunas)){

        C.nlinhas = A.nlinhas;
        C.ncolunas = A.ncolunas;

        for (int i = 0; i < A.nlinhas; ++i){
            for (int j = 0; j < A.ncolunas; ++j){
                C.dados[i][j] = A.dados[i][j] + B.dados[i][j];
            }
        }

        return C;
    }else
        printf("TAMANHOS DAS MATRIZES INCOMPATIVEIS !");
}

struct matriz subtracao(struct matriz A, struct matriz B){

    struct matriz C; /**< Struct que recebera a matriz resultado da operacao */

    /**
     * Caso as Matrizes tenham tamanhos iguais
     * Realiza a operacao e o resultado e gravado na matriz C
     *
     * Caso as Matrizes não tenham tamanhos iguas
     * Sai da função
     */
    if((A.nlinhas == B.nlinhas) && (A.ncolunas == B.ncolunas)){

        C.nlinhas = A.nlinhas;
        C.ncolunas = A.ncolunas;

        for (int i = 0; i < A.nlinhas; ++i){
            for (int j = 0; j < A.ncolunas; ++j){
                C.dados[i][j] = A.dados[i][j] + B.dados[i][j];
            }
        }

        return C;
    }else
        printf("TAMANHOS DAS MATRIZES INCOMPATIVEIS !");
}

struct matriz multiplicacao(struct matriz A, struct matriz B){

    struct matriz C;
    float mult=0;

    if(A.ncolunas==B.nlinhas){

        C.nlinhas = A.nlinhas;
        C.ncolunas = B.ncolunas;

        for(int i=0; i<A.nlinhas; i++){
                    for(int j=0; j<B.ncolunas; j++){

                        C.dados[i][j]=0;

                        for(int X=0; X<B.nlinhas; X++){
                           mult += A.dados[i][X] * B.dados[X][j];
                        }

                        C.dados[i][j] = mult;
                        mult=0;
                    }
                }
        return C;
    }else
        printf("TAMANHOS DAS MATRIZES INCOMPATIVEIS !");
}
/**
************************* FUNCOES DE MANIPULACAO DE ARQUIVO *****************************
*/

struct matriz import_matriz(struct matriz m){

    FILE *file;             /**< Arquivo a ser lido */
    char diretorio[100];    /**< Caminho do diretorio */
    int isValido =1;        /**< Guarda se o diretorio e valido ou nao */

    /**
     * Le o diretorio do usuario ate que seja um diretorio valido
     */
    do {
        printf("Informe o diretório do arquvo: ");
        scanf("%s",diretorio);
        //printf("%s\n",diretorio);

        // /home/williammcn/testeqt/numeros.txt
        /** abre o arquivo para leitura */
        file = fopen(diretorio, "r");

        /**
         * Detecta se o diretorio existe ou nao
         */
        if(file == 0){//diretório não existe
            printf("DIRETORIO INVALIDO\n");
        }else {
            isValido  = 0;
        }
    } while (isValido );

    /**
     * ler valor das linha e colunas, respecticamente
     */
    fscanf(file,"%d %d",&m.nlinhas, &m.ncolunas);
    printf("Linhas: %d\nColunas:%d\n\n",m.nlinhas,m.ncolunas);

    /**
    * Confere se o tamanho da matriz é superior ao tamanho maximo
    * Se Sim: Zera os valores e exibe uma mensagem
    * Se Nao: Continua normalmente
    */
    if(m.nlinhas >100 || m.ncolunas > 100){
        printf("O Tamanho de linhas da matriz está além do tamanho máximo permitido (100)\n");
        printf("tente novamente com tamanhos menores\n");
        m.nlinhas = 0;
        m.ncolunas= 0;

        return m;
    }

    /**
     * limpa a matriz
     */
    for (int i = 0; i < m.nlinhas; ++i) {
        for (int j = 0; j < m.ncolunas; ++j) {
            m.dados[i][j] = 0;
        }
    }

    /**
     * pega os valores do arquivo e joga na matriz
     */
    for (int i = 0; i < m.nlinhas; ++i) {
        for (int j = 0; j < m.ncolunas; ++j) {
             fscanf(file," %f ",&m.dados[i][j]);
        }
    }
    fclose(file);
    return m;
}

void export_matriz(struct matriz m){

    FILE *file;             /**< Arquivo o qual sera salvo */
    char diretorio[100];    /**< Caminho do diretorio */
    int check=1;            /**< Guarda se o diretorio e valido ou nao */

    /**
     * Le o diretorio do usuario ate que seja um diretorio valido
     */
    do {
        printf("informe o diretório do arquvo: ");
        scanf("%s",diretorio);
        //printf("%s\n",diretorio);

        // /home/williammcn/testeqt/numeros.txt
        /** abre o arquivo para escrita */
        file = fopen(diretorio, "w");

        /**
         * Detecta se o diretorio existe ou nao
         */
        if(file == 0){//diretório não existe
            printf("DIRETORIO INVALIDO\n");
        }else {
            check = 0;
        }
    } while (check);

    /**
     * escreve no arquivo os valores das linha e colunas
     */
    fprintf(file,"%d %d\n", m.nlinhas, m.ncolunas);

    /**
     * escreve no arquivo os dados da matriz
     */
    for(int i = 0; i < m.nlinhas; ++i) {
        for (int j = 0; j < m.ncolunas; ++j) {
            fprintf(file,"%2f ", m.dados[i][j]);
        }
        fprintf(file,"\n");
    }

    /** Fechar o arquivo */
    fclose(file);
    return ;
}
