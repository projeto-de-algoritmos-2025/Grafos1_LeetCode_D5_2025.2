#include <stdio.h>
#include <stdlib.h>

int longestCycle(int *arestas, int tamanhoArestas)
{

    int maiorCiclo = -1;

    int *visitadoEm = (int *)calloc(tamanhoArestas, sizeof(int));
    int *comprimentoCaminho = (int *)calloc(tamanhoArestas, sizeof(int));

    int iteracaoAtual = 1;

    for (int i = 0; i < tamanhoArestas; i++)
    {
        if (visitadoEm[i] == 0)
        {
            int atual = i;
            int comprimento = 0;

            while (atual != -1 && visitadoEm[atual] == 0)
            {
                visitadoEm[atual] = iteracaoAtual;
                comprimentoCaminho[atual] = comprimento;
                atual = arestas[atual];
                comprimento++;
            }

            if (atual != -1 && visitadoEm[atual] == iteracaoAtual)
            {
                int tamanhoDoCiclo = comprimento - comprimentoCaminho[atual];
                if (tamanhoDoCiclo > maiorCiclo)
                {
                    maiorCiclo = tamanhoDoCiclo;
                }
            }

            iteracaoAtual++;
        }
    }

    free(visitadoEm);
    free(comprimentoCaminho);

    return maiorCiclo;
}