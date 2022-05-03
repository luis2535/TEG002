#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main()
{
    FILE *arq;
    arq = fopen("grafo.txt", "r");
    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo\n");
        return 1;
    }
    int a;
    int vertice, grau;
    fscanf(arq, "%d\n", &a);
    int **matriz;
    matriz = criarMatriz(a, a);
    int x, y;
    while (fscanf(arq, "%d %d\n", &x, &y) != EOF)
    {
        adicionaAresta(x - 1, y - 1, matriz);
    }
    fclose(arq);
    int k = -1;
    while (k != 0)
    {
        system("cls");
        printf("\nMenu:\n");
        printf("1 - Exibicao nos e arestas\n");
        printf("2 - Nos com arestas em laco\n");
        printf("3 - Arestas Duplas\n");
        printf("4 - Grau de um vértice\n");
        printf("5 - Somatório dos graus\n");
        printf("6 - Vertices isolados\n");
        printf("7 - Teorema número de arestas.\n");
        printf("8 - Vertices com grau impar é par?\n");
        printf("9 - Grafo é simples?\n");
        printf("10 - Grafo é completo?\n");
        printf("11 - Grafo é regular?\n");
        printf("12 - Passeio\n");
        printf("13 - Remoção aresta.\n");
        printf("14 - Remoção vertice.\n");
        printf("15 - Salvar grafo.\n");
        printf("0 - Sair\n");
        scanf("%d", &k);
        switch (k)
        {
        case 1:
            printf("\nNumero de nós: %d\n", a);
            imprimeMatriz(matriz, a);
            printf("\nNumero de arestas: %d\n", numeroArestas(matriz, a));
            system("pause");
            break;
        case 2:
            lacos(matriz, a);
            system("pause");
            break;
        case 3:
            arestasDuplas(matriz, a);
            system("pause");
            break;
        case 4:
            printf("\nQue vertice deseja analisar?\n");
            scanf("%d", &vertice);
            grau = grauV(matriz, vertice, a);
            if (grau == -1)
            {
                printf("\nEsse vertice nao existe\n");
            }
            else
            {
                printf("\nGrau do vertice V[%d] = %d\n", vertice, grau);
            }
            system("pause");
            break;
        case 5:
            somagrau(matriz, a);
            system("pause");
            break;
        case 6:
            isolados(matriz, a);
            system("pause");
            break;
        case 7:
            teoremaArestas(matriz, a);
            system("pause");
            break;
        case 8:
            verticesImpar(matriz, a);
            system("pause");
            break;
        case 9:
            grafoSimples(matriz, a);
            system("pause");
            break;
        case 10:
            grafoCompleto(matriz, a);
            system("pause");
            break;
        case 11:
            grafoRegular(matriz, a);
            system("pause");
            break;
        case 12:
            passeio(matriz, a);
            system("pause");
            break;
        case 13:
            matriz = removerAresta(matriz, a);
            system("pause");
            break;
        case 14:
            matriz = removerVertice(matriz, a);
            a--;
            system("pause");
            break;
        case 15:
            salvarGrafo(matriz, a);
            system("pause");
            break;
        case 0:
            printf("Finalizando\n");
            break;
        default:
            printf("Digite novamente!\n");
            break;
        }
    }

    return 0;
}
