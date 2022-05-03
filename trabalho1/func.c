#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int **criarMatriz(int linhas, int colunas)
{
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            matriz[i][j] = 0;
        }
    }
    return matriz;
}

int **adicionaAresta(int linha, int coluna, int **matriz)
{
    matriz[linha][coluna] += 1;
    matriz[coluna][linha] += 1;
    return matriz;
}
void imprimeMatriz(int **matriz, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}
int numeroArestas(int **matriz, int tamanho)
{
    int soma = 0;
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            if (i <= j)
            {
                soma += matriz[i][j];
            }
        }
    }
    return soma;
}
void lacos(int **matriz, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (matriz[i][i] >= 1)
        {
            printf("\nExiste um laco no NÓ: %d\n", i);
        }
    }
}
void arestasDuplas(int **matriz, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = i; j < tamanho; j++)
        {
            if (matriz[i][j] > 1)
            {
                printf("\nExiste uma aresta multipla nos vertices V[%d] e V[%d]\n", i + 1, j + 1);
                printf("\nO número de arestas desse par é: %d\n", matriz[i][j]);
            }
        }
    }
}
int grauV(int **matriz, int vertice, int tamanho)
{
    int soma = 0;
    if ((vertice - 1 > tamanho) || (vertice - 1 < 0))
    {
    }
    else
    {
        for (int i = 0; i < tamanho; i++)
        {
            soma += matriz[vertice - 1][i];
        }
        return soma;
    }
    soma = -1;
    return soma;
}
void somagrau(int **matriz, int tamanho)
{
    int soma = 0;
    for (int i = 1; i < tamanho + 1; i++)
    {
        soma += grauV(matriz, i, tamanho);
    }
    printf("\nO somatório dos graus é: %d\n", soma);
}
void isolados(int **matriz, int tamanho)
{
    int soma;
    int cont = 0;
    for (int i = 0; i < tamanho; i++)
    {
        soma = 0;
        for (int j = 0; j < tamanho; j++)
        {
            soma += matriz[i][j];
        }
        if (soma == 0)
        {
            cont++;
            printf("\nO vertice V[%d] esta isolado\n", i + 1);
        }
    }
    if (cont == 0)
    {
        printf("\nNao ha vertices isolados\n");
    }
}
void verticesImpar(int **matriz, int tamanho)
{
    int cont = 0;
    int grau = 0;
    for (int i = 0; i < tamanho; i++)
    {
        grau = grauV(matriz, i + 1, tamanho);
        if (grau % 2 != 0)
        {
            cont++;
        }
    }
    if (cont % 2 == 0)
    {
        printf("\nO numero de vertices com grau impar(%d) eh par\n", cont);
    }
    else
    {
        printf("\nO numero de vertices com grau impar(%d) eh impar\n", cont);
    }
}
void teoremaArestas(int **matriz, int tamanho)
{
    int num = numeroArestas(matriz, tamanho);
    int teorema = 0;
    teorema = tamanho * (tamanho - 1) / 2;
    if (num < teorema)
    {
        printf("\nO número de arestas é menor que o numero de combinacoes de |V| tomadas 2 a 2\n");
    }
    else if (num == teorema)
    {
        printf("\nO número de arestas é igual ao numero de combinacoes de |V| tomadas 2 a 2\n");
    }
    else
    {
        printf("\nO número de arestas é maior que o numero de combinacoes de |V| tomadas 2 a 2\n");
    }
}
void grafoSimples(int **matriz, int tamanho)
{
    int cont = 0;
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            if (matriz[i][j] > 1) // apenas um teste é realizado, pois se uma aresta é um laço, automaticamente esse aresta é dupla
            {
                cont++;
            }
        }
    }
    if (cont > 0)
    {
        printf("\nO grafo não é um grafo simples.\n");
    }
    else
    {
        printf("\nO grafo é um grafo simples.\n");
    }
}
void grafoCompleto(int **matriz, int tamanho)
{
    int cont = 0;
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            if (i == j)
            {
                if (matriz[i][j] > 0)
                {
                    cont++;
                    break;
                }
            }
            else
            {
                if (matriz[i][j] != 1)
                {
                    cont++;
                    break;
                }
            }
        }
    }
    if (cont != 0)
    {
        printf("\nO grafo não é completo.\n");
    }
    else
    {
        printf("\nO grafo é completo.\n");
    }
}
void grafoRegular(int **matriz, int tamanho)
{
    int grau = grauV(matriz, 1, tamanho);
    int comparar;
    int cont = 0;
    if (tamanho != 1)
    {
        for (int i = 1; i < tamanho; i++)
        {
            comparar = grauV(matriz, i + 1, tamanho);
            if (grau != comparar)
            {
                cont++;
            }
        }
    }
    if (cont == 0)
    {
        printf("\nO grafo é regular.\n");
    }
    else
    {
        printf("\nO grafo não é regular.\n");
    }
}
void passeio(int **matriz, int tamanho)
{
    printf("\nDigite o comprimento do passeio.\n");
    int c;
    scanf("%d", &c);
    int grauTotal = 0;
    for (int i = 1; i < tamanho + 1; i++)
    {
        grauTotal += grauV(matriz, i, tamanho);
    }
    if (grauTotal == 0)
    {
        printf("O passeio não pode ser realizado pois a matriz é nula.\n");
    }
    else if (c == grauTotal)
    {
        printf("O passeio pode ser realizado passando por todas as arestas do grafo.\n");
    }
    else if (c < grauTotal)
    {
        printf("O passeio pode ser realizado, porém não será passado por todas as arestas do grafo.\n");
    }
    else
    {
        printf("O passeio pode ser realizado passando mais de uma vez por algumas arestas.\n");
    }
}
int **removerAresta(int **matriz, int tamanho)
{
    int x, y;
    printf("\nDigite a aresta que deseja remover.\n");
    scanf("%d %d", &x, &y);
    if (x > tamanho || y > tamanho || x < 0 || y < 0)
    {
        printf("Esses vertices não existem.\n");
    }
    else
    {
        if (matriz[x - 1][y - 1] == 0)
        {
            printf("Não existe uma aresta entre esses 2 vertices.\n");
        }
        else
        {
            matriz[x - 1][y - 1]--;
            matriz[y - 1][x - 1]--;
            printf("Aresta removida com sucesso.\n");
        }
    }
    return matriz;
}
int **removerVertice(int **matriz, int tamanho)
{
    int vertice;
    printf("\nDigite o vertice que deseja remover.\n");
    scanf("%d", &vertice);
    int **matrizNova = criarMatriz(tamanho - 1, tamanho - 1);
    if (vertice > tamanho || vertice <= 0)
    {
        printf("Esse vertice não existe.\n");
        return matriz;
    }
    else
    {
        for (int i = 0; i < tamanho - 1; i++)
        {
            for (int j = 0; j < tamanho - 1; j++)
            {
                if (i < vertice - 1)
                {
                    if (j < vertice - 1)
                    {
                        matrizNova[i][j] = matriz[i][j];
                    }
                    if (j >= vertice - 1)
                    {
                        matrizNova[i][j] = matriz[i][j + 1];
                    }
                }
                else
                {
                    if (i >= vertice - 1)
                    {
                        if (j < vertice - 1)
                        {
                            matrizNova[i][j] = matriz[i + 1][j];
                        }
                        else
                        {
                            matrizNova[i][j] = matriz[i + 1][j + 1];
                        }
                    }
                }
            }
        }
    }
    return matrizNova;
}
void salvarGrafo(int **matriz, int tamanho)
{
    FILE *arq;
    arq = fopen("grafo.txt", "w");
    fprintf(arq, "%i", tamanho);
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = i; j < tamanho; j++)
        {
            if (matriz[i][j] != 0)
            {
                int arestas = matriz[i][j];
                if (i == j)
                {
                    arestas = arestas / 2;
                }
                for (int k = 0; k < arestas; k++)
                {
                    fprintf(arq, "\n%i %i", i + 1, j + 1);
                }
            }
        }
    }
    fclose(arq);
}