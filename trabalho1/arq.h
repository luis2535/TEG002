#ifndef ARQ_H_INCLUDED
#define ARQ_H_INCLUDED

int **criarMatriz(int linhas, int colunas);
int **criarGrafo(int n);
int *adicionaAresta(int linha, int coluna, int **matriz);
int *imprimeMatriz(int **matriz, int tamanho);
#endif