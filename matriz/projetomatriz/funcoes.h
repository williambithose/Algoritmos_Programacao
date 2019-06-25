/**
 * @file funcoes.h
 * @author William Nascimento e Helio Jales
 * @date 26 jun 2019
 * @brief Header do projeto de Manipulação de Matrizes
 *
 * @see https://github.com/williambithose/Algoritmos_Programacao/tree/master/matriz/projetomatriz
 */

#ifndef FUNCOES_H
#define FUNCOES_H

/**
 * STRUCT MATRIZ
 * struct que representa as matrizes manipuladas no programa
 */
struct matriz {
    int nlinhas;            /**< Numero de linhas da matriz */
    int ncolunas;           /**< Numero de colunas da matriz */
    float dados[100][100];  /**< Dados da matriz */
};

/**
************************* FUNCOES VISUAIS ***********************************************
*/

/**
 * Funcao menu
 * @brief Imprime o menu e retorna o valor da função a ser acionada
 *
 * Retorno:
 * aux: Valor da funcao desejada pelo usuário
 */
int menu(void);

/**
 * Funcao printMatriz
 * @brief Imprime na tela a matriz selecionada como entrada
 *
 * Entrada:
 * m: Struct a ser impressa
 */
void printMatriz(struct matriz m);

/**
************************* FUNCOES DE ATRIBUICAO DE VALORES ******************************
*/

/**
 * Funcao setTamanho
 * @brief Adiciona tamanho de linhas e colunas no struct
 *
 * Entrada:
 * m: Struct a ser definido o tamanho
 *
 * Retorno:
 * m após ser definido seu tamanho
 */
struct matriz setTamanho(struct  matriz m);

/**
 * Funcao setRandom
 * @brief Adiciona os valores aleatorio na matriz
 *
 * Entrada:
 * m: Struct a serem atribuidos os valores
 *
 * Retorno:
 * m após ser atribuidos os valores
 */
struct matriz setRandom(struct  matriz m);

/**
 * Funcao setManual
 * @brief Adiciona os valores manualmente na matriz
 *
 * Entrada:
 * m: Struct a serem atribuidos os valores
 *
 * Retorno:
 * m após ser atribuidos os valores
 */
struct matriz setManual(struct  matriz m);

/**
************************* FUNCOES DE OPERACOES ******************************************
*/

/**
 * Funcao soma
 * @brief Calcula soma de duas matrizes
 *
 * Entrada:
 * A, B: Structs os quais será feito a soma
 *
 * Retorno:
 * C: Struct resultado da operacao
 */
struct matriz soma(struct matriz A, struct matriz B);

/**
 * Funcao subtracao
 * @brief Calcula subtracao de duas matrizes
 *
 * Entrada:
 * A, B: Structs os quais será feito a subtracao
 *
 * Retorno:
 * C: Struct resultado da operacao
 */
struct matriz subtracao(struct matriz A, struct matriz B);

/**
 * Funcao multipicacao
 * @brief Calcula o produto de duas matrizes
 *
 * Entrada:
 * A, B: Structs os quais será feito o produto
 *
 * Retorno:
 * C: Struct resultado da operacao
 */
struct matriz multiplicacao(struct matriz A, struct matriz B);

/**
************************* FUNCOES DE MANIPULACAO DE ARQUIVO *****************************
*/

/**
 * Funcao import_matriz
 * @brief Le os valores de um aquivo .txt do diretorio indicado pelo usuario
 * e atribui a um struct matriz
 *
 * O arquivo a ser lido deve ser no formato .txt
 * E deve conter:
 *  Na primeira linha o numero de linhas e colunas respectivamente
 *  Em seguida os dados devidamente organizados
 *  EX:
 *      3 3
 *      1 2 3
 *      4 5 6
 *      7 8 9
 *
 * Entrada:
 * m: Struct da matriz a ser atribuido os valores
 *
 * Retorno:
 * C: Struct apos ser atribuido os valores
 */
struct matriz import_matriz(struct matriz m);

/**
 * Funcao import_matriz
 * @brief salva os dados de uma matriz em um arquivo .txt no diretorio indicado pelo usuario
 *
 * DETALHAR AS RESTRICOES NO ARQUIVO
 *
 * Entrada:
 * m: Struct da matriz a ser atribuido os valores
 *
 * Retorno:
 * C: Struct apos ser atribuido os valores
 */
void export_matriz(struct matriz m);

#endif // FUNCOES_H
